//
// Created by igor on 16.12.2020.
//

#include "Sensors.h"
#include "I2Cdev.h"
#include "Wire.h"
#include "Settings.h"
#include <math.h>
#define sensorRange 32768.0

void Sensors::read() {
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    qmc.read(&mx,&my,&mz);

    readings.a = {
            ax / sensorRange * accRange,
            ay / sensorRange * accRange,
            az / sensorRange * accRange
    };

    readings.omega = {
            gx / sensorRange * gyroRange * PI / 180,
            gy / sensorRange * gyroRange * PI / 180,
            gz / sensorRange * gyroRange * PI / 180
    };

    readings.B = {
            -((int16_t)my) / sensorRange * magnetometerRange,
            ((int16_t)mx) / sensorRange * magnetometerRange,
            ((int16_t)mz) / sensorRange * magnetometerRange
    };
}

Sensors::Sensors() {

}

void Sensors::init() {
    Serial.println("Sensors initializing");
    Wire.begin();
    Wire.setClock(1000000);
    accelgyro.initialize();
    qmc.init();

    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");


    accelgyro.setFullScaleAccelRange(accSetting);
    accelgyro.setFullScaleGyroRange(gyroSetting);

    accelgyro.CalibrateAccel(6);
    accelgyro.CalibrateGyro(6);
}
