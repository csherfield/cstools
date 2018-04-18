/*
 * NewMatrix.cpp
 *
 *  Created on: 30 Mar 2018
 *      Author: chrissherfield
 */
#include <iostream>
#include "NewMatrix.h"
using namespace std;

namespace cstools {

NewMatrix::NewMatrix() : m_pmatrix(new std::vector<std::vector<double> >()), nRows(0), nCols(0) {
	cout << "Creating Matrix with empty constructor" << endl;
}

NewMatrix::NewMatrix(int rows, int cols) : nRows(rows), nCols(cols) {
	m_pmatrix = new vector< vector<double> >(rows, vector<double>(cols, 0));
	cout << "Creating Matrix using rows and cols, assigning every element to 0" << endl;
}
NewMatrix::NewMatrix(int rows, int cols, const double &a) : nRows(rows), nCols(cols)
{
	m_pmatrix = new vector< vector<double> >(rows, vector<double>(cols, a));
}

NewMatrix::NewMatrix(std::vector<std::vector<double> > *v) {
	cout << "Creating Matrix using vector address" << endl;
	nRows = v->size();
	if (nRows > 0)
	{
		nCols = (*v)[0].size();
	}
	m_pmatrix = v;
}







NewMatrix::~NewMatrix() {
	cout << "Destroying Matrix" << endl;
}

void NewMatrix::operator=(const NewMatrix &m)
{
		m_pmatrix = m.m_pmatrix;
}

NewMatrix NewMatrix::operator+(const NewMatrix &other) {

    vector< vector<double> > *v = new vector< vector<double> >(nRows, vector<double>(nCols, 0));

    auto m2_iterRow = (other.getElements())->begin();
    for (auto m1_iterRow = (this->getElements())->begin(); m1_iterRow != (this->getElements())->end(); ++m1_iterRow, ++m2_iterRow)
    {
        v->push_back(this->addVectors(*m1_iterRow, *m2_iterRow));
    }


    NewMatrix m(v);


    return m;

}
//
//std::vector<double>* NewMatrix::operator[](const int row){
//		if (row >= 0 && row < nRows)
//		{
//			return m_pmatrix[row];
//		}
//		else
//		{
//			throw "row not available";
//		}
//}


vector<double> NewMatrix::addVectors(const std::vector<double> &v1,const std::vector<double> &v2)
{
	vector<double> v;
	auto iter2 = v2.begin();
	for (auto iter1 = v1.begin(); iter1 != v1.end(); ++iter1, ++iter2)
	{
		double addition = *iter1 + *iter2;
		v.push_back(addition);
	}

	return v;

}


void NewMatrix::printMatrix()
{
    for (auto iter1 = this->m_pmatrix->begin(); iter1 != this->m_pmatrix->end(); ++iter1)
    {
        this->printVector(*iter1);
    }

}


void NewMatrix::printVector(vector<double> &v) {

	cout << "| ";
	for (auto iter = v.begin(); iter != v.end(); iter++) {

		cout << *iter << " ";
	}
	cout << "| " << endl;

}
}/* namespace cstools */
