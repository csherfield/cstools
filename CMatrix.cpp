/*
 * CMatrix.cpp
 *
 *  Created on: 18 Apr 2018
 *      Author: chrissherfield
 */

#include "CMatrix.h"

using namespace std;

namespace cstools {

CMatrix::CMatrix() : nn(0), mm(0)  {
	p_matrix = new vector<Vector>;

}

CMatrix::CMatrix(int n, int m):  nn(n), mm(m)
{
	p_matrix = new vector<Vector>(n, Vector(m,0));

}

CMatrix::CMatrix(int n, int m, const double &a) : nn(n), mm(m) {
	p_matrix = new vector<Vector>(n, Vector(m,a));
}

CMatrix::CMatrix(int n, int m, const vector<double> &a) :  nn(n), mm(m)
{
	if (n*m != a.size())
	{
		throw "Wrong dimensions";
	}
	p_matrix = new vector<Vector>(n, Vector(m,0));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			(*p_matrix)[i][j] = a[i+j];
		}
	}

}

CMatrix::CMatrix(int n, int m, const std::vector<Vector> &a) : nn(n), mm(m)
{
	if (a.size() != n)
	{
		throw "Wrong number of rows";
	}
	p_matrix = new vector<Vector>(n, Vector(m,0));
	for (int i = 0; i < n; i++)
	{
		if (a[i].size() == m)
		{
			(*p_matrix)[i] = a[i];
		}
		else
		{
			throw "Row wrong size";
		}
	}
}

CMatrix::CMatrix(const CMatrix &rhs)
{
	*this = rhs;
}

CMatrix & CMatrix::operator=(const CMatrix &rhs)
{
	if (this != &rhs)
	{
		delete p_matrix;
		nn = rhs.nRows();
		mm = rhs.nCols();
		p_matrix = new vector<Vector>();

		for (auto it = rhs.begin(); it != rhs.begin(); it++)
			{
				p_matrix->push_back(Vector(*it));
			}
	}

	return *this;


}

CMatrix &CMatrix::operator+(const CMatrix &rhs)
{

	if (this->nRows() == rhs.nRows() && this->nCols() == rhs.nCols())
	{
		CMatrix *matrix = new CMatrix(this->nRows(), this->nCols());
		for (int i = 0; i < this->nRows(); i++)
		{
			(*matrix)[i] = (*this)[i] + rhs[i];
		}
		return *matrix;
	}
	else
	{
		throw "Rows and columns don't match";
	}

}

bool CMatrix::operator==(const CMatrix &rhs)
{
	bool eq = true;
	if (CMatrix::sizeCheck(*this, rhs))
	{
		auto rhsIt = rhs.begin();
		for (auto it = this->begin(); it != this->end(); it++, rhsIt++)
		{
			if (*it != *rhsIt)
			{
				eq = false;
				break;
			}
		}
	}
	else
	{
		eq = false;
	}
	return eq;

}



CMatrix::~CMatrix() {
	delete p_matrix;
}
//
int CMatrix::nRows() const {
	return p_matrix->size();
}
int CMatrix::nCols() const
{
	if (p_matrix->size()>0) return (*p_matrix)[0].size();
	else return 0;
}

bool CMatrix::sizeCheck(const CMatrix &m1, const CMatrix &m2)
{
	return m1.nRows() == m2.nRows() && m1.nCols() == m2.nCols();
}


} /* namespace cstools */
