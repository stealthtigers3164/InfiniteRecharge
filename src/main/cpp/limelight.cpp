#include <iostream>
#include <frc/smartdashboard/Smartdashboard.h>
#include <networktables/Networktable.h>
#include <networktables/NetworkTableInstance.h>
#include <limelight.h>

//constructor
limelight::limelight(){
    std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    KpAim = -0.1f;
    KpDistance = -0.1f;
    main_aim_command = 0.05f;
}

//update table values
float limelight::drive(){
    if (table == NULL) {
        table =  nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    }
    //update limelight valuse
    table->GetNumber("tx", tx);
    table->GetNumber("ty", ty);
    table->GetNumber("tv", tv);
    float heading_error = -tx;
    float distance_error = -ty;
    float steering_adjust = 0.0f;

    //tx = ((std::abs(tx)/tx) * std::sqrt((std::abs(tx)/tx)*tx));
    //ty = ((std::abs(ty)/ty) * std::sqrt((std::abs(ty)/ty)*ty));

    

    //horizontal calculations
    //adjust weights for calibration
    if (tx > 1.0){
        steering_adjust = KpAim * heading_error - main_aim_command;
    } else if (tx < 1.0){
        steering_adjust = KpAim * heading_error + main_aim_command;
    }


    //distance calculations
    float distance_adjust = KpDistance * distance_error;

    //return final power as output -- called only by input the file
    //input has if else that will either align or just use joystick
    return steering_adjust + distance_adjust;
}
/*
float limelight::turret(){
    if (table == NULL) {
        table =  nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    }
    //udate limelight values
    table->GetNumber("tx", tx);

    float heading_error = -tx;
    float steering_adjust = 0.0f;

    if (tx > 1.0){
        steering_adjust = KpAim * heading_error - main_aim_command;
    } else if (tx < 1.0){
        steering_adjust = KpAim * heading_error + main_aim_command;
    }

    return steering_adjust;
}*/