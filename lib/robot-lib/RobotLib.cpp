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

    Potentiometer::Potentiometer(int pin) : pin(pin) {
        pinMode(pin, INPUT);
    }

    double Potentiometer::getAngle() {
        int sensorValue = analogRead(pin);
        double angle = map(sensorValue, 0, 1023, 0, 180);
        return angle;
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

    void CommandScheduler::schedule(Command* command) {
        // TODO: Schedule the command only if the requirements are not currently in use
    
        scheduledCommands.push_back(*command);
        command->initialize();
    }
}