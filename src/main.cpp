//============================================================================
// Name        : SDL.cpp
// Author      : Amir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
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
		if(!screen.processEvents()){
			break;
		}
	}

	screen.close();

	return 0;
}
