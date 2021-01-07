//
// Created by igor on 16.12.2020.
//

#include <Settings.h>
#include "RigidBody.h"

void RigidBody::update(const Sensors::Readings &readings) {
    Quaternion oldHeading = madgwickAHRS.orientation;
    madgwickAHRS.MadgwickAHRSupdate(readings.omega, readings.a, readings.B);
    heading = madgwickAHRS.orientation;
    omega = discreteDerivative(oldHeading, heading, DT);
}
