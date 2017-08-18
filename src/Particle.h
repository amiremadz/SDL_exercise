/*
 * Particle.h
 *
 *  Created on: Aug 18, 2017
 *      Author: aemadzadeh
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

namespace particles {

class Particle {
public:
	Particle();

private:
	double mX;
	double mY;

public:
	double getX() { return mX; };
	double getY() { return mY; }

public:
	virtual ~Particle();
};

} /* namespace particles */

#endif /* PARTICLE_H_ */
