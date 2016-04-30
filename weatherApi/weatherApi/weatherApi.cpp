// weatherApi.cpp : Defines the entry point for the application.
//
#include "stdafx.h"
#include "weatherApi.h"

//TO DO
// Get information from OpenWeather JSON
// Convert JSON into C++ code
// Allow UI to input

using namespace utility;			// Common utilities like string conversions
using namespace web;				// Common features like URIs
using namespace web::http;			// Common HTTP functionality
using namespace web::http::client;		// HTTP client features
using namespace concurrency::streams;		// Asynchronous streams

//http://stackoverflow.com/questions/34960421/looping-through-a-list-of-objects

void findWeather()
{
	web::http::client::http_client client(U("http://api.openweathermap.org"));
	web::uri_builder builder(U("/data/2.5/forecast"));
	builder.append_query(U("q"), U("London,UK"));
	builder.append_query(U("appid"), U("82e200ef6d4a970a6d799061a11ed93c"));

	http_response response = client.request(methods::GET, builder.to_string()).get();
	web::json::value forecastJSON = response.extract_json(true).get();
	web::json::value forecastListJSON = forecastJSON.at(U("list"));

	for (size_t i = 0; i < forecastListJSON.size(); i++)
	{
		web::json::value forecastDayJSON = forecastListJSON[i];
		web::json::value mainJSON = forecastDayJSON.at(U("main"));
		std::string weatherDescription = "";
		if (!mainJSON.is_null())
		{
			weatherDescription = conversions::to_utf8string(mainJSON.as_string());
		}
		std::cout << "Weather is " << conversions::to_utf8string(weatherDescription) << std::endl;

		web::json::value MainJson = forecastDayJSON.at(U("main"));
	}
}