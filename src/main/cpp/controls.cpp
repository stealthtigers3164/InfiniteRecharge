#include <controls.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <httplib.h>

shuffle::shuffle(){

    m_PrevDriverSelected = "Default";

    m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
    m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
    
    m_Driver.AddOption("Default", "Default");
    m_Driver.AddOption("Driver1", "Driver1");
    m_Driver.AddOption("Driver2", "Driver2");
    m_Driver.AddOption("Driver3", "Driver3");
    m_Driver.SetDefaultOption("Default", "Default");
    frc::SmartDashboard::PutData("Driver", &m_Driver);

    frc::SmartDashboard::PutString("Host", "172.20.10.2");
    frc::SmartDashboard::PutString("Mech", "limelight");
    frc::SmartDashboard::PutNumber("Controller", 1);
    frc::SmartDashboard::PutString("Button", "A");
}

shuffle::keybind shuffle::getControl(std::string mech){
    keybind result;
    result.controller;
    result.button;
    return result;
}