#include <input.h>
#include <limelight.h>
#include <drive.h>
#include <Gamepad.h>
#include <math.h>

//constructor
input::input(){
    //possibly add second gamepad
    //pick control scheme through smartdashboard??
    //one/two controllers -> choose through smartdashboard??
    controller = new Gamepad(0);
    aligner = new limelight();
    //ports may change with comp. robot
    //BL, FL, FR, BR
    drivechain = new drive(3, 2, 1, 0);
}

void input::update(){
    
    float* LeftStick = controller->LeftJoystick();
    float* RightStick = controller->RightJoystick();
    //uncomment statements below to print joystick values to riolog
    //printf("Left Joystick\n\nX:%f\nY:%f\n\n", LeftStick[0], LeftStick[1]);
    //printf("Right Joystick\n\nX:%f\nY:%f\n\n", RightStick[0], RightStick[1]);

    //limelight alignment set to A button
    if (controller->ButtonX()){
        float adjustment = aligner->update();
        //left and right are the Y axis (joyVector[1])
        //square for non-linear curve (smoother acceleration)
        float left = std::pow(LeftStick[1], 2) + adjustment;
        float right = std::pow(RightStick[1], 2) - adjustment;
        //reversed right motors
        right *= -1.0f;
        drivechain->update(left, right);
    } else {
        //left and right are the Y axis (joyVector[1])
        //square for non-linear curve (smoother acceleration)
        float left = std::pow(LeftStick[1], 2);
        float right = std::pow(RightStick[1], 2);
        //reversed right motors
        right *= -1.0f;
        drivechain->update(left, right);
    }

    /*if(controller->ButtonA()){
        
    }*/
}