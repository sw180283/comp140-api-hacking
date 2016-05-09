#pragma once

#include "resource.h"

class Weather
{
public:
	Weather();
	~Weather();

	std::string weatherList;
	std::string weatherDescription;

	void findWeather();
	void displayWeather();

private:

};