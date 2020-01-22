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
#include <frc/Joystick.h>
#include <frc/smartdashboard/smartdashboard.h>

#include "Robot.h"
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include <frc/DriverStation.h>


    static constexpr auto i2cPort = frc::I2C::Port::kOnboard;
    rev::ColorSensorV3 m_colorSensor{i2cPort};
    rev::ColorMatch m_colorMatcher;
  static constexpr frc::Color kBlueTarget = frc::Color(0.143, 0.427, 0.429);
  static constexpr frc::Color kGreenTarget = frc::Color(0.197, 0.561, 0.240);
  static constexpr frc::Color kRedTarget = frc::Color(0.561, 0.232, 0.114);
  static constexpr frc::Color kYellowTarget = frc::Color(0.361, 0.524, 0.113);

    frc::Spark *motor = new frc::Spark(5); 
    bool targetGreen = false;
    bool targetRed = false;
    bool targetBlue = false;
    bool targetYellow = false;

    std::string gameData;
   
     void declaration(){
        m_colorMatcher.AddColorMatch(kBlueTarget);
        m_colorMatcher.AddColorMatch(kGreenTarget);
        m_colorMatcher.AddColorMatch(kRedTarget);
        m_colorMatcher.AddColorMatch(kYellowTarget);
        frc::SmartDashboard::PutNumber("Colour", 0);
       }   
  


    double speed = 0.26;
    
    void detectColour(){
        frc::Color detectedColor = m_colorSensor.GetColor();
        std::string colorString;
        double confidence = 0.0;
        frc::Color matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);
        motor->Set(speed);
         gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
        if(gameData.length() > 0){
        switch (gameData[0]){
            case 'B' :
            targetBlue = true;
            targetGreen = false;
            targetRed = false;
            targetYellow = false;
            break;
            case 'G' :
            targetBlue = false;
            targetGreen = true;
            targetRed = false;
            targetYellow = false;
            break;
            case 'R' :
            targetBlue = false;
            targetGreen = false;
            targetRed = true;
            targetYellow = false;
            break;
            case 'Y' :
            targetBlue = true;
            targetGreen = false;
            targetRed = false;
            targetYellow = true;
            break;
            default :
            //This is corrupt data
            break;
        }
        }else{
            targetBlue = false;
            targetGreen = false;
            targetRed = false;
            targetYellow = false;
        }
        if (matchedColor == kBlueTarget) {
            colorString = "Blue";
            if(targetBlue){
                motor->Set(0);
            }else{
                motor->Set(speed);
            }
            
        } else if (matchedColor == kRedTarget) {
            colorString = "Red";
           if(targetRed){
               motor->Set(0);
            }else{
                motor->Set(speed);
            }
        } else if (matchedColor == kGreenTarget) {
            colorString = "Green";
            if(targetGreen){
                motor->Set(0);
            }else{
                motor->Set(speed);
            }
        }
        else if (matchedColor == kYellowTarget) {
            colorString = "Yellow";
            if(targetYellow){
                motor->Set(0);
            }else{
                motor->Set(speed);
            }
        } else {
            colorString = "Unknown";
        }
        frc::SmartDashboard::PutNumber("Red", detectedColor.red);
        frc::SmartDashboard::PutNumber("Green", detectedColor.green);
        frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
        frc::SmartDashboard::PutNumber("Confidence", confidence);
        frc::SmartDashboard::PutString("Detected Color", colorString);
    }