//
// Created by jake on 08/05/15.
//

#ifndef GRAPHS_NUMERICVECTOR_H
#define GRAPHS_NUMERICVECTOR_H

#include "Vector.h"
#include <math.h>

class NumVector : public Vector<double>{
public:
    NumVector();
    explicit NumVector(const int&);
    NumVector(const NumVector&);
    NumVector operator+(NumVector&);//sum
    NumVector operator-(NumVector&);//diff
    double operator*(NumVector&);//scalar product
    NumVector operator*(double);
    NumVector operator/(double);
    static NumVector unitaryVector(NumVector&);
    static double modVect(NumVector&);
    static double radAngle(NumVector&, NumVector&);
    static double degAngle(NumVector&, NumVector&);
};
#endif //GRAPHS_NUMERICVECTOR_H

NumVector NumVector::operator+(NumVector &b) {
    if(b.length() != this->size) throw new InvalidEntryException();
    NumVector aux = NumVector(b.length());
    for (int i = 0; i < this->size; ++i) {
        aux[i] = this->arr[i] + b[i];
    }
    return aux;
}

NumVector::NumVector(const NumVector &vector) {
    this->size = vector.length();
    this->arr = new double[this->size];
    for (int i = 0; i < this->size; ++i) {
        arr[i] = vector.get(i);
    }
}
NumVector::NumVector(const int &nn) {
    this->size = nn;
    this->arr = new double[nn];
}

NumVector NumVector::operator-(NumVector &b) {
    if(b.length() != this->size) throw new InvalidEntryException();
    NumVector aux =  NumVector(b.length());
    for (int i = 0; i < this->size; ++i) {
        aux[i] = this->arr[i] - b[i];
    }
    return aux;
}

double NumVector::operator*(NumVector &vector) {
    if(vector.length() != this->size) throw new InvalidEntryException();
    double aux =  0;
    for (int i = 0; i < this->size; ++i) {
        aux += this->arr[i] * vector[i];
    }
    return aux;
}

NumVector NumVector::operator*(double d) {
    NumVector aux = NumVector(this->length());
    for (int i = 0; i < this->size; ++i) {
        aux[i] = this->arr[i] * d;
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
    NumVector aux = NumVector(this->length());
    for (int i = 0; i < this->size; ++i) {
        aux[i] = this->arr[i] / d;
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

NumVector::NumVector() {
    this->size = 0;
}

double NumVector::degAngle(NumVector &vector1, NumVector &vector2) {
    return radAngle(vector1,vector2) * 180 / 3.14159265 ;
}
