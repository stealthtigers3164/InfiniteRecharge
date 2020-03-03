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
// https://github.com/yhirose/cpp-httplib
#include <httplib.h>
// https://github.com/dropbox/json11
#include <json11.hpp>
#include <Gamepad.h>

class controls{

    public:

        controls();

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

        httplib::Client client;
        json11::Json json;

};