#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Spark.h>
#include <Gamepad.h>
#include <drive.h>
#include <ctre/Phoenix.h>



drive::drive(){
    std::cout << "WARNING! No ports defined for drive class constructor." <<  std::endl;
}

drive::drive(int backLeft, int frontLeft, int frontRight, int backRight){
    m_frontLeft = new WPI_VictorSPX(5);
    m_frontRight = new WPI_VictorSPX(8);
    m_backLeft = new WPI_VictorSPX(0);
    m_backRight = new WPI_VictorSPX(1);
} 

void drive::update(float left, float right){
    m_frontLeft->Set(left);
    m_frontRight->Set(right);
    m_backLeft->Set(left);
    m_backRight->Set(right);
}
/*#include <iostream>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Spark.h>
#include <Gamepad.h>
#include <drive.h>



drive::drive(){
    std::cout << "WARNING! No ports defined for drive class constructor." <<  std::endl;
}

drive::drive(int backLeft, int frontLeft, int frontRight, int backRight){
    m_frontLeft = new frc::Spark(frontLeft);
    m_frontRight = new frc::Spark(frontRight);
    m_backLeft = new frc::Spark(backLeft);
    m_backRight = new frc::Spark(backRight);
}

void drive::update(float left, float right){
    m_frontLeft->Set(left);
    m_frontRight->Set(right);
    m_backLeft->Set(left);
    m_backRight->Set(right);
}*/