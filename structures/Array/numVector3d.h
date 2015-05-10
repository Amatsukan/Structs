//
// Created by jake on 10/05/15.
//

#ifndef GRAPHS_NUMVECTOR3D_H
#define GRAPHS_NUMVECTOR3D_H

#include "numericVector.h"

class numVector3d : public NumVector {
public:
    numVector3d();
    numVector3d scalarProduct (numVector3d&);
};


#endif //GRAPHS_NUMVECTOR3D_H
