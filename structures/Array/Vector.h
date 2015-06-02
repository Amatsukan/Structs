//
// Created by jake on 08/05/15.
//

#ifndef GRAPHS_ARRAY_H
#define GRAPHS_ARRAY_H

#include <iostream>
#include "ArrayExceptions.h"

template <typename T>
class Vector{

public:
    explicit Vector(const int&);
    Vector();
    Vector(const Vector &);
    virtual ~Vector();
    T at(const int &) const;
    void set(const int&, const T&);
    T& operator[] (int);
    Vector & operator= (const Vector &);
    int length() const;
    inline bool operator==(const Vector&);
    inline bool operator!=(const Vector&);

    template <class U>
    friend std::ostream& operator<< (std::ostream&, Vector<U>&);

protected:
    T* _arr;
    int _size;

};

#endif //GRAPHS_ARRAY_H

template <typename T>
Vector<T>::Vector() :
    _arr(0), _size(0)
{}

template <typename T>
Vector<T>::Vector(const int &i) :
    _size(i), _arr(new T[i])
{}

template <typename T>
Vector<T>::Vector(const Vector &array) :
    _size(array.length()), _arr(new T[_size])
{
    for (int i = 0; i <_size; ++i) {
        _arr[i] = array.at(i);
    }
}

template <typename T>
T Vector<T>::at(const int &i) const {
    if(i >= _size or i< 0) throw OutOfBoundsException();

    return _arr[i];
}

template <typename T>
void Vector<T>::set(const int &i, const T &t) {
    if(i >= _size or i< 0) throw new OutOfBoundsException();

    _arr[i] = t;
}

template <class T>
T& Vector<T>::operator[] (int index) {
    if(index >= _size or index < 0) throw new OutOfBoundsException();
    return _arr[index];
}

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &array) {
    Vector<T> & aux = *(new Vector(array));
    return aux;
}

template <typename T>
Vector<T>::~Vector() {
    delete [] _arr;
}

template <typename T>
bool Vector<T>::operator!=(const Vector &a) {
    return not(operator==(a));
}

template <typename T>
bool Vector<T>::operator==(const Vector &a) {
    for (int i = 0; i < _size; ++i) {
        if (a[i] != _arr[i]) return false;
    }
    return true;
}

template <typename T>
int Vector<T>::length() const{
    return _size;
}

template <class T>
std::ostream& operator<< (std::ostream& out, Vector<T>& vect) {
    out << "[ ";
    for (int i = 0; i < vect.length()-1; ++i) {
        out << vect[i] << ", ";
    }
    out << vect[vect.length()-1] << " ]";
    return out;
}
