#pragma once
#include <frc/smartdashboard/Smartdashboard.h>
#include <networktables/Networktable.h>
#include <networktables/NetworkTableInstance.h>

//limelight header

class limelight{

    private:
        float KpAim;
        float KpDistance;
        float main_aim_command;

        float tx;
        float ty;

    public:
        limelight();
        float update();
};