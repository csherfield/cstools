/*
 * CMatrix.h
 *
 *  Created on: 18 Apr 2018
 *      Author: chrissherfield
 */

#ifndef CMATRIX_H_
#define CMATRIX_H_

#include <vector>

#include "Vector.h"

using namespace cstools;

namespace cstools {

class CMatrix {
	/*
	 * To take over the matrix and newmatrix classes
	 */
private:
	int nn;
	int mm;
	std::vector<Vector> *p_matrix;

public:
	CMatrix();
	~CMatrix();
	CMatrix(int n, int m);
	CMatrix(int n, int m, const double &a);
	CMatrix(int n, int m, const std::vector<double> &a);
	CMatrix(int n, int m, const std::vector<Vector> &a);

	CMatrix(const CMatrix &rhs);
	CMatrix & operator=(const CMatrix &rhs);
	inline Vector operator[](const int i) {return (*p_matrix)[i]; };
	inline const Vector operator[](const int i) const {return (*p_matrix)[i]; };
	CMatrix &operator+(const CMatrix &rhs);
	bool operator==(const CMatrix &rhs);

//	    void resize(int newn, int newm);
//	    void assign(int newn, int newm, const T &a); ~NRmatrix();


	typedef std::vector<Vector>::iterator iterator;
	typedef std::vector<Vector>::const_iterator const_iterator;

	iterator begin() { return p_matrix->begin(); }
	const_iterator begin() const { return p_matrix->begin(); }

	iterator end() { return p_matrix->end(); }
	const_iterator end() const { return p_matrix->end(); }

	inline int nRows() const;
	inline int nCols() const;


private:
	static bool sizeCheck(const CMatrix &m1, const CMatrix &m2);
};

} /* namespace cstools */

#endif /* CMATRIX_H_ */
