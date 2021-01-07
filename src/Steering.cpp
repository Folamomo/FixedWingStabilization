//
// Created by igor on 16.12.2020.
//

#include "Steering.h"


void Steering::update(Steering::State newState) {
    state = newState;
    elevatorServo.set(state.elevator);
    rudderServo.set(state.rudder);
    leftAileronServo.set(state.leftAileron);
    rightAileronServo.set(state.rightAileron);
    throttleServo.set(state.throttle);
}

Steering::Steering() :
    elevatorServo(mapping30degrees, 6),
    rudderServo(mapping30degrees, 9),
    leftAileronServo(mapping30degrees, 10),
    rightAileronServo(mapping30degrees, 3),
    throttleServo(mappingThrottle, 5),
    state(){
}
