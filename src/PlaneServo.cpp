//
// Created by igor on 19.12.2020.
//

#include "PlaneServo.h"

PlaneServo::PlaneServo(int (*const mapInput)(float), int pin): mapInput(mapInput) {
    servo.attach(pin);
    servo.writeMicroseconds(DEFAULT_PULSE_WIDTH);
}

void PlaneServo::set(float value) {
    servo.writeMicroseconds(mapInput(value));
}

int noLimitsMapping(float value){
    return DEFAULT_PULSE_WIDTH + value * (DEFAULT_PULSE_WIDTH - MIN_PULSE_WIDTH);
}

int mapping30degrees(float value) {
    return DEFAULT_PULSE_WIDTH + value * 450;
}

int mappingThrottle(float value) {
    return MIN_PULSE_WIDTH + value * (MAX_PULSE_WIDTH - MIN_PULSE_WIDTH);
}