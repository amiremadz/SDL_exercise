/*
 * Swarm.cpp
 *
 *  Created on: Aug 18, 2017
 *      Author: aemadzadeh
 */

#include "Swarm.h"
#include <vector>
namespace particles {

Swarm::Swarm() {
	mParticles = new Particle[NPARTICLES];

}

Swarm::~Swarm() {
	delete[] mParticles;
}


void Swarm::update(){
	for(int i=0; i<NPARTICLES; i++){
			mParticles[i].update();
		}
}



} /* namespace particles */
