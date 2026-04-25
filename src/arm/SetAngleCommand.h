#include <RobotLib.h>
#include "ArmSubsystem.h"
using namespace RobotLib;

// TODO: Refactor this to use a header file
class SetAngleCommand : public Command {
    public:
        SetAngleCommand(ArmSubsystem* arm, double angle);
        void initialize() override;

    private:
        ArmSubsystem* arm;
        double angle;
};