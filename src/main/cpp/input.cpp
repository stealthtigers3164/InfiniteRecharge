#include <input.h>
#include <limelight.h>
#include <drive.h>
#include <Gamepad.h>

//constructor
input::input(){
    //possibly add second gamepad
    //pick control scheme through smartdashboard??
    //one/two controllers -> choose through smartdashboard??
    controller = new Gamepad(0);
    aligner = new limelight();
    drivechain = new drive(1, 2, 3, 0);
}

void input::update(){
    
    float* LeftStick = controller->LeftJoystick();
    float* RightStick = controller->RightJoystick();
    //uncomment statements below to print joystick values to riolog
    //printf("Left Joystick\n\nX:%f\nY:%f\n\n", LeftStick[0], LeftStick[1]);
    //printf("Right Joystick\n\nX:%f\nY:%f\n\n", RightStick[0], RightStick[1]);

    //limelight alignment set to A button
    if (controller->ButtonA()){
        float adjustment = aligner->update();
        //left and right are the Y axis (joyVector[1])
        float left = LeftStick[1] + adjustment;
        float right = RightStick[1] - adjustment;
        //reversed right motors -- may need to change
        right *= -1.0f;
        drivechain->update(left, right);
    } else {
        //left and right are the Y axis (joyVector[1])
        float left = LeftStick[1];
        float right = RightStick[1];
        //reversed right motors -- may need to change
        right *= -1.0f;
        drivechain->update(left, right);
    }
}