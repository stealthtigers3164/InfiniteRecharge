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

#include "Robot.h"
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"

    static constexpr auto i2cPort = frc::I2C::Port::kOnboard;
    rev::ColorSensorV3 m_colorSensor{i2cPort};
    rev::ColorMatch m_colorMatcher;
    static constexpr frc::Color kBlueTarget = frc::Color(0.143, 0.427, 0.429);
    static constexpr frc::Color kGreenTarget = frc::Color(0.197, 0.561, 0.240);
    static constexpr frc::Color kRedTarget = frc::Color(0.561, 0.232, 0.114);
    static constexpr frc::Color kYellowTarget = frc::Color(0.361, 0.524, 0.113);

    frc::Spark *motor = new frc::Spark(5); 


    void declaration(){
        m_colorMatcher.AddColorMatch(kBlueTarget);
        m_colorMatcher.AddColorMatch(kGreenTarget);
        m_colorMatcher.AddColorMatch(kRedTarget);
        m_colorMatcher.AddColorMatch(kYellowTarget);
    }

    void detectColour(){
        frc::Color detectedColor = m_colorSensor.GetColor();
        std::string colorString;
        double confidence = 0.0;
        frc::Color matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);

        if (matchedColor == kBlueTarget) {
            colorString = "Blue";
            motor->Set(0.25);
        } else if (matchedColor == kRedTarget) {
            colorString = "Red";
            motor->Set(0);
        } else if (matchedColor == kGreenTarget) {
            colorString = "Green";
            motor->Set(0.25);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
            motor->Set(0.25);
        } else if (matchedColor == kYellowTarget) {
            colorString = "Yellow";
            motor->Set(0.25);
    
        } else {
            colorString = "Unknown";
        }

        frc::SmartDashboard::PutNumber("Red", detectedColor.red);
        frc::SmartDashboard::PutNumber("Green", detectedColor.green);
        frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
        frc::SmartDashboard::PutNumber("Confidence", confidence);
        frc::SmartDashboard::PutString("Detected Color", colorString);
    }