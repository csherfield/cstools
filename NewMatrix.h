/*
 * NewMatrix.h
 *
 *  Created on: 30 Mar 2018
 *      Author: chrissherfield
 */

#ifndef NEWMATRIX_H_
#define NEWMATRIX_H_

#include <vector>

namespace cstools {

class NewMatrix {

private:
	/*    Members    */
	std::vector<std::vector<double> > *m_pmatrix;
	int nRows;
	int nCols;

public:
	/*   Constructors   */
	NewMatrix();
	NewMatrix(int rows, int cols);
	NewMatrix(int rows, int cols, const double &a);
	NewMatrix(std::vector<std::vector<double> > *v);

	// TODO Copy constructor
//	NewMatrix(const NewMatrix &rhs);

	/* Destructors   */
	virtual ~NewMatrix();

	/* Overloaded Operators */
	void operator=(const NewMatrix &m);
	NewMatrix operator+(const NewMatrix &other);
//	NewMatrix operator*(const NewMatrix &other);
//	std::vector<double>* operator[](const int row );


public:
	/* Methods  */

	void printMatrix();
	std::vector<std::vector<double> > * getElements() const { return m_pmatrix; }






	// Static methods
	static void printVector(std::vector<double> &v);
	static std::vector<double> addVectors(const std::vector<double> &v1,const std::vector<double> &v2);

//	inline T* operator[](const int i);
//	inline const T* operator[](const int i) const;
//	inline int nrows() const;
//	inline int ncols() const;
//	void resize(int newn, int newm);
//	void assign(int newn, int newm, const T &a);


};

} /* namespace cstools */

#endif /* NEWMATRIX_H_ */
