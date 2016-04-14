// weatherApi.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "weatherApi.h"

//TO DO
// Get information from OpenWeather JSON
// Convert JSON into C++ code
// Allow UI to input

http://api.openweathermap.org/data/2.5/forecast/city?id=524901&APPID=82e200ef6d4a970a6d799061a11ed93c 
API key = 82e200ef6d4a970a6d799061a11ed93c

using namespace utility;
using namespace web;
using namespace web::http;
using namespace web::http::client;
using namespace concurrency::streams;

using namespace web::json;

auto fileStream = std::make_shared<ostream>();

//Using the task namespace, make a temporary holder for the stream
//Open stream to outFile
pplx::task<void> requestTask = fstream::open_ostream(U("results.html")).then([=](ostream outFile)
{
	*fileStream = outFile;

	const string clientSite = "http://api.openweathermap.org/data/2.5/forecast/city?id=";
	const string locationID = "524901";
	const string appID = "&APPID=82e200ef6d4a970a6d799061a11ed93c";

	web::http::client::http_client client(U(clientSite));

	web::uri_builder builder(U(locationID));
	builder.append_query(U(locationID), U(appID));
	return client.request(methods.GET, builder.to_string());
	
	http_response::extract_json()
})