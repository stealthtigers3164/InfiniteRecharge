#pragma once
#include <frc/smartdashboard/Smartdashboard.h>
#include <networktables/Networktable.h>
#include <networktables/NetworkTableInstance.h>

//limelight header

class limelight{

    private:

        // declare private limelight variables --  see cpp/limelight.cpp
        float KpAim;
        float KpDistance;
        float main_aim_command;

        float tx;
        float ty;

        // network table to pull limelight values from
        std::shared_ptr<NetworkTable> table;

    public:
        // public constructor
        limelight();
        //update function -- call this from other files to read limelight data
        float update();
};