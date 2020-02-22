/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include <Gamepad.h>

frc::SendableChooser<std::string> m_chooser;
const std::string kAutoNameDefault = "Default";
const std::string kAutoNameCustom = "My Auto";
std::string m_autoSelected;
std::string m_PrevDriverSelected = "Default";
std::string m_DriverSelected;

frc::SendableChooser<inputChooser> m_ColourWheel;
frc::SendableChooser<inputChooser> m_LimeAutoAlignment;
frc::SendableChooser<inputChooser> m_Shooter;
frc::SendableChooser<inputChooser> m_Driver;
frc::SendableChooser<inputChooser> m_PrevDriver;

enum driver{
    ONE,
    TWO,
    NONE
};

struct inputChooser{
    Gamepad::controller button;
    driver controller;
};

inputChooser oneA;
inputChooser oneB;
inputChooser oneX;
inputChooser oneY;
inputChooser oneLBUMPER;
inputChooser oneRBUMPER;
inputChooser oneBACK;
inputChooser oneSTART;
inputChooser oneUDPAD;
inputChooser oneDDPAD;
inputChooser oneLDPAD;
inputChooser oneRDPAD;
inputChooser oneLTRIG;
inputChooser oneRTRIG;
inputChooser oneLJOY;
inputChooser oneRJOY;
inputChooser twoA;
inputChooser twoB;
inputChooser twoX;
inputChooser twoY;
inputChooser twoLBUMPER;
inputChooser twoRBUMPER;
inputChooser twoBACK;
inputChooser twoSTART;
inputChooser twoUDPAD;
inputChooser twoDDPAD;
inputChooser twoLDPAD;
inputChooser twoRDPAD;
inputChooser twoLTRIG;
inputChooser twoRTRIG;
inputChooser twoLJOY;
inputChooser twoRJOY;
inputChooser none;

inputChooser buttonsList[33] = {
    oneA,
    oneB,
    oneX,
    oneY,
    oneLBUMPER,
    oneRBUMPER,
    oneBACK,
    oneSTART,
    oneUDPAD,
    oneDDPAD,
    oneLDPAD,
    oneRDPAD,
    oneLTRIG,
    oneRTRIG,
    oneLJOY,
    oneRJOY,
    twoA,
    twoB,
    twoX,
    twoY,
    twoLBUMPER,
    twoRBUMPER,
    twoBACK,
    twoSTART,
    twoUDPAD,
    twoDDPAD,
    twoLDPAD,
    twoRDPAD,
    twoLTRIG,
    twoRTRIG,
    twoLJOY,
    twoRJOY,
    none
};

std::string names[33] = {
    "A 1",
    "B 1",
    "X 1",
    "Y 1",
    "Left Bumper 1",
    "Right Bumper 1",
    "Dpad Up 1",
    "Dpad Down 1",
    "Dpad Left 1",
    "Dpad Right 1",
    "Left Trigger 1",
    "Right Trigger 1",
    "Left Joystick Button 1",
    "Right Joystick Button 1",
    "Start 1",
    "Back 1",
    "A 2",
    "B 2",
    "X 2",
    "Y 2",
    "Left Bumper 2",
    "Right Bumper 2",
    "Dpad Up 2",
    "Dpad Down 2",
    "Dpad Left 2",
    "Dpad Right 2",
    "Left Trigger 2",
    "Right Trigger 2",
    "Left Joystick Button 2",
    "Right Joystick Button 2",
    "Start 2",
    "Back 2",
    "None"
};

