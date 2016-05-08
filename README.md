# API Hacking
This is the base repository for the COMP140 API Hacking assignment.

NB: this repository currently does not contain a `.gitignore` file. I recommend you use https://www.gitignore.io to generate an appropriate `.gitignore` file for your choice of implementation language and development environment.

##Running
This project requires C++ REST SDK (casablanca) to run. To find out how to install go to: https://github.com/Microsoft/cpprestsdk
I used ManageNuGet packages in the solution explorer to manage this package.

##WindowApplication
The weatherApiConsoleApplication is an executable that requests the location of the user, then gets the current weather from that location and prints a description of the current weather.

##SoftFox
SoftFox is my comp150 game that I wanted to integrate my API into. The files editted are:  
- SoftFox.cpp (mostly changeWeather())
- SoftFox.h
- Weather.cpp
- Weather.h
The API gets the weather for Falmouth and returns the current weather with a icon provided by openweathermap.org.

##Tutorials
http://stackoverflow.com/questions/34960421/looping-through-a-list-of-objects
http://www.lazyfoo.net/tutorials/SDL/32_text_input_and_clipboard_handling/index.php

## Proposal
##Game
I am going to be implementing this componenet for our Comp150 game.

##Component
The component I want to include into this game would be to use weather databases to affect the weather and colour hue of the game. If the area is cloudy then the colours look grey, if there is rain then rain particles appear on the screen, etc.

##Language
For this I'll be using C++ for the colour and weather change and JSON API as this is required to use the API. To use this API with C++, I'll be using C++ REST SDK (casablanca) to allow for the information to be taken from the http request and JSON.
https://github.com/Microsoft/cpprestsdk 
https://social.msdn.microsoft.com/Forums/vstudio/en-US/df7e4b67-e6ed-42c8-85f4-25424276ad70/c-rest-sdk-work-with-json-data?forum=vcgeneral

##Reason for Choosing Language
I chose to use casablanca for this project as it has been used for other applications, including weather apps that directly recieve information from openweathermap, and so have proven to work effectively. There was also an extensive tutorial to guide installation and give basic JSON usage using the casablanca library. 

I chose to use JSON instead of the XML option, as I found the code more readable and in an easily read form for casablanca.

##API
The API I'll be using is Open Weather Map which provides free weather data and forecast API suitable for any cartographic services like web and smartphones applications.

##Functionality
I think this would improve the game as it would make for more immersion into the world, and allow our target audience to experience different weather conditions around the world.
