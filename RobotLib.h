#ifndef ROBOT_LIB_H
#define ROBOT_LIB_H

#include <Servo.h>

namespace RobotLib {
    class Subsystem {

    };

    class Command {

    };

    class CommandScheduler final {

    };

    class RobotBase {

    };

    class Servo {
        public:
            Servo(int pin);
            void setAngle(double angle);
        
        private:
            ::Servo servoLib;
    };
}
#endif