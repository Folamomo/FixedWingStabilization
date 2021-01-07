//
// Created by igor on 16.12.2020.
//

#define PROTOCOL_TIMEGAP 3

#define PROTOCOL_OVERHEAD 3
#define PROTOCOL_COMMAND40 0x40

#include "RadioReceiver.h"
#include <Arduino.h>



void RadioReceiver::receive() {
    while (stream->available() > 0) {
        // only consider a new data package if we have not heard anything for >3ms
        uint32_t now = millis();
        if (now - last >= PROTOCOL_TIMEGAP){
            state = GET_LENGTH;
        }
        last = now;

        uint8_t v = stream->read();
        switch (state) {
            case GET_LENGTH:
                if (v <= PROTOCOL_LENGTH && v > PROTOCOL_OVERHEAD) {
                    ptr = 0;
                    len = v - PROTOCOL_OVERHEAD;
                    chksum = 0xFFFF - v;
                    state = GET_DATA;
                } else {
                    state = DISCARD;
                }
                break;

            case GET_DATA:
                buffer[ptr++] = v;
                chksum -= v;
                if (ptr == len) {
                    state = GET_CHKSUML;
                }
                break;

            case GET_CHKSUML:
                lchksum = v;
                state = GET_CHKSUMH;
                break;

            case GET_CHKSUMH:
                // Validate checksum
                if (chksum == (v << 8) + lchksum) {
                    // Checksum is all fine Execute command -
                    uint8_t adr = buffer[0] & 0x0f;
                    if (buffer[0]==PROTOCOL_COMMAND40) {
                        // Valid servo command received - extract channel data
                        for (uint8_t i = 1; i < PROTOCOL_CHANNELS * 2 + 1; i += 2) {
                            channel[i / 2] = buffer[i] | (buffer[i + 1] << 8);
                        }
                        Serial.println(channel[0]);
                    }
                }
                state = DISCARD;
                break;

            case DISCARD:
            default:
                break;
        }
    }

    if (millis() - last >= 1000){
        goodConnection = false;
    } else {
        goodConnection = true;
        commands.roll = (channel[0]-1500)/500.0;
        commands.pitch = (channel[1]-1500)/500.0;
        commands.throttle = (channel[2]-1000)/1000.0;
        commands.yaw = (channel[3]-1500)/500.0;
        commands.flaps = (channel[5]-1500)/500.0;
        commands.stabilize = channel[6] > 1500;
    }
}

RadioReceiver::RadioReceiver() {
    Serial1.begin(115200);
    stream = &Serial1;
    last = millis();
    state = DISCARD;
    ptr = 0;
    len = 0;
    chksum = 0;
    lchksum = 0;
}
