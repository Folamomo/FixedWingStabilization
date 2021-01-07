//
// Created by igor on 16.12.2020.
//

#ifndef UAVSTABILIZATION_STEERING_H
#define UAVSTABILIZATION_STEERING_H

#include "Servo.h"
#include "PlaneServo.h"

class Steering {
public:
    Steering();
    struct State {
        float leftAileron;
        float rightAileron;
        float rudder;
        float elevator;
        float throttle;
    } state;
    void update(State newState);

private:
    PlaneServo elevatorServo;
    PlaneServo rudderServo;
    PlaneServo leftAileronServo;
    PlaneServo rightAileronServo;
    PlaneServo throttleServo;
};




#endif //UAVSTABILIZATION_STEERING_H
