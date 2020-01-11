#pragma once
#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Spark.h>
#include <Gamepad.h>

class drive{

    //create private 
    private:
        frc::Spark *m_frontLeft;
        frc::Spark *m_backLeft;
        frc::Spark *m_frontRight;
        frc::Spark *m_backRight;

    public:
        drive();
        drive(int frontLeft, int backLeft, int frontRight, int backRight);
        
        int update(double left, double right);
};