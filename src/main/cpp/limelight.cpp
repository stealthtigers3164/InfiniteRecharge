#include <frc/smartdashboard/Smartdashboard.h>
#include <networktables/Networktable.h>
#include <networktables/NetworkTableInstance.h>

//constructor
limelight::limelight(){
    std::shared_ptr<NetworkTable> table = nt::NetworkTableInstance::GetDefault().GetTable("limelight");
    KpAim = -0.1f;
    KpDistance = -0.1f;
    main_aim_command = 0.05f;
}

//update table values
float limelight::update(){
    tx = table->GetNumber("tx");
    ty = table->GetNumber("ty");

    //calculations -- TODO

    //return final power as output -- called only by input the file
    //input has if else that will either align or just use joystick
}