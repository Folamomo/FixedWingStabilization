//
// Created by igor on 16.12.2020.
//

#ifndef UAVSTABILIZATION_RADIORECEIVER_H
#define UAVSTABILIZATION_RADIORECEIVER_H

#define PROTOCOL_LENGTH 60
#define PROTOCOL_CHANNELS 10
#include <UART.h>

class RadioReceiver {
    public:
    struct Commands {
        float pitch;
        float yaw;
        float roll;
        float throttle;
        bool stabilize;
        float flaps;
    } commands;

    bool goodConnection;
    void receive();
    RadioReceiver();
private:
    enum STATE{
        GET_LENGTH,
        GET_DATA,
        GET_CHKSUML,
        GET_CHKSUMH,
        DISCARD
    } state;
    Stream* stream;
    unsigned long last;
    uint8_t buffer[PROTOCOL_LENGTH];
    uint16_t channel[PROTOCOL_CHANNELS];
    uint8_t ptr;
    uint8_t len;
    uint16_t chksum;
    uint8_t lchksum;
};


#endif //UAVSTABILIZATION_RADIORECEIVER_H
