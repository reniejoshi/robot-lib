#include <RobotLib.h>
#include "RobotContainer.h"
#include "RobotMap.h"
using namespace RobotLib;

class OI {
    public:
        OI(RobotContainer* container) : container(container) {}

    private:
        RobotContainer* container;
        Potentiometer potentiometer{RobotMap::POTENTIOMETER_PIN};
        void configureBindings();
};