#include "RobotLib.h"
#include <Arduino.h>
#include <Servo.h>

namespace RobotLib {
    Servo::Servo(int pin) {
        servoLib.attach(pin);
    }

    void Servo::setAngle(double angle) {
        angle = constrain(angle, 0, 180);
        servoLib.write(angle);
    }
}