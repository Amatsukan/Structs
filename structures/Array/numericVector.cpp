//
// Created by jake on 10/05/15.
#include "numericVector.h"

NumVector NumVector::operator+(NumVector &b) {
    if(b.length() != _size) throw new InvalidEntryException();
    NumVector aux = NumVector(b.length());
    for (int i = 0; i < _size; ++i) {
        aux[i] = _arr[i] + b[i];
    }
    return aux;
}

NumVector::NumVector(const NumVector &vector):
       Vector<double>(vector.length())
{
    for (int i = 0; i < _size; ++i) {
        _arr[i] = vector.at(i);
    }
}
NumVector::NumVector(const int &nn) :
    Vector<double>(nn)
{}

NumVector NumVector::operator-(NumVector &b) {
    if(b.length() != _size) throw new InvalidEntryException();
    NumVector aux =  NumVector(b.length());
    for (int i = 0; i < _size; ++i) {
        aux[i] = _arr[i] - b[i];
    }
    return aux;
}

double NumVector::operator*(NumVector &vector) {
    if(vector.length() != _size) throw new InvalidEntryException();
    double aux =  0;
    for (int i = 0; i < _size; ++i) {
        aux += _arr[i] * vector[i];
    }
    return aux;
}

NumVector NumVector::operator*(double d) {
    NumVector aux = NumVector(length());
    for (int i = 0; i < _size; ++i) {
        aux[i] = _arr[i] * d;
    }
    return aux;
}

double NumVector::modVect(NumVector &vect) {
    int mod =0;
    for (int i = 0; i < vect.length(); ++i) {
        mod+= pow(vect[i],2);
    }
    return sqrt(mod);
}

NumVector NumVector::operator/(double d) {
    NumVector aux = NumVector(length());
    for (int i = 0; i < _size; ++i) {
        aux[i] = _arr[i] / d;
    }
    return aux;
}

NumVector NumVector::unitaryVector(NumVector &vect) {

    return vect/modVect(vect);
}

double NumVector::radAngle(NumVector &vector1, NumVector &vector2) {
    double cosX = (vector1*vector2)/(modVect(vector1)*modVect(vector2));
    return acos(cosX);
}

NumVector::NumVector():
        Vector(0)
{
}

double NumVector::degAngle(NumVector &vector1, NumVector &vector2) {
    return radAngle(vector1,vector2) * 180 / 3.14159265 ;
}
