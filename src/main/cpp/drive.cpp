#include <iostream>
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
<<<<<<< HEAD
    m_frontRight->Set(left);
    m_backLeft->Set(right);
=======
    m_frontRight->Set(right);
    m_backLeft->Set(left);
>>>>>>> dev
    m_backRight->Set(right);
}