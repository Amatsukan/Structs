//
// Created by jake on 09/05/15.
//

#ifndef GRAPHS_MATRIX_H
#define GRAPHS_MATRIX_H

#include "Vector.h"
#include "ArrayExceptions.h"

//TODO implement methods for not regular lines
template <typename T>
class Matrix{
public:
    explicit Matrix(const int &,const int &);
    Matrix(const int &,const Vector<int> &);
    Matrix();
    Matrix(const Matrix&);
    virtual ~Matrix();
    //const Vector getNColluns() const;
    T get(const int&, const int&) const;
    void set(const int&, const int&, const T&);
    T& operator[] (int);
    Matrix & operator= (const Matrix &);
    int length() const;//number of lines
    int length(int) const;//nume of elements in one selected line
    inline bool operator==(const Matrix&);
    inline bool operator!=(const Matrix&);
private:
    Vector<Vector<T>> matrix;
    int size_i;
    Vector<int> size_j;
    // matriz sizes [iXj]
};
#endif //GRAPHS_MATRIX_H

template <typename T>
Matrix<T>::Matrix() {
}

template <typename T>
Matrix<T>::Matrix(const Matrix &matrix) {
    size_i = matrix.length();
}

template <typename T>
int Matrix<T>::length() const {
    return size_i;
}

template <typename T>
int Matrix<T>::length(int i) const {
    if (i<0 or i>= length()) throw new OutOfBoundsException();
    return size_j[i];
}

template <typename T>
T Matrix::get(const int &i, const int &il) const {
    if (i<0 or i>= length()) throw new OutOfBoundsException();
    if (il<0 or il>= length(il)) throw new OutOfBoundsException();
    return matrix[i][il];
}

template <typename T>
Matrix<T>::Matrix(const int &i, const int &il) {
    size_i = i;
    size_j = Vector<int>(i);
    for (int j = 0; j < i; ++j) {
        size_j[j] = il;
    }
}

template <typename T>
Matrix<T>::~Matrix() {
    for (int i = 0; i < length() ; ++i) {
        for (int j = 0; j < length(i) ; ++j) {
            delete matrix[i][j];
        }
    }
    delete matrix;
}

template <typename T>
Vector<T> &Matrix<T>::operator[](int i) {
    return matrix[i];
}

template <typename T>//TODO implement for all matrix forms
Matrix<T> &Matrix<T>::operator=(const Matrix &matrix) {
    Matrix<T>  m = Matrix(matrix.length(), matrix.length(0));
    for (int i = 0; i < length() ; ++i) {
        for (int j = 0; j < length(i) ; ++j) {
            m[i][j] = matrix[i][j];
        }
    }
    return m;
}

template <typename T>
Matrix<T>::Matrix(const int &i, const Vector<int> &vector) {
    size_i = i;
    size_j = Vector<int>(i);
    for (int j = 0; j < i; ++j) {
        size_j[j] = vector[j];
    }
}

//template <typename T>
//    const Vector<int> Matrix<T>::getNColluns() const{
//    const Vector<int> &ret = size_j;
//    return ret;
//}

template <typename T>
void Matrix<T>::set(const int &i, const int &il, const T &t) {
    try{
        matrix[i][il] = t;
    }catch(OutOfBoundsException){
        __throw_exception_again;
    }
}

bool Matrix::operator==(const Matrix &matrix) {
    try {
        for (int i = 0; i < matrix.length() ; ++i) {
                if(matrix[i] != matrix[i]){
                    return false;
                }
        }
        return true;
    }catch(OutOfBoundsException){
        return false;
    }
}

bool Matrix::operator!=(const Matrix &matrix) {
    return not operator==(matrix);
}
