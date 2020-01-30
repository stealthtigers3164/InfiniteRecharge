#include <input.h>
#include <limelight.h>
#include <drive.h>
#include <Gamepad.h>

//constructor
input::input(){
    controller = new Gamepad(0);
    aligner = new limelight();
    drivechain = new drive(1, 2, 3, 0);
}

void input::update(){
    
    float* LeftStick = controller->LeftJoystick();
    float* RightStick = controller->RightJoystick();
    //printf("Left Joystick\n\nX:%f\nY:%f\n\n", LeftStick[0], LeftStick[1]);
    //printf("Right Joystick\n\nX:%f\nY:%f\n\n", RightStick[0], RightStick[1]);

    //limelight alignment set to A button
    if (controller->ButtonA()){
        float adjustment = aligner->update();
        float left = LeftStick[1] + adjustment;
        float right = RightStick[1] - adjustment;
        //reversed right motors -- may need to change
        right *= -1.0f;
        drivechain->update(left, right);
    } else {
        float left = LeftStick[1];
        float right = RightStick[1];
        //reversed right motors -- may need to change
        right *= -1.0f;
        drivechain->update(left, right);
    }
}