void DashInit(){

    oneA.button = Gamepad::controller::A;
    oneA.controller = driver::ONE;
    oneB.button = Gamepad::controller::A;
    oneB.controller = driver::ONE;
    oneX.button = Gamepad::controller::A;
    oneX.controller = driver::ONE;
    oneY.button = Gamepad::controller::A;
    oneY.controller = driver::ONE;
    oneLBUMPER.button = Gamepad::controller::LBUMPER;
    oneLBUMPER.controller = driver::ONE;
    oneUDPAD.button = Gamepad::controller::UDPAD;
    oneUDPAD.controller = driver::ONE;
    oneDDPAD.button = Gamepad::controller::DDPAD;
    oneDDPAD.controller = driver::ONE;
    oneLDPAD.button = Gamepad::controller::LDPAD;
    oneLDPAD.controller = driver::ONE;
    oneRDPAD.button = Gamepad::controller::RDPAD;
    oneRDPAD.controller = driver::ONE;
    oneLTRIG.button = Gamepad::controller::LTRIG;
    oneLTRIG.controller = driver::ONE;
    oneRTRIG.button = Gamepad::controller::RTRIG;
    oneRTRIG.controller = driver::ONE;
    oneLJOY.button = Gamepad::controller::LJOY;
    oneLJOY.controller = driver::ONE;
    oneRJOY.button = Gamepad::controller::RJOY;
    oneRJOY.controller = driver::ONE;
    oneSTART.button = Gamepad::controller::START;
    oneSTART.controller = driver::ONE;
    oneBACK.button = Gamepad::controller::BACK;
    oneBACK.controller = driver::ONE;
    twoA.button = Gamepad::controller::A;
    twoA.controller = driver::TWO;
    twoB.button = Gamepad::controller::B;
    twoB.controller = driver::TWO;
    twoX.button = Gamepad::controller::X;
    twoX.controller = driver::TWO;
    twoY.button = Gamepad::controller::Y;
    twoY.controller = driver::TWO;
    twoLBUMPER.button = Gamepad::controller::LBUMPER;
    twoLBUMPER.controller = driver::TWO;
    twoRBUMPER.button = Gamepad::controller::RBUMPER;
    twoRBUMPER.controller = driver::TWO;
    twoUDPAD.button = Gamepad::controller::UDPAD;
    twoUDPAD.controller = driver::TWO;
    twoDDPAD.button = Gamepad::controller::DDPAD;
    twoDDPAD.controller = driver::TWO;
    twoLDPAD.button = Gamepad::controller::LDPAD;
    twoLDPAD.controller = driver::TWO;
    twoRDPAD.button = Gamepad::controller::RDPAD;
    twoRDPAD.controller = driver::TWO;
    twoLTRIG.button = Gamepad::controller::LTRIG;
    twoLTRIG.controller = driver::TWO;
    twoRTRIG.button = Gamepad::controller::RTRIG;
    twoRTRIG.controller = driver::TWO;
    twoLJOY.button = Gamepad::controller::LJOY;
    twoLJOY.controller = driver::TWO;
    oneRJOY.button = Gamepad::controller::RJOY;
    oneRJOY.controller = driver::TWO;
    none.button = Gamepad::controller::NONE;
    none.controller = driver::NONE;
    twoSTART.button = Gamepad::controller::START;
    twoSTART.controller = driver::TWO;
    twoBACK.button = Gamepad::controller::BACK;
    twoBACK.controller = driver::TWO;

    for (int i=0; i<33; i++){
        m_ColourWheel.AddOption(names[i], buttonsList[i]);
        m_LimeAutoAlignment.AddOption(names[i], buttonsList[i]);
        m_Shooter.AddOption.AddObject(names[i], buttonsList[i]);
    }

    m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
    m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

    m_ColourWheel.SetDefaultOption("X 1", oneX);
    frc::SmartDashboard::PutData("Colour Wheel", &m_ColourWheel);

    m_LimeAutoAlignment.SetDefaultOption("A 1", oneA);
    frc::SmartDashboard::PutData("Limelight", &m_LimeAutoAlignment);

    m_Shooter.SetDefaultOption("Right Bumper 1", oneRBUMPER);
    frc::SmartDashboard::PutData("Shooter", &m_Shooter);
    
    m_Driver.AddOption("Default", "Default");
    m_Driver.AddOption("Driver1", "Driver1");
    m_Driver.AddOption("Driver2", "Driver2");
    m_Driver.AddOption("Driver3", "Driver3");
    m_Driver.SetDefaultOption("Default", "Default");
    frc::SmartDashboard::PutData("Driver", &m_Driver);
}

void DashboardCheck(){
    m_DriverSelected = m_Driver.GetSelected();
    if (m_PrevDriverSelected != m_DriverSelected){
        if (m_DriverSelected == "Driver1"){
            m_Shooter.SetDefaultOption("Y", "Y");
            frc::SmartDashboard::PutData("Shooter", &m_Shooter);
        }
        else if (m_DriverSelected == "Driver2"){
            m_Shooter.SetDefaultOption("X", "X");
            frc::SmartDashboard::PutData("Shooter", &m_Shooter);
        }
    }
    m_PrevDriverSelected = m_DriverSelected;
}
