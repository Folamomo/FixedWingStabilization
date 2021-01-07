//
// Created by igor on 19.12.2020.
//

#ifndef UAV_PID_H
#define UAV_PID_H


class PID {
public:
    PID(float kp, float ki, float kd);

    const float kp, ki, kd;
    float step(float error);
private:
    float lastError;
    float integral;
};


#endif //UAV_PID_H
