//
// Created by igor on 16.12.2020.
//

#include "Logger.h"
#include <SD.h>


Logger Logger::operator<<(unsigned long time) {
    out.write(String(time).c_str());
    return *this;
}

Logger Logger::operator<<(const Steering::State &state) {
    return *this;
}

Logger Logger::operator<<(const Quaternion &heading) {
    return *this;
}

Logger Logger::operator<<(const Vector3 &omega) {
    return *this;
}

Logger Logger::operator<<(const RadioReceiver::Commands &commands) {
    return *this;
}



Logger::Logger() {

}

void Logger::getAndIncrementID() {
    const char* nextLog = "next_log.txt";
    SD.begin();
    if(SD.exists(nextLog)){
        File next = SD.open(nextLog, FILE_READ);
        fileID = next.parseInt();
        next.close();
    }
    File next = SD.open(nextLog, O_WRITE | O_CREAT | O_TRUNC);
    next.print(fileID + 1);
    next.close();
}

Logger Logger::operator<<(const char *string) {
    out.write(string);
    return *this;
}

Logger Logger::operator<<(String &string) {
    out.write(string.c_str());
    return *this;
}

Logger::~Logger() {
    out.close();

}

void Logger::init() {
    getAndIncrementID();
    char filename[30];
    sprintf(filename, "LOG%lu", fileID);
    out = SD.open(filename, O_WRITE | O_CREAT | O_TRUNC);
}
