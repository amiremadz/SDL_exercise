//============================================================================
// Name        : SDL.cpp
// Author      : Amir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include "Screen.h"
#include "Swarm.h"

using namespace std;
using namespace particles;

int main() {

	srand(time(NULL));

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

	Swarm swarm;

	while(true)
	{
		int elapsed = SDL_GetTicks();
		swarm.update(elapsed);

		Uint8 red = static_cast<Uint8> ((1 + sin(elapsed * 0.0001)) * 128);
		Uint8 green = static_cast<Uint8> ((1 + sin(elapsed * 0.0002)) * 128);
		Uint8 blue = static_cast<Uint8> ((1 + sin(elapsed * 0.0003)) * 128);

		const Particle * const particles = swarm.getParticles();

		//Draw Particles
		for(int i=0; i<Swarm::NPARTICLES; i++){
			Particle particle = particles[i];
			int x = static_cast<int>( (particle.getX() + 1)*Screen::SCREEN_WIDTH/2 );
			int y = static_cast<int>( (particle.getY() + 1)*Screen::SCREEN_WIDTH/2 + (Screen::SCREEN_HEIGHT - Screen::SCREEN_WIDTH)/2);

			//cout << x << " " << y << endl;

			screen.setPixel(x, y, red, green, blue);
		}

		screen.boxBlur();

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
