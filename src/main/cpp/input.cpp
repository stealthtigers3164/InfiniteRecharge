#include <input.h>
#include <limelight.h>
#include <drive.h>
#include <varG.h>
#include <Gamepad.h>
//constructor
input::input(){
    controller = new Gamepad(0);
    aligner = new limelight();
    drivechain = new drive(3, 2, 1, 0);
}
extern bool buttonAWPP; 
void input::update(){
    
    float* LeftStick = controller->LeftJoystick();
    float* RightStick = controller->RightJoystick();
    //printf("Left Joystick\n\nX:%f\nY:%f\n\n", LeftStick[0], LeftStick[1]);
    //printf("Right Joystick\n\nX:%f\nY:%f\n\n", RightStick[0], RightStick[1]);

    //limelight alignment set to A button
    if (controller->ButtonA()){
        float adjustment = aligner->update();
        float left = LeftStick[1] - adjustment;
        float right = RightStick[1] + adjustment;
        //reversed right motors
        right *= -1.0f;
        drivechain->update(left, right);
    } else {
        float left = LeftStick[1];
        float right = RightStick[1];
        //reversed right motors
        right *= -1.0f;
        drivechain->update(left, right);
    }
    /*if (controller->ButtonX()){
        //cspinner->spin();
        //buttonCheck(true);

    }*/
    if (controller->ButtonB()){
        buttonAWPP = true;
    }
    /*if (controller->ButtonX()){
        cspinner->matchColor();
    }*/
}