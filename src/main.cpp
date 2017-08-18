//============================================================================
// Name        : SDL.cpp
// Author      : Amir
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <SDL.h>
#include <stdio.h>
using namespace std;

int main() {

	const int SCREEN_WIDTH = 400;
	const int SCREEN_HEIGHT = 300;

	if(SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		cout << "fail" << endl;
		return 1;
	}

	/*
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3); //Useless?
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	*/

	cout << SDL_GetNumVideoDisplays() << endl;

	SDL_DisplayMode dm;
	if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
	    SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
	    return 1;
	}

	SDL_Window *window = NULL;

	window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

	// | SDL_WINDOW_FULLSCREEN_DESKTOP

	if(window == NULL)
	{
		printf("Failed to create windowL %s\n.", SDL_GetError());
		SDL_Quit();
		return 2;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture *texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if(renderer == NULL)
	{
		cout << "Could not create renderer" << endl;
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	if(texture == NULL)
	{
		cout << "Could not create texture" << endl;
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 4;
	}

	Uint32 *buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
	memset(buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	for(int i=0; i<SCREEN_WIDTH*SCREEN_HEIGHT/4; i++)
	{
		buffer[i] = 0x00FF8000;
	}

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH*sizeof(Uint32));

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	bool quit = false;
	SDL_Event event;

	//SDL_Delay(3000);

	while(!quit)
	{
		while(SDL_PollEvent(&event))
		{
			if(event.type == SDL_QUIT)
			{
				quit = true;
			}
		}
	}

	delete[] buffer;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_DestroyWindow(window);
	SDL_Quit();


	return 0;
}
