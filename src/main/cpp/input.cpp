#include <input.h>
#include <limelight.h>
#include <drive.h>
#include <Gamepad.h>

//constructor
input::input(){
    controller = new Gamepad(1);
    aligner = new limelight();
    drivechain = new drive(1, 2, 3, 4);
}

void input::update(){
    
    //limelight alignment set to A button
    if (controller->ButtonA()){
        float adjustment = aligner->update();
        float left = controller->LeftJoystick()[1] + adjustment;
        float right = controller->RightJoystick()[1] - adjustment;
        drivechain->update(right, left);
    } else { 
        float left = controller->LeftJoystick()[1];
        float right = controller->RightJoystick()[1];
        drivechain->update(right, left);
    }
}