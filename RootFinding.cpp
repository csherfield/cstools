/*
 * RootFinding.cpp
 *
 *  Created on: 24 Apr 2018
 *      Author: chrissherfield
 */

#include <iostream>
#include <cmath>
#include "RootFinding.h"
#include<exception>
using namespace std;


namespace cstools {

RootFinding::RootFinding() {
	// TODO Auto-generated constructor stub

}

RootFinding::~RootFinding() {
	// TODO Auto-generated destructor stub
}



double RootFinding::bisection(double(*func)(double), double initA, double initB, double epsilon)
{
	double a = initA;
	double b = initB;
	double mp = (a+b)/2;

	double fa = func(a);
	cout << "Fa: " << fa << endl;
	double fb = func(b);
	cout << "Fb: " << fb << endl;

	// Test for positive and negative
	if (fa < 0 && fb > 0)
	{
		double mpTest = func(mp);
		while(abs(mpTest) > epsilon)
		{
			mp = (a+b)/2;
			mpTest = func(mp);
			cout << "MpTest: " << mpTest << endl;
			if (mpTest > 0)
			{
				cout << "Changing b" << endl;
				b = mp;
			}
			else
			{
				cout << "Changing a" << endl;
				a = mp;
			}

		}

	}
	return mp;
}

} /* namespace cstools */
