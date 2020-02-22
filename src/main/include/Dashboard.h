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

class shuffle{

    public:

        shuffle();

        enum driver{
            ONE,
            TWO,
            NONE
        };

        struct inputChooser{
            Gamepad::controller button;
            driver controller;
        };

    private:

        //initialize smartdashboard values
        frc::SendableChooser<std::string> m_chooser;
        const std::string kAutoNameDefault = "Default";
        const std::string kAutoNameCustom = "My Auto";
        std::string m_autoSelected;
        std::string m_PrevDriverSelected;
        std::string m_DriverSelected;

        frc::SendableChooser<inputChooser> m_ColourWheel;
        frc::SendableChooser<inputChooser> m_LimeAutoAlignment;
        frc::SendableChooser<inputChooser> m_Shooter;
        frc::SendableChooser<std::string> m_Driver;
        frc::SendableChooser<std::string> m_PrevDriver;

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

        const inputChooser buttonsList[33] = {
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

        const std::string names[33] = {
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

};

/*
void DashboardCheck(){
    m_DriverSelected = m_Driver.GetSelected();
    if (m_PrevDriverSelected != m_DriverSelected){
        if (m_DriverSelected == "Driver1"){
            m_Shooter.SetDefaultOption("Y", oneY);
            frc::SmartDashboard::PutData("Shooter", &m_Shooter);
        }
        else if (m_DriverSelected == "Driver2"){
            m_Shooter.SetDefaultOption("X", oneX);
            frc::SmartDashboard::PutData("Shooter", &m_Shooter);
        }
    }
    m_PrevDriverSelected = m_DriverSelected;
}
*/
