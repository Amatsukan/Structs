#include <iostream>
    #include "structures/Array/numericVector.h"

using namespace std;

int main() {
    NumVector a = NumVector(2);
    a[0] = 1;
    a[1] = 2;
    NumVector b = a;
    a[1] = 1;
    std::cout<<a.degAngle(a,b);
    return 0;
}