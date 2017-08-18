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
}

Particle::~Particle() {
	// TODO Auto-generated destructor stub
}

} /* namespace particles */
