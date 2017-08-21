/*
 * Particle.h
 *
 *  Created on: Aug 18, 2017
 *      Author: aemadzadeh
 */

#ifndef PARTICLE_H_
#define PARTICLE_H_

#include <math.h>

namespace particles {

class Particle {
public:
	Particle();

private:
	double mX;
	double mY;
	double mR;
	double mTheta;
	double mRspeed;

public:
	double getX() { return mX; };
	double getY() { return mY; }
	void update(int interval);

private:
	void init();

public:
	virtual ~Particle();

};

} /* namespace particles */

#endif /* PARTICLE_H_ */
