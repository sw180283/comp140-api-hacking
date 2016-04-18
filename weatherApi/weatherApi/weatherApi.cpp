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

using namespace utility;			// Common utilities like string conversions
using namespace web;				// Common features like URIs
using namespace web::http;			// Common HTTP functionality
using namespace web::http::client;		// HTTP client features
using namespace concurrency::streams;		// Asynchronous streams

using namespace web::json;

auto fileStream = std::make_shared<ostream>();

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
}
