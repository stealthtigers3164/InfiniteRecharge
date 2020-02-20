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

frc::SendableChooser<input> m_ColourWheel;
frc::SendableChooser<input> m_LimeAutoAlignment;
frc::SendableChooser<input> m_Shooter;
frc::SendableChooser<input> m_Driver;
frc::SendableChooser<input> m_PrevDriver;

enum driver{
    ONE,
    TWO,
    NONE
};

struct input{
    Gamepad::controller button;
    driver controller;
};

input oneA;
input oneB;
input oneX;
input oneY;
input oneLBUMPER;
input oneRBUMPER;
input oneBACK;
input oneSTART;
input oneUPDPAD;
input oneDDPAD;
input oneLDPAD;
input oneRDPAD;
input oneLTRIG;
input oneRTRIG;
input oneLJOY;
input oneRJOY;
input twoA;
input twoB;
input twoX;
input twoY;
input twoLBUMPER;
input twoRBUMPER;
input twoBACK;
input twoSTART;
input twoUPDPAD;
input twoDDPAD;
input twoLDPAD;
input twoRDPAD;
input twoLTRIG;
input twoRTRIG;
input twoLJOY;
input twoRJOY;
input none;

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
    oneSTART.button = Gamepad::controller::START;
    oneSTART.controller = driver::ONE;
    oneUPDPAD.button = Gamepad::controller::UDPAD;
    oneUPDPAD.controller = driver::ONE;
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
    twoBACK.button = Gamepad::controller::BACK;
    twoBACK.controller = driver::TWO;
    twoSTART.button = Gamepad::controller::START;
    twoSTART.controller = driver::TWO;
    twoUPDPAD.button = Gamepad::controller::UDPAD;
    twoUPDPAD.controller = driver::TWO;
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

    m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
    m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

    m_ColourWheel.AddOption("A 1", oneA);
    m_ColourWheel.AddOption("A 2", twoA);
    m_ColourWheel.AddOption("B 1", oneB);
    m_ColourWheel.AddOption("B 2", twoB);
    m_ColourWheel.AddOption("X 1", oneX);
    m_ColourWheel.AddOption("X 2", twoX);
    m_ColourWheel.AddOption("Y 1", oneY);
    m_ColourWheel.AddOption("Y 2", twoY);
/* input oneLBUMPER;
input oneRBUMPER;
input oneBACK;
input oneSTART;
input oneUPDPAD;
input oneDDPAD;
input oneLDPAD;
input oneRDPAD;
input oneLTRIG;
input oneRTRIG;
input oneLJOY;
input oneRJOY; */
    m_ColourWheel.AddOption("Left Bumper 1");
    m_ColourWheel.AddOption("Left Bumper 2");
    m_ColourWheel.AddOption("Right Bumper 1");
    m_ColourWheel.AddOption("Right Bumper 2");
    m_ColourWheel.AddOption("Dpad Up 1");
    m_ColourWheel.AddOption("Dpad Up 2");
    m_ColourWheel.AddOption("Dpad Down 1");
    m_ColourWheel.AddOption("Dpad Down 2");
    m_ColourWheel.AddOption("Dpad Left 1");
    m_ColourWheel.AddOption("Dpad Left 2");
    m_ColourWheel.AddOption("Dpad Right 1");
    m_ColourWheel.AddOption("Dpad Right 2");
    m_ColourWheel.AddOption();
    m_ColourWheel.AddOption();
    m_ColourWheel.AddOption();
    m_ColourWheel.AddOption();
    m_ColourWheel.AddOption();
    m_ColourWheel.AddOption();
    m_ColourWheel.AddOption();
    m_ColourWheel.AddOption();
    m_ColourWheel.AddOption();
    m_ColourWheel.AddOption();
    m_ColourWheel.AddOption();
    m_ColourWheel.AddOption();
    m_ColourWheel.SetDefaultOption("X1", oneX);
    frc::SmartDashboard::PutData("Colour Wheel", &m_ColourWheel);

    m_LimeAutoAlignment.AddOption("A", "A");
    m_LimeAutoAlignment.AddOption("B", "B");
    m_LimeAutoAlignment.AddOption("X", "X");
    m_LimeAutoAlignment.AddOption("Y", "Y");
    m_LimeAutoAlignment.SetDefaultOption("B", "B");
    frc::SmartDashboard::PutData("Limelight", &m_LimeAutoAlignment);

    m_Shooter.AddOption("A", "A");
    m_Shooter.AddOption("B", "B");
    m_Shooter.AddOption("X", "X");
    m_Shooter.AddOption("Y", "Y");
    m_Shooter.SetDefaultOption("X", "X");
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