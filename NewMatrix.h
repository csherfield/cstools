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


public:
	/*   Constructors   */
	NewMatrix(int rows, int cols);
	NewMatrix(std::vector<std::vector<double> > *v);


public:
	/* Destructors   */
	virtual ~NewMatrix();


public:
	 /*    Operators   */
	NewMatrix operator+(NewMatrix& m2);
	NewMatrix operator*(NewMatrix& m2);

private:
	/*    Members    */
	std::vector<std::vector<double> > *m_pmatrix;

private:
	/* Methods  */

	std::vector<double> add_vectors(const std::vector<double> v1,const std::vector<double> v2);

	void print_vector(std::vector<double> v);


public:
	void print_matrix();
};


} /* namespace cstools */

#endif /* NEWMATRIX_H_ */
