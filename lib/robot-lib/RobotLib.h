#ifndef ROBOT_LIB_H
#define ROBOT_LIB_H

#include <Servo.h>
#include <Vector.h>

namespace RobotLib {
    class Subsystem {
        public:
            virtual void periodic();
    };

    class Command {
        public:
            virtual void initialize();
            virtual void execute();
            virtual void end(bool interrupted);
            virtual bool isFinished();
            void addRequirements(Subsystem* requirements);
            void schedule();
        
        private:
            Subsystem* requirement;
    };

    class CommandScheduler final {
        public:
            static CommandScheduler& getInstance();
            void run();
            void schedule();

        private:
            CommandScheduler& instance;
            Vector<Command> scheduledCommands;
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