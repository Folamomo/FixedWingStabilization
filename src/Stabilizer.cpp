//
// Created by igor on 16.12.2020.
//

#include "Stabilizer.h"

float limit(float in){
    return in > 1.0 ? 1.0 : in < -1.0 ? -1.0 : in;
}

Steering::State Stabilizer::update(const RadioReceiver::Commands &commands, Quaternion heading, Vector3 omega) {
    RadioReceiver::Commands regulated_commands{};
    Vector3 angles = heading.toEuler();
    float staticPitchResult = staticPitch.step(-angles.y);
    float staticRollResult  = staticRoll.step(-angles.x);

    return passthrough({
        dynamicPitch.step(commands.pitch + staticPitchResult - omega.y),
        dynamicYaw.step(commands.yaw - omega.z),
        dynamicRoll.step(commands.roll + staticRollResult - omega.x),
        commands.throttle,
        commands.stabilize,
        commands.flaps
    });
}

Steering::State Stabilizer::passthrough(const RadioReceiver::Commands &commands) {
    return Steering::State{
        limit(commands.roll + commands.flaps),
        limit(-commands.roll + commands.flaps),
        limit(commands.yaw),
        limit(commands.pitch),
        commands.throttle
    };
}

Steering::State Stabilizer::failsafe(Quaternion heading, Vector3 omega) {
    Vector3 angles = heading.toEuler();
    Serial.print(omega.x);Serial.print("\t");
    Serial.print(omega.y);Serial.print("\t");
    Serial.println(omega.z);
    float staticPitchResult = staticPitch.step(-angles.y);
    float staticRollResult  = staticRoll.step(failsafeRollRadians-angles.x);

    return passthrough({       dynamicPitch.step(staticPitchResult - omega.y),
                               dynamicYaw.step(-omega.z),
                               dynamicRoll.step(staticRollResult - omega.x),
                               0,
                               true,
                               failsafeFlaps
    });
}

