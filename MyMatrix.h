//
// Created by Student on 8/16/2023.
//

#ifndef PART3_MYMATRIX_H
#define PART3_MYMATRIX_H


class MyMatrix {
public:
    MyMatrix();
    MyMatrix(float, float, float, float);   // const&
    MyMatrix(const MyMatrix& mat);
    ~MyMatrix();
    void set(float[2][2]);
    void set(float, float, float, float);      // Statement on the functions of the "MyMatrix" department
    void print() const;
    float det();
    void add(const MyMatrix&);
    void multi(const MyMatrix&);
    bool isEqual(const MyMatrix&);
private:
    float mat[2][2];                            // Statement on the member of the "MyMatrix" department
};


#endif //PART3_MYMATRIX_H
