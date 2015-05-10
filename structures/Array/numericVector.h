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
