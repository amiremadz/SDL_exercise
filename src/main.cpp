//============================================================================
// Name        : SDL.cpp
// Author      : Amir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <math.h>
#include "Screen.h"

using namespace std;
using namespace particles;

int main() {

	cout << SDL_GetNumVideoDisplays() << endl;

	Screen screen;

	if(!screen.init()){
		cout << "SDL initialization error." << endl;
	}

	SDL_DisplayMode dm;
	if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
	    SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
	    return 1;
	}

	//SDL_Delay(3000);

	while(true)
	{
		int elapsed = SDL_GetTicks();

		Uint8 red = static_cast<Uint8> ((1 + sin(elapsed * 0.0001)) * 128);
		Uint8 green = static_cast<Uint8> ((1 + sin(elapsed * 0.0002)) * 128);
		Uint8 blue = static_cast<Uint8> ((1 + sin(elapsed * 0.0003)) * 128);

		//Draw Particles
		for(int y=0; y<Screen::SCREEN_HEIGHT; y++){
			for(int x=0; x<Screen::SCREEN_WIDTH; x++){
				screen.setPixel(x, y, red, green, blue);
			}
		}

		//screen.setPixel(200, 150, 255, 255, 255);

		// Draw the screen
		screen.update();

		// Check for message/events
		if(!screen.processEvents()){
			break;
		}
	}

	screen.close();

	return 0;
}
