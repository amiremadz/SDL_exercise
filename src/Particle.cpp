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

Particle::Particle(){
	init();
}

void Particle::init(){
	mX = 0;
	mY = 0;
	mR = 0;
	mTheta = (2* M_PI*rand())/RAND_MAX;
	mRspeed = (0.05*rand()/RAND_MAX);
	mRspeed = mRspeed * mRspeed;
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

void Particle::update(int interval){
	mR += mRspeed*interval;
	mTheta += interval * 0.0005;

	mX = mR*cos(mTheta);
	mY = mR*sin(mTheta);

	bool isOnEdge = mX <= -1 || mX >= 1 || mY <= -1 || mY >= 1;

	if(isOnEdge){
		init();
	}

	if(rand() < 0.01*RAND_MAX){
		init();
	}

}




} /* namespace particles */

