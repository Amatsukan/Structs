//
// Created by jake on 09/05/15.
//

#ifndef GRAPHS_MATRIX_H
#define GRAPHS_MATRIX_H

#include "Vector.h"

template <typename T>
class Matrix{
public:
    explicit Matrix(const int &);
    Matrix();
    Matrix(const Vector &);
    virtual ~Vector();
    T get(const int&) const;
    void set(const int&, const T&);
    T& operator[] (int);
    Vector & operator= (const Vector &);
    int length() const;
    inline bool operator==(const Vector&);
    inline bool operator!=(const Vector&);
private:
    Vector<Matrix<T>> matrix;
    int size_i;
    int size_j;
    // matriz sizes [iXj]
};
#endif //GRAPHS_MATRIX_H

