//
// Created by jake on 10/05/15.
//

#include "numVector3d.h"

numVector3d numVector3d::vectorProduct(numVector3d &v2) {
    numVector3d a = numVector3d();
    a[0] = ((this->at(1)*v2[2])-( v2[1]*this->at(2)));
    a[1] = ((this->at(0)*v2[2])-( v2[0]*this->at(2)));
    a[2] = ((this->at(0)*v2[1])-( v2[0]*this->at(1)));
}

numVector3d::numVector3d() :
    NumVector(3)
{}
