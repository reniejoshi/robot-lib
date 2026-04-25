#include "SetAngleCommand.h"

SetAngleCommand::SetAngleCommand(ArmSubsystem* arm, double angle) : arm(arm), angle(angle) {
    addRequirements(arm);
}

void SetAngleCommand::initialize() {
    arm->setAngle(angle);
}