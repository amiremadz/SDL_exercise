/*
 * Screen.h
 *
 *  Created on: Aug 17, 2017
 *      Author: aemadzadeh
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL.h>
#include <stdio.h>

namespace particles {

class Screen {
public:
	Screen();

public:
	static const int SCREEN_WIDTH = 400;
	static const int SCREEN_HEIGHT = 300;

public:
	bool init();
	bool processEvents();
	void close();

private:
	SDL_Window *mWindow;
	SDL_Renderer *mRenderer;
	SDL_Texture *mTexture;
	Uint32 *mBuffer;

public:
	virtual ~Screen();


};



} /* namespace particles */

#endif /* SCREEN_H_ */
