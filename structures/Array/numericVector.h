//
// Created by jake on 08/05/15.
//

#ifndef GRAPHS_NUMERICVECTOR_H
#define GRAPHS_NUMERICVECTOR_H

#include "Vector.h"
#include <math.h>

class NumVector : public Vector<double>{
public:
    //NumVector(NumVector&);
    NumVector(int);
    NumVector operator+(NumVector&);//sum
    NumVector operator-(NumVector&);//diff
    double operator*(NumVector&);//scalar product
    NumVector operator*(double);
    NumVector operator/(double);
    static NumVector unitaryVector(NumVector&);
    static double modVect(NumVector&);
    static double angle(NumVector&, NumVector&);
};
#endif //GRAPHS_NUMERICVECTOR_H

NumVector NumVector::operator+(NumVector &b) {
    if(b.length() != this->size) throw new InvalidEntryException();
    NumVector aux = *(new NumVector(b.length()));
    for (int i = 0; i < this->size; ++i) {
        aux[i] = this->arr[i] + b[i];
    }
    return aux;
}

//NumVector::NumVector(NumVector &vector) {
//    this->size = vector.length();
//    for (int i = 0; i < this->size; ++i) {
//        arr[i] = vector[i];
//    }
//}
NumVector::NumVector(int nn) {
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

double NumVector::angle(NumVector &vector1, NumVector &vector2) {
    double cosX = (vector1*vector2)/(modVect(vector1)*modVect(vector2));
    return acos(cosX);
}
