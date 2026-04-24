#include <RobotLib.h>
#include "RobotMap.h"
#include "ArmSubsystem.h"
using namespace RobotLib;

void ArmSubsystem::setAngle(double angle) {
    servo.setAngle(angle);
};