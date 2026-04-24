#ifndef ROBOT_CONTAINER_H
#define ROBOT_CONTAINER_H

#include "arm/ArmSubsystem.h"
#include "OI.h"

class RobotContainer {
    public:
        RobotContainer() : arm(), oi(this) {}
        ArmSubsystem arm;
        OI oi;
};

#endif