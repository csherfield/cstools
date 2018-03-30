//
// Created by Chris Sherfield on 23/03/2018.
//
#include <vector>
#include <iostream>

using namespace std;

#include "Matrix.h"


namespace cstools {

Matrix::Matrix(vector<double> v) { // @suppress("Class members should be properly initialized")
    this->create_matrix(v);

}

Matrix::Matrix(vector<vector<double> > v) // @suppress("Class members should be properly initialized")
{
    this->create_matrix(v);
}

void Matrix::create_matrix(vector<double> v)
{
    vector<vector<double> > temp;
    temp.push_back(v);
    this->create_matrix(temp);
}

void Matrix::create_matrix(vector<vector<double> > v)
{
    vector<vector<double*> > pv;
    // First check the dimensions
    this->number_of_rows = v.size();
    unsigned long test_number_of_columns = v[0].size();
    for (auto iter = v.begin(); iter != v.end(); ++iter) {
        if (iter->size() != test_number_of_columns) {
            throw logic_error("Number of columns in each row is not equal");
        }


    }
    this->values = v;

    for (auto iter = this->values.begin(); iter != this->values.end(); ++iter) {
        if (iter->size() != test_number_of_columns) {
            throw logic_error("Number of columns in each row is not equal");
        }

        vector<double *> temp_pv;
        for (auto iter2 = iter->begin(); iter2 != iter->end(); iter2++) {
            temp_pv.push_back(&(*iter2));
        }
        pv.push_back(temp_pv);

        this->number_of_columns = test_number_of_columns;

        this->matrix = pv;
    }
}



Matrix Matrix::operator+(Matrix& m2) {

    auto rows1 = this->getRows();
    vector<vector<double> > v;

    auto rows2 = m2.getRows();
    auto iter2 = rows2.begin();
    for (auto iter1 = rows1.begin(); iter1 != rows1.end(); ++iter1, ++iter2)
    {
        v.push_back(this->add_vectors(*iter1, *iter2));
    }


    Matrix m(v);


    return m;

}

Matrix Matrix::operator*(Matrix& m2)
{

    if (this->number_of_columns != m2.number_of_rows)
    {
        throw logic_error("Matrix 1 number of columns not equal to Matrix 2 number of rows");
    }
    vector<vector<double> > v;
    for (unsigned long i = 0; i < this->number_of_rows; ++i)
    {
        vector<double> row;
        for (unsigned long j = 0; j < m2.number_of_columns; ++j)
        {
            try {
                double temp = this->multiply_vectors(this->getRow(i), m2.getColumn(j));
                row.push_back(temp);
            } catch (logic_error e)
            {
                cout << e.what();
            }

        }
        v.push_back(row);
    }
    return Matrix(v);

}



vector<double> Matrix::add_vectors(const vector<double*> v1, const vector<double*> v2)
{
    vector<double> v;
    auto iter2 = v2.begin();
    for (auto iter1 = v1.begin(); iter1 != v1.end(); ++iter1, ++iter2)
    {
        double addition = *(*iter1) + *(*iter2);
        v.push_back(addition);
    }

    return v;

}


vector<double*> Matrix::getRow(unsigned long index)
{
    vector<double*> v;
    for (auto  iter = this->values[index].begin(); iter != this->values[index].end(); ++iter)
    {
        v.push_back(&(*iter));

    }
    return v;


}

vector<double*> Matrix::getColumn(unsigned long index)
{
    vector<double*> v;
    for (auto iter = this->matrix.begin(); iter != this->matrix.end(); ++iter)
    {
        auto iter2 = iter->begin();
        advance(iter2, index);
        v.push_back(*iter2);
    }

    return v;
}



vector<vector<double*> > Matrix::getRows()
{
    return this->matrix;
}



int Matrix::getNumber_of_rows() const {
    return number_of_rows;
}

int Matrix::getNumber_of_columns() const {
    return number_of_columns;
}


void Matrix::print_matrix()
{

    for (auto iter1 = this->matrix.begin(); iter1 != this->matrix.end(); ++iter1)
    {
        this->print_vector(*iter1);
    }

}


void Matrix::print_vector(vector<double*> v)
{
    cout << "| ";
    for (auto iter = v.begin(); iter != v.end(); ++iter)
    {
        cout << *(*iter) << " ";
    }
    cout << "|" << endl;

}

double Matrix::multiply_vectors(vector<double*> v1, vector<double*> v2)
{
    if (v1.size() != v2.size())
    {
        throw logic_error("Vectors are not equal in length");
    }
    double sum = 0;
    auto iter2 = v2.begin();
    for (auto iter1 = v1.begin(); iter1 != v1.end(); ++iter1,  ++iter2 )
    {
        double temp = *(*iter1) * *(*iter2);
        sum += temp;

    }

    return sum;

}

Matrix Matrix::identity(unsigned long n)
{
    vector<vector<double> > v;
    for (unsigned long i = 0; i < n; ++i)
    {
        vector<double> row;
        for (unsigned long j = 0; j < n; ++j) {
            if (j == i) {
                row.push_back(1);
            } else {
                row.push_back(0);
            }
        }
        v.push_back(row);
    }

    return Matrix::Matrix(v);
}

} /* namespace cstools */



