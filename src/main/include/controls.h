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
#include <httplib.h>
#include <Gamepad.h>

class shuffle{

    public:

        shuffle();

        typedef struct keybind{
            int controller;
            std::string button;
        };

        keybind getControl(std::string);

    private:

        //initialize smartdashboard values
        frc::SendableChooser<std::string> m_chooser;
        const std::string kAutoNameDefault = "Default";
        const std::string kAutoNameCustom = "My Auto";
        std::string m_autoSelected;
        std::string m_PrevDriverSelected;
        std::string m_DriverSelected;

        frc::SendableChooser<std::string> m_Driver;

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