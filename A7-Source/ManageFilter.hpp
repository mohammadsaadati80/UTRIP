#ifndef __MANAGE_FILTER_H__
#define __MANAGE_FILTER_H__

#include "MainFilter.hpp"
#include "CityFilter.hpp"
#include "PriceFilter.hpp"
#include "StarFilter.hpp"
#include "ReserveFilter.hpp"

#define CITYFILTER 0
#define STARFILTER 1
#define PRICEFILTER 2
#define RESERVEFILTER 3
#define VALID_PRICE 0
#define FIRST_VALID_MIN_STAR 1  
#define LAST_VALID_MIN_STAR 5
#define FIRST_VALID_MAX_STAR 1  
#define LAST_VALID_MAX_STAR 5
#define FIRST_VALID_RESERVE 1
#define LAST_VALID_RESERVE 30

class ManageFilter
{
public:
	void add_all_hotels(std::vector<Hotel> &hotel_info);
	void sort_hotels_base_on_id(std::vector<Hotel*> &all_hotel_info);
	void hotel_swap(std::vector<Hotel*> &all_hotel_info, int current_hotel, int swap_element);
	void add_new_city_filter(std::string city);
	void add_new_star_filter(int min_star, int max_star);
	void add_new_price_filter(double min_price, double max_price);
	void add_new_reserve_filter(std::string room_type, int quantity, int check_in, int check_out);
	void delete_all_filters();
	void show_hotels_info();
	void show_summary_of_hotels_info(std::vector<Hotel*> filtered_hotel_info);

private:
	std::vector<Hotel*> all_hotel_info;
	std::vector<Hotel*> filtered_hotel_info;
	std::vector<MainFilter*> filters;
	CityFilter* city_filter;
	StarFilter* star_filter;
	PriceFilter* price_filter;
	ReserveFilter* reserve_filter;

};

#endif 