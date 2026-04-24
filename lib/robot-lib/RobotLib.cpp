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

    CommandScheduler& CommandScheduler::getInstance() {
        static CommandScheduler scheduler;
        return scheduler;
    }

    void CommandScheduler::run() {
        // Run the periodic method of all subsystems
        for (Subsystem subsystem : subsystems) {
            subsystem.periodic();
        }

        for (int i = 0; i < scheduledCommands.size(); i++) {
            // Run the execute method of all scheduled commands
            scheduledCommands[i].execute();

            // Unschedule command if finished
            if (scheduledCommands[i].isFinished()) {
                scheduledCommands.remove(i);
            }
        }
    }
}