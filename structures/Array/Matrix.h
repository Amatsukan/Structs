//
// Created by jake on 09/05/15.
//

#ifndef GRAPHS_MATRIX_H
#define GRAPHS_MATRIX_H

#include <iostream>

#include "Vector.h"
#include "ArrayExceptions.h"

//TODO implement methods for not regular lines
template <typename T>
class Matrix{
public:
    explicit Matrix(const int &,const int &);
//    Matrix(const int &,const Vector<int> &);
    Matrix();
    Matrix(const Matrix&);
    virtual ~Matrix();
//    const Vector getNColluns() const;
    T get(const int&, const int&) const;
    void set(const int&, const int&, const T&);
    Vector<T>& operator[] (int);
    const Matrix operator! ();
    Matrix & operator= (const Matrix &);
    int length() const;//number of lines
//    int length(int) const;//nume of elements in one selected line
    inline bool operator==(const Matrix&);
    inline bool operator!=(const Matrix&);
private:
    Vector<Vector<T>> matrix;
    int _size_i;
    int _size_j;
    // matriz sizes [iXj]
};
#endif //GRAPHS_MATRIX_H

template <typename T>
Matrix<T>::Matrix() {
}

template <typename T>
const Matrix<T> Matrix<T>::operator!(){
    Matrix<T> ret = Matrix<T>(_size_j,_size_i);
    for (int j = 0; j < _size_i; ++j) {
        for (int i = 0; i < _size_j; ++i) {
            ret[j][i] = matrix[i][j];
        }
    }
    return ret;
}

template <typename T>
Matrix<T>::Matrix(const Matrix &matrix) {
    _size_i = matrix.length();
}

template <typename T>
int Matrix<T>::length() const {
    return _size_i;
}

//template <typename T>
//int Matrix<T>::length(int i) const {
//    if (i<0 or i>= length()) throw new OutOfBoundsException();
//    return _size_j[i];
//}

template <typename T>
T Matrix<T>::get(const int &i, const int &il) const {
    if (i<0 or i>= length()) throw new OutOfBoundsException();
    if (il<0 or il>= matrix.at(i).length()) throw new OutOfBoundsException();
    return matrix[i][il];
}

template <typename T>
Matrix<T>::Matrix(const int &i, const int &il) {
    _size_i = i;
    _size_j = il;
}

template <typename T>
Matrix<T>::~Matrix() {
}

template <typename T>
Vector<T> &Matrix<T>::operator[](int i) {
    return matrix[i];
}

template <typename T>//TODO implement for all matrix forms
Matrix<T> &Matrix<T>::operator=(const Matrix &matrix) {
    Matrix<T>  m = Matrix(matrix.length(), matrix[0].length());
    for (int i = 0; i < length() ; ++i) {
        for (int j = 0; j < m[0].length() ; ++j) {
            m[i][j] = matrix[i][j];
        }
    }
    return m;
}

//template <typename T>
//Matrix<T>::Matrix(const int &i, const Vector<int> &vector) {
//    _size_i = i;
//    size_j = Vector<int>(i);
//    for (int j = 0; j < i; ++j) {
//        size_j[j] = vector[j];
//    }
//}

template <typename T>
void Matrix<T>::set(const int &i, const int &il, const T &t) {
    try{
        matrix[i][il] = t;
    }catch(OutOfBoundsException){
        throw new OutOfBoundsException;
    }
}

template <typename T>
bool Matrix<T>::operator==(const Matrix &matrix) {
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

template <typename T>
bool Matrix<T>::operator!=(const Matrix &matrix) {
    return not operator==(matrix);
}

template <class T>
std::ostream& operator<< (std::ostream& out, Matrix<T>& matrix) {
    for (int i = 0; i < matrix.length()-1; ++i) {
        out << matrix[i] << std::endl;
    }
    out << matrix[matrix.length()-1];
    return out;
}