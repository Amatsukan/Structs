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
    T get(const int&) const;
    void set(const int&, const T&);
    T& operator[] (int);
    Vector & operator= (const Vector &);
    int length() const;
    inline bool operator==(const Vector&);
    inline bool operator!=(const Vector&);

    template <class U>
    friend std::ostream& operator<< (std::ostream&, Vector<U>&);

protected:
    T* arr;
    int size;

};

#endif //GRAPHS_ARRAY_H
template <typename T>
Vector<T>::Vector() {
    size = 0;
}

template <typename T>
Vector<T>::Vector(const int &i) {
    this->size = i;
    this->arr = new T[this->size];
}

template <typename T>
Vector<T>::Vector(const Vector &array) {
    this->size = array.length();
    this->arr = new T[size];
    for (int i = 0; i < this->size; ++i) {
        this->arr[i] = array.get(i);
    }
}

template <typename T>
T Vector<T>::get(const int &i) const {
    if(i >= this->size or i< 0) throw OutOfBoundsException();

    return arr[i];
}

template <typename T>
void Vector<T>::set(const int &i, const T &t) {
    if(i >= this->size or i< 0) throw new OutOfBoundsException();

    arr[i] = t;
}

template <class T>
T& Vector<T>::operator[] (int index) {
    if(index >= this->size or index < 0) throw new OutOfBoundsException();
    return arr[index];
}
template <typename T>
Vector<T> &Vector<T>::operator=(const Vector &array) {
    Vector<T> & aux = *(new Vector(array));
    return aux;
}
template <typename T>
Vector<T>::~Vector() {
    delete [] arr;
}
template <typename T>
bool Vector<T>::operator!=(const Vector &a) {
    bool ret = true;
    for (int i = 0; i < size; ++i) {
        if(a[i] == this->arr[i]) ret = false;
    }
    return ret;
}
template <typename T>
bool Vector<T>::operator==(const Vector &a) {
    for (int i = 0; i < size; ++i) {
        if(a[i] != this->arr[i]) return false;
    }
    return true;
}

template <typename T>
int Vector<T>::length() const{
    return this->size;
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
