#include <RobotLib.h>
#include "RobotContainer.h"
using namespace RobotLib;

class OI {
    public:
        OI(RobotContainer* container) : container(container) {}

    private:
        RobotContainer* container;
        void configureBindings();
};