//
// Created by igor on 16.12.2020.
//

#ifndef UAVSTABILIZATION_STABILIZER_H
#define UAVSTABILIZATION_STABILIZER_H

#include "RadioReceiver.h"
#include "Vector3.h"
#include "Quaternion.h"
#include "Steering.h"
#include "PID.h"

#define failsafeRollRadians 0.015
#define failsafeFlaps 0.2

class Stabilizer {
public:
    Steering::State update(const RadioReceiver::Commands& commands, Quaternion heading, Vector3 omega);
    Steering::State passthrough(const RadioReceiver::Commands& commands);
    Steering::State failsafe(Quaternion heading, Vector3 omega);

private:
    PID staticPitch{0.01, 0, 0.05};
    PID staticRoll{0.02, 0, 0.05};
    PID dynamicPitch{0.02, 0, 0.01};
    PID dynamicRoll{0.02, 0, 0.01};
    PID dynamicYaw{0.02, 0, 0.01};
};


#endif //UAVSTABILIZATION_STABILIZER_H
