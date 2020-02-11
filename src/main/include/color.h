#pragma once

#include <string>
#include <frc/Spark.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DriverStation.h>
#include <rev/ColorSensorV3.h>
#include <rev/ColorMatch.h>

class color{

    public:

        color();
        void readColor();
        void spin();
        void matchColor();

    private:
        static constexpr auto i2cPort = frc::I2C::Port::kOnboard;
        rev::ColorSensorV3 m_colorSensor{i2cPort};
        rev::ColorMatch m_colorMatcher;
        //The following 4 lines are for color calibration
        static constexpr frc::Color kBlueTarget = frc::Color(0.143, 0.427, 0.429);
        static constexpr frc::Color kGreenTarget = frc::Color(0.197, 0.561, 0.240);
        static constexpr frc::Color kRedTarget = frc::Color(0.561, 0.232, 0.114);
        static constexpr frc::Color kYellowTarget = frc::Color(0.361, 0.524, 0.113);
        static constexpr frc::Color kUnknownTarget = frc::Color(0.0000, 0.0000, 0.0000);
        //color match variables
        frc::Color detectedColor;
        frc::Color matchedColor;
        //data sent from field -- which color to match to
        std::string gameData;
        //current color initiation -- allows readColor() to be void
        int currentColor;
        //motor
        frc::Spark *motor;
        //speed -- stays constant
        static constexpr double speed = 0.28;
};
    //It will be ran only once -- make constructor
    //deprecated
    /*
    void declaration(){
        m_colorMatcher.AddColorMatch(kBlueTarget);
        m_colorMatcher.AddColorMatch(kGreenTarget);
        m_colorMatcher.AddColorMatch(kRedTarget);
        m_colorMatcher.AddColorMatch(kYellowTarget);
        frc::SmartDashboard::PutNumber("Color", 0);
    }
    */

//deprecated
/*     int readColor(){
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
        }
        frc::SmartDashboard::PutNumber("Red", detectedColor.red);
        frc::SmartDashboard::PutNumber("Green", detectedColor.green);
        frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
        frc::SmartDashboard::PutNumber("Confidence", confidence);
        frc::SmartDashboard::PutString("Detected Color", colorString);
  
    } */


    //The method/function spin should not be enabled at the same time that detectColor is.

    //
    
    //deprecated
/*         int targetColor = 0;
        int previousColor = 0;
        int currentColor = 0;
        int rotationCount = 0;
        int numberOfRotation = 37;
    void spin(){
        currentColor = readColor(); //replace with current color
        previousColor = currentColor;
        motor->Set(speed);
        while(rotationCount < numberOfRotation){
            currentColor = readColor();
            if(currentColor != previousColor){
                rotationCount++;
            }
            previousColor = currentColor;
        }
        motor->SetSpeed(0);
    } */

//deprecated
/* 
    //Repeated during Periodic
    void detectColor(){
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
        //these if-else statements check target + the matched color and decides whether to rotate or not.
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
        //The following lines put in SmartDashboard/Suffleboard The String for the actual color under sensor. NOT THE ONE THAT IS BEING SENSED BY FRC.
        frc::SmartDashboard::PutNumber("Red", detectedColor.red);
        frc::SmartDashboard::PutNumber("Green", detectedColor.green);
        frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
        frc::SmartDashboard::PutNumber("Confidence", confidence);
        frc::SmartDashboard::PutString("Detected Color", colorString);
    } */

//deprecated
/*     bool act = false;
    void colorWheel(){
        if(){
            if(act){
                act = false;
            }else{
                act = true;
            }
            targetColor = 0;
            previousColor = 0;
            currentColor = 0;
            rotationCount = 0;
            numberOfRotation = 37;
            targetBlue = true;
            targetGreen = false;
            targetRed = false;
            targetYellow = false;
        }

        if(act){
        if(rotationCount < numberOfRotation){
            spin();
        }else{
            detectColor();
        }
        
        }
    } */