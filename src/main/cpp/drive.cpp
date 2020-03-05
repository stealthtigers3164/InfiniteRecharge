#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <ctre/Phoenix.h>
#include <Gamepad.h>
#include <drive.h>

drive::drive(){
    std::cout << "WARNING! No ports defined for drive class constructor." <<  std::endl;
}

//told to turn this from spark into victor SPX
//therefore changes have been made

drive::drive(int backLeft, int frontLeft, int frontRight, int backRight){
    m_frontLeft = new WPI_VictorSPX(frontLeft);
    m_frontRight = new WPI_VictorSPX(frontRight);
    m_backLeft = new WPI_VictorSPX(backLeft);
    m_backRight = new WPI_VictorSPX(backRight);
}

void drive::update(float left, float right){
    m_frontLeft->Set(ControlMode::PercentOutput, left);
    m_frontRight->Set(ControlMode::PercentOutput, right);
    m_backLeft->Set(ControlMode::PercentOutput, left);
    m_backRight->Set(ControlMode::PercentOutput, right);
}