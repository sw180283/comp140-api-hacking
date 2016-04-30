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

/*
//https://msdn.microsoft.com/en-us/library/jj950082.aspx

using namespace web;
using namespace web::http;
using namespace web::http::client;

//Retrives a JSON value from an HTTP request
pplx::task<void> RequestJSONValueAsync()
{
	http_client client(L"http://api.openweathermap.org/data/2.5/forecast?q=London,UK&APPID=82e200ef6d4a970a6d799061a11ed93c");
	//Build request start URI
	//uri_builder builder(L"/data/2.5/forecast");
	//builder.append_query(L"q", L"London,UK");
	//builder.append_query(L"appid", L"82e200ef6d4a970a6d799061a11ed93c");
	return client.request(methods::GET).then([](http_response response) -> pplx::task<json::value>
	{
		if (response.status_code() == status_codes::OK)
		{
			return response.extract_json();
		}
		return pplx::task_from_result(json::value());
	})
		.then([](pplx::task<json::value> previousTask)
	{	
		try
		{
			const json::value& v = previousTask.get();
		}
		catch (const http_exception& e)
		{
			std::wostringstream ss;
			ss << e.what() << std::endl;
			std::wcout << ss.str();
		}
	});
}*/

/*
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>

using namespace web::json;
/*
int main(int argc, char* argv[])
{
	auto fileStream = std::make_shared<ostream>();

	//Open stream to output file
	pplx::task<void> requestTask = fstream::open_ostream(U("results.html")).then([=](ostream outFile)
	{
		*fileStream = outFile;

		//Create http_client send request
		http_client client(U("http://api.openweathermap.org/"));

		//Build request start URI
		uri_builder builder(U("/data/2.5/forecast"));
		builder.append_query(U("q"), U("London,UK"));
		builder.append_query(U("appid"), U("82e200ef6d4a970a6d799061a11ed93c"));
		return client.request(method::GET, builder.to_string());
	}
})*/

/*
//Using the task namespace, make a temporary holder for the stream
//Open stream to outFile
pplx::task<void> requestTask = fstream::open_ostream(U("results.html")).then([=](ostream outFile)
{
	*fileStream = outFile;

	//List of string addresses
	const string clientSite = U("http://api.openweathermap.org/data/2.5/forecast/city?id=");
	const string locationID = U("524901");
	const string appID = U("&APPID=82e200ef6d4a970a6d799061a11ed93c");

	//The base client website
	web::http::client::http_client client(clientSite);

	//Build the fully address
	web::uri_builder builder(locationID);
	builder.append_query((locationID), (appID));
	return client.request(methods.GET, builder.to_string());
	
	//http_response::extract_json()
})

    // Handle response headers arriving.
    .then([=](http_response response)
    {
        printf("Received response status code:%u\n", response.status_code());

        // Write response body into the file.
        return response.body().read_to_end(fileStream->streambuf());
    })

    // Close the file stream.
    .then([=](size_t)
    {
        return fileStream->close();
    });

    // Wait for all the outstanding I/O to complete and handle any exceptions
    try
    {
        requestTask.wait();
    }
    catch (const std::exception &e)
    {
        printf("Error exception:%s\n", e.what());
    }

    return 0;
}*/



//http://stackoverflow.com/questions/34960421/looping-through-a-list-of-objects

void findWeather()
{
	web::http::client::http_client client(U("http://api.openweathermap.org"));
	web::uri_builder builder(U("/data/2.5/forecast"));
	web::uri_builder builder.append_query(U("q"), U("London,UK"));
	web::uri_builder builder.append_query(U("appid"), U("82e200ef6d4a970a6d799061a11ed93c"));

	http_response response = client.request(methods::GET, builder.to_string()).get();
	web::json::value forecastJSON = response.extract_json(true).get();
	web::json::value forecastJSON = forecastJSON.at(U("list"));

	for (size_t i = 0; i < forecastListJSON.size(); i++)
	{
		web::json::value forecastDayJson = forecastListJSON[i];
		web::json::value mainJSON = forecastDayJSON.at(U("main"));
		string weatherDescription = "";
		if (!mainJSON.is_null())
		{
			weatherDescription = conversion::to_utf8strin(mainJSON.as_string());
		}
		std::cout << "Weather is " << conversion::to_utf8strin(weatherDescription) << std::endl;

		web::json::value MainJson = forecastDayJson.at(U("main"));
	}
