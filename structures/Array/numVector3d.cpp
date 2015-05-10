//
// Created by jake on 10/05/15.
//

#include "numVector3d.h"

numVector3d numVector3d::scalarProduct(numVector3d &v2) {
    numVector3d a = numVector3d();
    a[0] = ((this->get(1)*v2[2])-( v2[1]*this->get(2)));
    a[1] = ((this->get(0)*v2[2])-( v2[0]*this->get(2)));
    a[2] = ((this->get(0)*v2[1])-( v2[0]*this->get(1)));
}

numVector3d::numVector3d() {
    this->size = 3;
    this->arr = new double[3];
}
