//the smart dashboard, testing by Lucas  
#include <frc/smartdashboard/SmartDashbaord.h>


void SmartDashboard()
{
    frc::SmartDashboard::PutNumber("Red", detectedColor.Red);
    frc::SmartDashboard::PutNumber("Green", detectedColor.Green);
    frc::SmartDashboard::PutNumber("Blue", detectedColor.Blue);
    frc::SmartDashboard::PutNumber("Yellow", detectedColor.Yellow);
    frc::SmartDashboard::PutString("Confidence", confidence);
    frc::SmartDashboard::PutString("Detected Color", colorString);
}

