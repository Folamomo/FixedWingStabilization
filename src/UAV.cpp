#include "UAV.h"

unsigned long loop_start;
unsigned long loop_end;

#include "Settings.h"
#define micros_per_cycle (1000000/FREQUENCY)

void UAV::update() {
    loop_end += micros_per_cycle;

    radioReceiver.receive();
    sensors.read();
    rigidBody.update(sensors.readings);
    if (radioReceiver.goodConnection){
        if (radioReceiver.commands.stabilize)
            steering.update(stabilizer.update(radioReceiver.commands, rigidBody.heading, rigidBody.omega));
        else
            steering.update(stabilizer.passthrough(radioReceiver.commands));
    } else {
        steering.update(stabilizer.failsafe(rigidBody.heading, rigidBody.omega));
    }
//    logger << rigidBody.heading << rigidBody.omega << radioReceiver.commands << steering.state << "\n";

    while(micros()>loop_end){
        loop_end += micros_per_cycle;
        Serial.println("Skipepd one measure cycle");
    }
    while((loop_start = micros()) < loop_end);
}


void UAV::init() {
    sensors.init();
//    logger.init();
    loop_start = micros();
    loop_end = loop_start;
}



