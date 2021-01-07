//
// Created by igor on 19.12.2020.
//

#ifndef UAV_PLANESERVO_H
#define UAV_PLANESERVO_H

#include <Servo.h>



class PlaneServo {
public:
    void set(float value);
    PlaneServo(int (*const mapInput)(float), int pin);
private:
    int (*const mapInput)(float);
    Servo servo;
};

int noLimitsMapping(float value);

int mapping30degrees(float value);

int mappingThrottle(float value);

#endif //UAV_PLANESERVO_H
