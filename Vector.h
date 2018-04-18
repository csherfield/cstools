/*
 * Vector.h
 *
 *  Created on: 17 Apr 2018
 *      Author: chrissherfield
 */

#ifndef VECTOR_H_
#define VECTOR_H_

#include <vector>

namespace cstools {

class Vector {
	/*
	 * A wrapper for the STL vector, providing mathematical vector calculations
	 * For now, not using templates. Assuming use of doubles.
	 */

private:
	int nn;
	std::vector<double> *v;
	int id;
	static int id_count;

public:
	Vector();
	Vector(int n);
	Vector(int n, const double &a);
	Vector(const std::vector<double> &a);
	Vector(const Vector &v);

	const double &operator[](const int i) const;
	double &operator[](const int i);


	Vector &operator=(const Vector &rhs);
	Vector &operator+(const Vector &rhs);
	Vector &operator+(const double a);
	Vector &operator*(const double a);
	bool operator==(const Vector &rhs) const;
	bool operator!=(const Vector &rhs) const;

	virtual ~Vector();

	typedef std::vector<double>::iterator iterator;
	typedef std::vector<double>::const_iterator const_iterator;
	iterator begin() { return v->begin(); }
	iterator end() { return v->end(); }

	const_iterator begin() const {return v->begin();}
	const_iterator end() const {return v->begin();}

	void resize(int newn);

	void assign(int newn, const double &a);
//
//
	/* Methods    */

	inline int size() const { return nn;};

	double magnitue() const;


};

} /* namespace cstools */

#endif /* VECTOR_H_ */
