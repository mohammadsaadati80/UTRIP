#ifndef __RATING_H__
#define __RATING_H__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <iomanip>

class Rating
{
public:
	Rating(std::string username, std::vector<double> rates);
	std::string get_username();
	void update_rates(std::vector<double> rates);
	double get_rate_member(int element_number);

private:
	std::string username;
	std::vector<double> rates;

};

#endif