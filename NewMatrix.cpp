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

NewMatrix::NewMatrix(int rows, int cols) {
	m_pmatrix = new vector< vector<double> >(rows, vector<double>(cols, 0));
	cout << "Creating Matrix" << endl;
}
NewMatrix::NewMatrix(std::vector<std::vector<double> > *v) {
	cout << "Creating Matrix" << endl;
	m_pmatrix = v;
}

NewMatrix::~NewMatrix() {
	cout << "Destroying Matrix" << endl;
	delete m_pmatrix;
}



NewMatrix NewMatrix::operator+(NewMatrix& m2) {

    vector< vector<double> > v;

    auto m2_iterRow = (m2.m_pmatrix)->begin();
    for (auto m1_iterRow = (this->m_pmatrix)->begin(); m1_iterRow != (this->m_pmatrix)->end(); ++m1_iterRow, ++m2_iterRow)
    {
        v.push_back(this->add_vectors(*m1_iterRow, *m2_iterRow));
    }


    NewMatrix m(&v);


    return m;

}


vector<double> NewMatrix::add_vectors(const std::vector<double> v1,const std::vector<double> v2)
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


void NewMatrix::print_matrix()
{
    for (auto iter1 = this->m_pmatrix->begin(); iter1 != this->m_pmatrix->end(); ++iter1)
    {
        this->print_vector(*iter1);
    }

}


void NewMatrix::print_vector(vector<double> v) {

	cout << "| ";
	for (auto iter = v.begin(); iter != v.end(); iter++) {

		cout << *iter << " ";
	}
	cout << "| " << endl;

}
}/* namespace cstools */
