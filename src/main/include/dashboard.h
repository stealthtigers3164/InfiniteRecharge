#pragma once
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/SendableChooser.h>
#include <Gamepad.h>

class dash{

    public:
        
        dash();
        void read(int pad);

    private:
        
        frc::SendableChooser<Gamepad::controller> controllerOne;
        frc::SendableChooser<Gamepad::controller> controllerTwo;

}