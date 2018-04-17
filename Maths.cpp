/*
 * Maths.cpp
 *
 *  Created on: 17 Apr 2018
 *      Author: chrissherfield
 */

#include "Maths.h"
#include "iostream"


namespace cstools {

Maths::Maths() {
	// TODO Auto-generated constructor stub

}

Maths::~Maths() {
	// TODO Auto-generated destructor stub
}

int Maths::fibonacci(int n)
{
	if (n < 0)
	{
		// TODO Raise an exception, create custom exception for fun
		return -1;
	}
	int fib;
	if (n==0) fib = 0;
	if (n == 1) fib = 1;
	else if (n == 2) fib = 1;
	else if (n > 2)
	{
		fib = fibonacci(n-2) + fibonacci(n-1);
	}

	return fib;

}

} /* namespace cstools */
