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

    std::vector<std::vector<double> > values;

    std::vector<std::vector<double*> > matrix;

    void print_vector(std::vector<double*> v);

    void create_matrix(std::vector<std::vector<double> > v);
    void create_matrix(std::vector<double> v);



public:

    // Constructors

    Matrix(std::vector<std::vector<double> > v);

    Matrix(std::vector<double> v);




    // Getters

    std::vector<double*> getRow(unsigned long index);

    std::vector<std::vector<double*> > getRows();
    std::vector<std::vector<double*> > getColumns();

    int getNumber_of_rows() const;

    int getNumber_of_columns() const;

    std::vector<double*> getColumn(unsigned long index);


    // Setters



    // Operators
    Matrix operator+(Matrix& m2);
    Matrix operator*(Matrix& m2);



    // Others

    std::vector<double> add_vectors(const std::vector<double*> v1,const std::vector<double*> v2);

    double multiply_vectors(std::vector<double*> v1, std::vector<double*> v2);

    void print_matrix();

    static Matrix identity(unsigned long n);

};

} /* namespace cstools */



#endif //STATISTICALLEARNING_MATRIX_H
