//
// Created by igor on 19.12.2020.
//

#include "PID.h"
#include "Settings.h"

float PID::step(float error) {
    float out = 0;
    out += kp * error;

    out += kd * (error - lastError) * FREQUENCY;
    lastError = error;

    integral += error * DT;
    out += ki * integral;

    return out;
}

PID::PID(const float kp, const float ki, const float kd) : kp(kp), ki(ki), kd(kd) {}
