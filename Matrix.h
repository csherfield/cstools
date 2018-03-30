//
// Created by Chris Sherfield on 24/03/2018.
//
/* Things to implement:
 * Transpose
 * Equality check
 * ....
 *
 */

#ifndef STATISTICALLEARNING_MATRIX_H
#define STATISTICALLEARNING_MATRIX_H

namespace cstools {

class Matrix {

private:
    unsigned long number_of_rows;
    unsigned long number_of_columns;

    vector<vector<double> > values;

    vector<vector<double*> > matrix;

    void print_vector(vector<double*> v);

    void create_matrix(vector<vector<double> > v);
    void create_matrix(vector<double> v);



public:

    // Constructors

    Matrix(vector<vector<double> > v);

    Matrix(vector<double> v);




    // Getters

    vector<double*> getRow(unsigned long index);

    vector<vector<double*> > getRows();
    vector<vector<double*> > getColumns();

    int getNumber_of_rows() const;

    int getNumber_of_columns() const;

    vector<double*> getColumn(unsigned long index);


    // Setters



    // Operators
    Matrix operator+(Matrix& m2);
    Matrix operator*(Matrix& m2);



    // Others

    vector<double> add_vectors(const vector<double*> v1,const vector<double*> v2);

    double multiply_vectors(vector<double*> v1, vector<double*> v2);

    void print_matrix();

    static Matrix identity(unsigned long n);

};

} /* namespace cstools */



#endif //STATISTICALLEARNING_MATRIX_H
