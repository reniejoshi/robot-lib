#include <RobotLib.h>
#include "ArmSubsystem.h"
using namespace RobotLib;

// TODO: Refactor this to use a header file
class SetAngleCommand : public Command {
    public:
        SetAngleCommand(ArmSubsystem* arm, double angle) : arm(arm), angle(angle) {
            addRequirements(arm);
        }

        void initialize() override {
            arm->setAngle(angle);
        }

    private:
        ArmSubsystem* arm;
        double angle;
};