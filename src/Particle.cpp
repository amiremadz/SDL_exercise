/*
 * Particle.cpp
 *
 *  Created on: Aug 18, 2017
 *      Author: aemadzadeh
 */

#include "Particle.h"
#include <stdlib.h>

namespace particles {

Particle::Particle() {
	mX = (2.0*rand())/RAND_MAX - 1;
	mY = (2.0*rand())/RAND_MAX - 1;
	mXspeed = 0.001 * ((2.0*rand())/RAND_MAX - 1);
    mYspeed = 0.001 * ((2.0*rand())/RAND_MAX - 1);
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update(){
	mX += mXspeed;
	mY += mYspeed;

	// To avoid particles from going off the screen
	if(mX <= -1 || mX >= 1){
		mXspeed = -mXspeed;
	}

	if(mY <= -1 || mY >= 1){
		mYspeed = -mYspeed;
	}
}




} /* namespace particles */

