#include <color.h>
#include <string>
#include <rev/ColorMatch.h>
#include <rev/ColorSensorV3.h>
#include <frc/smartdashboard/SmartDashboard.h>

color::color(){
    m_colorMatcher.AddColorMatch(kBlueTarget);
    m_colorMatcher.AddColorMatch(kGreenTarget);
    m_colorMatcher.AddColorMatch(kRedTarget);
    m_colorMatcher.AddColorMatch(kYellowTarget);
    frc::SmartDashboard::PutNumber("Color", 0);
    //set motor to specific port
    motor = new frc::Spark(5);

    //init spin variables
    previousColor = 0;
    currentColor = 0;
    rotationCount = 0;
}

//reads the color output of the color sensor
void color::readColor(){
    detectedColor = m_colorSensor.GetColor();
    std::string colorString;
    double confidence = 0.0;
    matchedColor = m_colorMatcher.MatchClosestColor(detectedColor, confidence);
    //sets specific values corresponding to color for later
    if (matchedColor == kBlueTarget){
        colorString = "Blue";
        currentColor = 0;
    } else if (matchedColor == kRedTarget){
        colorString = "Red";
        currentColor = 2;
    } else if (matchedColor == kGreenTarget){
        colorString = "Green";
        currentColor = 1;
    } else if (matchedColor == kYellowTarget){
        colorString = "Yellow";
        currentColor = 3;
    } else {
        colorString = "Unknown";
    }
    //update smartdashboard
    frc::SmartDashboard::PutNumber("Red", detectedColor.red);
    frc::SmartDashboard::PutNumber("Green", detectedColor.green);
    frc::SmartDashboard::PutNumber("Blue", detectedColor.blue);
    frc::SmartDashboard::PutNumber("Confidence", confidence);
    frc::SmartDashboard::PutString("Detected Color", colorString);
}

bool color::spin(){
    motor->Set(speed);
    // spin until ~3.5 or up to 4.5 rotations
    // margin of error of 5 color slices
    if (rotationCount < targetRotations){
        readColor();
        if (currentColor != previousColor){
            rotationCount++;
        }
        previousColor = currentColor;
        return true;
    } else {
        //finish rotating
        return false;
        motor->Set(0);
    }
}

bool color::matchColor(){
    //read color replaces previous decleration of variables
    readColor();
    //receive the color match target
    gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
    //if gamedata is returned correctly
    if (gameData.length() > 0){
        motor->Set(speed);
        std::cout << gameData[0] << std::endl;
        switch (gameData[0]){
            //if target color is red
            case 'R':
                //if current color is blue
                if (matchedColor == kBlueTarget){
                    motor->Set(0);
                    return false;
                }
                return true;
                break;
            //if target color is blue
            case 'B':
                //if current color is red
                if (matchedColor == kRedTarget){
                    motor->Set(0);
                    return false;
                }
                return true;
                break;
            //if target color is yellow
            case 'Y':
                //if current color is green
                if (matchedColor == kGreenTarget){
                    motor->Set(0);
                    return false;
                }
                return true;
                break;
            //if target color is green
            case 'G':
                //if current color is yellow
                if (matchedColor ==  kYellowTarget){
                    motor->Set(0);
                    return false;
                }
                return true;
                break;
            default:
                return true;
                break;
        }
    } else {
        printf("No gamedata found!");
        return false;
    }
}

void color::resetSpin(){
    //reset spin variables
    previousColor = 0;
    currentColor = 0;
    rotationCount = 0;
    //turn off motor
    motor->Set(0);
}