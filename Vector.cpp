/*
 * Vector.cpp
 *
 *  Created on: 17 Apr 2018
 *      Author: chrissherfield
 */

#include "Vector.h"
//TODO Remove this
#include <iostream>
//TODO Remove this and implement on sqrt
#include <math.h>

//TODO remove this
using namespace std;

namespace cstools {

int Vector::id_count = 0;

Vector::Vector() : nn(0){
	id = id_count++;
	cout << "Creating new vector empty. ID: " << id << endl;
	v = new std::vector<double>;

}

Vector::Vector(int n) : nn(n)
{
	id = id_count++;
	cout << "Creating new vector with 0s. ID: " << id << endl;
	v = new std::vector<double>(n, 0);

}

Vector::Vector(int n, const double &a) : nn(n)
{
	id = id_count++;
	cout << "Creating new vector from constant.  ID: " << id << endl;
	v = new std::vector<double>(n, a);

}

Vector::Vector(const std::vector<double> &a)
{
	id = id_count++;
	cout << "Creating new vector from STL vector.  ID: " << id << endl;
	nn = a.size();
	v = new std::vector<double>;


	for (std::vector<double>::const_iterator it = a.begin(); it != a.end(); it++)
	{
		v->push_back(*it);
	}
}

Vector::Vector(const Vector &copyV)
{
	id = id_count++;
	cout << "Creating new Vector from copy constructor.  ID: " << id << endl;
	nn = copyV.size();
	v = new std::vector<double>(nn);
	for (int i = 0; i < v->size(); i++)
	{
		(*v)[i] = copyV[i];

	}

}

Vector &Vector::operator=(const Vector &rhs)
{
	if (this != &rhs)
	{
		cout << "Entering assignment operator" << endl;

		delete v;              // destroy storage in this
		nn = 0;
		v = nullptr;             // preserve invariants in case next line throws
		v = new std::vector<double>(rhs.size()); // create storage in this
		nn = rhs.size();

		for (int i = 0; i < nn; i++)
		{
			(*v)[i] = rhs[i];
		}


	}

	return *this;

}



Vector &Vector::operator+(const Vector &rhs)
{
	// Check size of vectors
	if (this->size() != rhs.size())
	{
		throw "Vector Sizes not equal!";
	}
	Vector *vec = new Vector(this->size());
	for (int i = 0; i < this->size(); i++)
	{
		(*vec)[i] = rhs[i] + (*this)[i];
	}

	return *vec;

}

Vector &Vector::operator+(const double a)
{
	Vector *vec = new Vector(this->size());
	for (int i = 0; i < vec->size(); i++)
	{
		(*vec)[i] = (*this)[i] + a;
	}

	return *vec;

}

Vector &Vector::operator*(const double a)
{
	Vector *vec = new Vector(this->size());
		for (int i = 0; i < vec->size(); i++)
		{
			(*vec)[i] = (*this)[i] * a;
		}

		return *vec;

}

bool Vector::operator==(const Vector &rhs) const
{

	// Check sizes first
	if (rhs.size() != this->size())
	{
		return false;
	}
	bool check = true;
	for (int i = 0; i < this->size(); i++)
	{
		if (rhs[i] != (*this)[i])
		{
			check = false;
			break;
		}
	}
	return check;

}

bool Vector::operator!=(const Vector &rhs) const
{
	return !((*this) == rhs);
}

double &Vector::operator[](const int i) {
	return (*v)[i];
}

const double &Vector::operator[](const int i) const
{
	return (*v)[i];
}

Vector::~Vector() {
	cout << "Deleting vector. ID: "<< id << endl;
	delete v;
}

void Vector::resize(int newn)
{
	v->resize(newn, 0);
	nn = v->size();
}


void Vector::assign(int newn, const double &a)
{
	delete v;
	nn = newn;
	v = new std::vector<double>(newn, a);

}

double Vector::magnitude() const
{
	double sum = 0;
	for (int i = 0; i < v->size(); i++)
	{
		double val = (*v)[i];
		sum += val * val;
	}
	sum = sqrt(sum);

	return sum;
}




} /* namespace cstools */
