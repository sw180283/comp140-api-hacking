#pragma once

#include "resource.h"

class Weather
{
public:
	Weather();
	~Weather();

	std::string weatherList;

	void findWeather();

private:
	std::string weatherDescription;
};