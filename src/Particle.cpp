/*
 * Particle.cpp
 *
 *  Created on: Aug 18, 2017
 *      Author: aemadzadeh
 */

#include "Particle.h"
#include <stdlib.h>
#include <iostream>

namespace particles {

Particle::Particle(): mX(0), mY(0), mR(0) {
	mTheta = (2* M_PI*rand())/RAND_MAX;
	mRspeed = (0.0005*rand()/RAND_MAX);
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update(int interval, bool bounceBack){

	mR += mRspeed*interval;

	mX = mR*cos(mTheta);
	mY = mR*sin(mTheta);

	// To avoid particles from going off the screen
	if(bounceBack){
		bool isOnEdge = mX <= -1 || mX >= 1 || mY <= -1 || mY >= 1;
		if(isOnEdge){
			mRspeed = -mRspeed;
		}
	}
}




} /* namespace particles */

