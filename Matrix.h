/*
Pranav Reddy
Matrix.h
Lab 11 348
Telling cpp what the Matrix obj looks like and what functions it has
*/
#ifndef MATRIX_H //header guards
#define MATRIX_H

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class Matrix {
private:
    int size; //stores NxN size
    int** data; //2D dynamic array

public:
    Matrix(); //default construct
    Matrix(int n); //constructor with size

    Matrix(const Matrix& other); //deep copy
    Matrix& operator=(const Matrix& other); //deep copy
    ~Matrix(); //free memory to fix leaking/crash problem

    void readMatrix(ifstream &file); //reads ONE NxN matrix from opened file
    void printMatrix() const; //prints matrix properly

    Matrix operator+(const Matrix& other); //operator overloading, adds two matrices
    Matrix operator*(const Matrix& other); //multiplies two matrices

    int diagonalSum() const; //sum of main plus secondary diagonal
    Matrix swapRows(int r1 = 0, int r2 = 1); //swaps rows and returns copy
    Matrix swapCols(int c1 = 0, int c2 = 1); //swaps columns and returns copy
    Matrix updateValue(int r = 0, int c = 0, int val = 100); //updates one value and returns copy
};

#endif //end of guard