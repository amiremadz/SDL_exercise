/*
 * Screen.cpp
 *
 *  Created on: Aug 17, 2017
 *      Author: aemadzadeh
 */

#include "Screen.h"

namespace particles {

Screen::Screen():
		mWindow(NULL), mRenderer(NULL), mTexture(NULL), mBuffer(NULL) {
}

Screen::~Screen() {
	// TODO Auto-generated destructor stub
}

bool Screen::init(){

	if(SDL_Init(SDL_INIT_VIDEO) < 0 )
	{
		return false;
	}

	mWindow = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	// | SDL_WINDOW_FULLSCREEN_DESKTOP

	if(mWindow == NULL)
	{
		SDL_Quit();
		return false;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_PRESENTVSYNC);

	if(mRenderer == NULL){
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
		return false;
	}

	mTexture = SDL_CreateTexture(mRenderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if(mTexture == NULL){
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
		return false;
	}

	mBuffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];
	memset(mBuffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	return true;
}

bool Screen::processEvents(){
	SDL_Event event;
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT)
		{
			return false;
		}
	}
	return true;
}

void Screen::update(){
	SDL_UpdateTexture(mTexture, NULL, mBuffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(mRenderer);
	SDL_RenderCopy(mRenderer, mTexture, NULL, NULL);
	SDL_RenderPresent(mRenderer);

}

int Screen::makeColor(char red, char green, char blue){
	int color = red;

	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	return color;
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue){
	int color = makeColor(red, green, blue);
	int index = 0;

	if( (y<0) || (y>=SCREEN_HEIGHT) || (x<0) || (x>=SCREEN_WIDTH) ){
		return;
	}

	index = y*SCREEN_WIDTH + x;
	mBuffer[index] = color;
}

void Screen::close(){

	delete[] mBuffer;
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyTexture(mTexture);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

} /* namespace particles */
