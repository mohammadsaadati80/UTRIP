#include "Rating.hpp"
using namespace std;

Rating::Rating(std::string username, std::vector<double> rates)
{
	this->username = username;
	this->rates = rates;
}

string Rating::get_username() { return username; }

void Rating::update_rates(std::vector<double> rates)
{
	this->rates = rates;
}

double Rating::get_rate_member(int element_number) { return rates[element_number]; }