#ifndef ARM_SUBSYSTEM_H
#define ARM_SUBSYSTEM_H

#include <RobotLib.h>
#include "RobotMap.h"
using namespace RobotLib;

class ArmSubsystem : public Subsystem {
    public:
        void periodic() override;
        void setAngle(double angle);
    
    private:
        RobotLib::Servo servo{RobotMap::ARM_SERVO_PIN};
};
#endif