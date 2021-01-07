//
// Created by igor on 16.12.2020.
//

#ifndef UAVSTABILIZATION_RIGIDBODY_H
#define UAVSTABILIZATION_RIGIDBODY_H


#include "Vector3.h"
#include "Sensors.h"
#include "Quaternion.h"
#include "MadgwickAHRS.h"

class RigidBody {
public:
    MadgwickAHRS madgwickAHRS;
    Quaternion heading;
    Vector3 omega;

    void update(const Sensors::Readings& readings);
};


#endif //UAVSTABILIZATION_RIGIDBODY_H
