/*
 * RootFinding.h
 *
 *  Created on: 24 Apr 2018
 *      Author: chrissherfield
 */

#ifndef ROOTFINDING_H_
#define ROOTFINDING_H_

#include <functional>

namespace cstools {

class RootFinding {
public:
	RootFinding();
	virtual ~RootFinding();

	static double bisection(double(*func)(double), double initA, double initB, double epsilon);

};

} /* namespace cstools */

#endif /* ROOTFINDING_H_ */
