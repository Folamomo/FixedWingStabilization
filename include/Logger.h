//
// Created by igor on 16.12.2020.
//

#ifndef UAVSTABILIZATION_LOGGER_H
#define UAVSTABILIZATION_LOGGER_H


#include "Steering.h"
#include "Quaternion.h"
#include "Vector3.h"
#include "RadioReceiver.h"
#include <SD.h>

class Logger {
private:
    unsigned long fileID = 0;
    SDFile out;
public:
    Logger();
    void init();
    Logger operator <<(unsigned long time);
    Logger operator <<(const Steering::State& state);
    Logger operator <<(const Quaternion& heading);
    Logger operator <<(const Vector3& omega);
    Logger operator <<(const RadioReceiver::Commands& commands);
    Logger operator <<(String& string);
    Logger operator <<(const char* string);

    void getAndIncrementID();
    ~Logger();
};


#endif //UAVSTABILIZATION_LOGGER_H
