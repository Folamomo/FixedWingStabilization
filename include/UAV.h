#ifndef UAVSTABILIZATION_UAV_H
#define UAVSTABILIZATION_UAV_H

#include "RigidBody.h"
#include "RadioReceiver.h"
#include "Stabilizer.h"
#include "Steering.h"
#include "Sensors.h"
#include "Logger.h"

class UAV{
private:
    RigidBody rigidBody{};
    Stabilizer stabilizer{};
    Logger logger{};
    RadioReceiver radioReceiver{};
    Steering steering{};
    Sensors sensors{};

public:
    void init();
    void update();
};

#endif //UAVSTABILIZATION_UAV_H
