//
// Created by igor on 16.12.2020.
//

#ifndef UAVSTABILIZATION_SENSORS_H
#define UAVSTABILIZATION_SENSORS_H


#include <MechaQMC5883.h>
#include <MPU6050.h>
#include "Vector3.h"

class Sensors {
public:
    struct Readings {
        Vector3 a;
        Vector3 omega;
        Vector3 B;
    } readings;

    Sensors();
    void read();
    void init();
private:
    MPU6050 accelgyro;
    MechaQMC5883 qmc;
    int16_t ax, ay, az;
    int16_t gx, gy, gz;
    uint16_t mx, my, mz;
};


#endif //UAVSTABILIZATION_SENSORS_H
