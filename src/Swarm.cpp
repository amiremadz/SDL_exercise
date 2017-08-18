/*
 * Swarm.cpp
 *
 *  Created on: Aug 18, 2017
 *      Author: aemadzadeh
 */

#include "Swarm.h"

namespace particles {

Swarm::Swarm() {
	mParticles = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete[] mParticles;
}

} /* namespace particles */
