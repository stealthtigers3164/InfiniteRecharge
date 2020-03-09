#pragma once
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
/* changed from spark to victor SPX
#include <frc/Spark.h>*/
#include <ctre/Phoenix.h>
#include <Gamepad.h>

class drive{

    //create private 
    private:
        WPI_VictorSPX *m_frontLeft;
        WPI_VictorSPX *m_backLeft;
        WPI_VictorSPX *m_frontRight;
        WPI_VictorSPX *m_backRight;

    public:
        drive();
        drive(int backLeft, int frontLeft, int frontRight, int backRight);
        
        void update(float left, float right);
};