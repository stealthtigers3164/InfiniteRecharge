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
#include <Gamepad.h>

#include "Robot.h"
#include "rev/ColorSensorV3.h"
#include "rev/ColorMatch.h"
#include <frc/DriverStation.h>
#include <varG.h>

    static constexpr auto i2cPort = frc::I2C::Port::kOnboard;
    rev::ColorSensorV3 m_colorSensor{i2cPort};
    rev::ColorMatch m_colorMatcher;
    //The following 4 lines are for colour calibration
    static constexpr frc::Color kBlueTarget = frc::Color(0.143, 0.427, 0.429);
    static constexpr frc::Color kGreenTarget = frc::Color(0.197, 0.561, 0.240);
    static constexpr frc::Color kRedTarget = frc::Color(0.561, 0.232, 0.114);
    static constexpr frc::Color kYellowTarget = frc::Color(0.361, 0.524, 0.113);
    static constexpr frc::Color kUnknownTarget = frc::Color(0.0000, 0.0000, 0.0000);
    frc::Spark *motor = new frc::Spark(5); 
    //The following 4 lines are the booleans that are activated with the switch break
    bool targetGreen = false;
    bool targetRed = false;
    bool targetBlue = false;
    bool targetYellow = false;
    std::string gameData;
   
   //It will be ran only once
    void declaration(){
        m_colorMatcher.AddColorMatch(kBlueTarget);
        m_colorMatcher.AddColorMatch(kGreenTarget);
        m_colorMatcher.AddColorMatch(kRedTarget);
        m_colorMatcher.AddColorMatch(kYellowTarget);
        frc::SmartDashboard::PutNumber("Colour", 0);
    }   
  
    

    double speed = 0.28;

    int readColour(){
        frc::Color detectedColor = m_colorSensor.GetColor();
        std::string colorString;
        double confidence = 0.0;
        frc::Color matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);
        if (matchedColor == kBlueTarget) {
            colorString = "Blue";
            return(0);
        } else if (matchedColor == kRedTarget) {
            colorString = "Red";
            return(2);
        } else if (matchedColor == kGreenTarget) {
            colorString = "Green";
            return(1);
        }
        else if (matchedColor == kYellowTarget) {
            colorString = "Yellow";
            return(3);
        } else {
            colorString = "Unknown";
            return -1;
        }
        frc::SmartDashboard::PutNumber("Red", detectedColor.red);
        frc::SmartDashboard::PutNumber("Green", detectedColor.green);
        frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
        frc::SmartDashboard::PutNumber("Confidence", confidence);
        frc::SmartDashboard::PutString("Detected Color", colorString);
  
    }
    //The method/function spin should not be enabled at the same time that detectColour is.

    //
    
        int targetColour = 0;
        int previousColour = 0;
        int currentColour = 0;
        int rotationCount = 0;
        int numberOfRotation = 37;
    void spin(){
        currentColour = readColour(); //replace with current colour
        previousColour = currentColour;
        motor->Set(speed);
        while(rotationCount < numberOfRotation){
            currentColour = readColour();
            if(currentColour != previousColour){
                rotationCount++;
            }
            previousColour = currentColour;
        }
        motor->SetSpeed(0);
    }
    //Repeated during Periodic
     void detectColour(){
        frc::Color detectedColor = m_colorSensor.GetColor();
        std::string colorString;
        double confidence = 0.0;
        frc::Color matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);
        motor->Set(speed);
        //GetMessage
        gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
        //If gamedata > 0 (received correctly) then go to switch-break then assign booleans to targets and then proceed.
        if(gameData.length() > 0){
            switch (gameData[0]){
                case 'B' :
                    targetBlue = false;
                    targetGreen = false;
                    targetRed = true;
                    targetYellow = false;
                    break;
                case 'G' :
                    targetBlue = false;
                    targetGreen = false;
                    targetRed = false;
                    targetYellow = true;
                    break;
                case 'R' :
                    targetBlue = true;
                    targetGreen = false;
                    targetRed = false;
                    targetYellow = false;
                    break;
                case 'Y' :
                    targetBlue = false;
                    targetGreen = true;
                    targetRed = false;
                    targetYellow = false;
                    break;
                default :
                    break;
            }
        }else{
            targetBlue = false;
            targetGreen = false;
            targetRed = false;
            targetYellow = false;
        }
        //these if-else statements check target + the matched colour and decides whether to rotate or not.
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
        //The following lines put in SmartDashboard/Suffleboard The String for the actual colour under sensor. NOT THE ONE THAT IS BEING SENSED BY FRC.
        frc::SmartDashboard::PutNumber("Red", detectedColor.red);
        frc::SmartDashboard::PutNumber("Green", detectedColor.green);
        frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
        frc::SmartDashboard::PutNumber("Confidence", confidence);
        frc::SmartDashboard::PutString("Detected Color", colorString);
    }
extern bool buttonAWPP; 
    void buttonCheck(){
            targetColour = 0;
            previousColour = 0;
            currentColour = 0;
            rotationCount = 0;
            numberOfRotation = 37;
            targetBlue = true;
            targetGreen = false;
            targetRed = false;
            targetYellow = false;
            buttonAWPP = true;
    }
    void colourWheel(){
        if(buttonAWPP == true ){
        if( rotationCount < numberOfRotation){
            spin();
        }else{
            detectColour();
        }
        }
    }