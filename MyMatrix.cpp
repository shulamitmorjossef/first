//
// Created by Student on 8/16/2023.
//

#include "MyMatrix.h"
#include <iostream>
using namespace std;

MyMatrix::MyMatrix(){
    // This function is an empty constructor, initializes the matrix to 0
    mat[0][0] = 0;
    mat[0][1] = 0;
    mat[1][0] = 0;
    mat[1][1] = 0;
}

MyMatrix::MyMatrix(float num1, float num2, float num3, float num4){
    // This function is a constructor, receives 4 float numbers and initializes the matrix accordingly
    set(num1,num2,num3,num4);
}

MyMatrix::MyMatrix(const MyMatrix& matrix){
    // This function is a copy constructor
    set(matrix.mat[0][0], matrix.mat[0][1],matrix.mat[1][0],matrix.mat[1][1]);
}

MyMatrix::~MyMatrix() {
    // This is an empty destructor

}

void MyMatrix::set(float matrix[2][2]){
    // This function receives matrix and copy her values to this matrix
    mat[0][0] = matrix[0][0];
    mat[0][1] = matrix[0][1];
    mat[1][0] = matrix[1][0];
    mat[1][1] = matrix[1][1];
}

void MyMatrix::set(float num1, float num2, float num3, float num4){
    // This function receives 4 float numbers and initializes the matrix accordingly
    mat[0][0] = num1;
    mat[0][1] = num2;
    mat[1][0] = num3;
    mat[1][1] = num4;
}

void MyMatrix::print()const{
    // This function print the matrix
    cout << mat[0][0] << " " << mat[0][1] << endl
         << mat[1][0] << " " << mat[1][1] << endl ;
}

float MyMatrix::det(){
    // This function return the determinant of the matrix
    float one, two;
    one = mat[0][0]*mat[1][1];
    two = mat[0][1]*mat[1][0];
    return (one - two) ;
}

void MyMatrix::add(const MyMatrix& matrix){
    // This function receives matrix by reference and add the matrix to this matrix
    mat[0][0] = mat[0][0] + matrix.mat[0][0];
    mat[0][1] = mat[0][1] + matrix.mat[0][1];
    mat[1][0] = mat[1][0] + matrix.mat[1][0];
    mat[1][1] = mat[1][1] + matrix.mat[1][1];
}
void MyMatrix::multi(const MyMatrix& matrix){
    // This function receives matrix by reference and Multiplier the matrix in this matrix (change just this matrix)
    float first = mat[0][0]*matrix.mat[0][0] + mat[0][1]*matrix.mat[1][0];
    float sec = mat[0][0]*matrix.mat[0][1] + mat[0][1]*matrix.mat[1][1];
    float third = mat[1][0]*matrix.mat[0][0] + mat[1][1]*matrix.mat[1][0];
    float four = mat[1][0]*matrix.mat[0][1] + mat[1][1]*matrix.mat[1][1];

    set(first,sec,third,four);
}

bool MyMatrix::isEqual(const MyMatrix& matrix){
    // This function receives matrix and check if this matrix is equal to matrix
    int count = 0;
    for(int i = 0; i<2; ++i)
        for(int j = 0; j<2;++j){
            if (mat[i][j] == matrix.mat[i][j])
                ++count ;
        }
    if(count==4)
        return true;
    return false;
}