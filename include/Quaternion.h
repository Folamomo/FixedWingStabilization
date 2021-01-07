//
// Created by igor on 16.12.2020.
//

#ifndef UAVSTABILIZATION_QUATERNION_H
#define UAVSTABILIZATION_QUATERNION_H


#include "Vector3.h"

class Quaternion {
public:
    double r;
    double i;
    double j;
    double k;

    Quaternion();

    Quaternion(double r, double i, double j, double k);

    Quaternion operator~() const;

    Vector3 toEuler() const;

    void normalize();
};


Quaternion operator* (const Quaternion& p, double r);
Quaternion operator* (const Quaternion& p, const Quaternion& q);
Vector3 discreteDerivative(Quaternion& from,  Quaternion& to, double dt);


#endif //UAVSTABILIZATION_QUATERNION_H
