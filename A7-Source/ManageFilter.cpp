#include "ManageFilter.hpp"
using namespace std;

void ManageFilter::add_all_hotels(vector<Hotel> &hotel_info)
{
	for (int current = 0; current < hotel_info.size(); current++)
		all_hotel_info.push_back(&hotel_info[current]);
	sort_hotels_base_on_id(all_hotel_info);
	city_filter = new CityFilter;
	star_filter = new StarFilter;
	price_filter = new PriceFilter;
	reserve_filter = new ReserveFilter;
	filters.push_back(city_filter);
	filters.push_back(star_filter);
	filters.push_back(price_filter);
	filters.push_back(reserve_filter);
}

void ManageFilter::sort_hotels_base_on_id(vector<Hotel*> &all_hotel_info)
{
	for (int current_hotel = 0; current_hotel < all_hotel_info.size(); current_hotel++)
	{
		string current_takable_course_name_for_compare = all_hotel_info[current_hotel]->get_hotel_unique_id();
		int swap_element = current_hotel;
		for (int current_hotel_for_compare = current_hotel + 1; current_hotel_for_compare < all_hotel_info.size(); current_hotel_for_compare++)
			if (current_takable_course_name_for_compare > all_hotel_info[current_hotel_for_compare]->get_hotel_unique_id())
			{
				current_takable_course_name_for_compare = all_hotel_info[current_hotel_for_compare]->get_hotel_unique_id();
				swap_element = current_hotel_for_compare;
			}
		hotel_swap(all_hotel_info, current_hotel, swap_element);
	}
}

void ManageFilter::hotel_swap(vector<Hotel*> &all_hotel_info, int current_hotel, int swap_element)
{
	Hotel* swap = all_hotel_info[current_hotel];
	all_hotel_info[current_hotel] = all_hotel_info[swap_element];
	all_hotel_info[swap_element] = swap;
}

void ManageFilter::add_new_city_filter(string city)
{
	city_filter->add_new_city_filter(city);
	filters[CITYFILTER] = city_filter;
}

void ManageFilter::add_new_star_filter(int min_star, int max_star)
{
	if (min_star > LAST_VALID_MIN_STAR || min_star < FIRST_VALID_MIN_STAR || max_star > LAST_VALID_MAX_STAR || max_star < FIRST_VALID_MAX_STAR || max_star < min_star)
		throw BadRequestException();
	star_filter->add_new_star_filter(min_star, max_star);
	filters[STARFILTER] = star_filter;
}

void ManageFilter::add_new_price_filter(double min_price, double max_price)
{
	if (min_price < VALID_PRICE || max_price < VALID_PRICE || max_price < min_price)
		throw BadRequestException();
	price_filter->add_new_price_filter(min_price, max_price);
	filters[PRICEFILTER] = price_filter;
}

void ManageFilter::add_new_reserve_filter(string room_type, int quantity, int check_in, int check_out)
{
	if(check_in > check_out)
		throw BadRequestException();
	reserve_filter->add_new_reserve_filter(room_type, quantity, check_in, check_out);
	filters[RESERVEFILTER] = reserve_filter;
}

void ManageFilter::delete_all_filters()
{
	filtered_hotel_info = all_hotel_info;
	for (int current = 0;current < filters.size();current++)
		filters[current]->deactive_fliter();
}

void ManageFilter::show_hotels_info()
{
	filtered_hotel_info = all_hotel_info;
	for (int current = 0;current < filters.size();current++)
		if (filters[current]->get_filter_status() == true)
			filtered_hotel_info = filters[current]->apply_filter(filtered_hotel_info);
	show_summary_of_hotels_info(filtered_hotel_info);
}

void ManageFilter::show_summary_of_hotels_info(vector<Hotel*> filtered_hotel_info)
{
	if (filtered_hotel_info.size() == 0)
		throw EmptyException();
	for (int current = 0; current < filtered_hotel_info.size();current++)
		filtered_hotel_info[current]->show_summary_of_hotel_info();
}