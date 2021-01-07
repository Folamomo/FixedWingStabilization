#include <Arduino.h>
#include <UAV.h>


UAV uav{};
void setup() {
    Serial.begin(115200);
    Serial.println("Hello World!\n");
    uav.init();
}


void loop() {
    uav.update();
}

