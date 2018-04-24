/*
 * Complex.h
 *
 *  Created on: 11 Apr 2018
 *      Author: chrissherfield
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <memory>
#include <iostream>


namespace cstools {

template<class T>
class Complex {
private:
	T real;
	T imag;
public:
	Complex(T real, T imag) : real(real), imag(imag) {std::cout << "Creating complex number" << std::endl;}

	Complex(Complex &rhs)
	{
		*this = rhs;
	}

	virtual ~Complex() { std::cout << "Destroying" << std::endl;};

	Complex &operator+(Complex &rhs)
	{
		std::unique_ptr<Complex<T> > pc = std::unique_ptr<Complex<T> >(new Complex<T>(this->real + rhs.real, this->imag + rhs.imag));
		return *pc;
	}

	Complex &operator=(Complex &rhs)
		{
			std::unique_ptr<Complex<T> > pc = std::unique_ptr<Complex<T> >(new Complex<T>(this->real + rhs.real, this->imag + rhs.imag));
			return *pc;
		}

	bool operator==(Complex &rhs)
	{
		return real == rhs.Real() && imag == rhs.Imag();
	}

	T Real() { return real; }
	T Imag() { return imag; }

};


} /* namespace cstools */

#endif /* COMPLEX_H_ */
