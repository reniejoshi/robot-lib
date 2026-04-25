#include "OI.h"
#include "arm/SetAngleCommand.h"

void OI::configureBindings() {
    CommandScheduler::getInstance().schedule(new SetAngleCommand(&container->arm, potentiometer.getAngle()));
}