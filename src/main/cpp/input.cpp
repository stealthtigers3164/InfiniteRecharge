#include <input.h>
#include <limelight.h>
#include <drive.h>
#include <color.h>
#include <Gamepad.h>
#include <math.h>

//constructor
input::input(){
    //possibly add second gamepad
    //pick control scheme through smartdashboard??
    //one/two controllers -> choose through smartdashboard??
    controllerOne = new Gamepad(0);
    controllerTwo = new Gamepad(1);
    //limelight code
    aligner = new limelight();
    //ports may change with comp. robot
    //BL, FL, FR, BR
    // GOL:                6, 7, 9, 8
    // Winchless:          1, 2, 3, 0
    drivechain = new drive(1, 2, 3, 0);
    //color sensor
    cspinner = new color();
}

void input::update(){
    
    float* LeftStick = controllerOne->LeftJoystick();
    float* RightStick = controllerOne->RightJoystick();
    //uncomment statements below to print joystick values to riolog
    //printf("Left Joystick\n\nX:%f\nY:%f\n\n", LeftStick[0], LeftStick[1]);
    //printf("Right Joystick\n\nX:%f\nY:%f\n\n", RightStick[0], RightStick[1]);

    //limelight alignment set to A button
    if (controllerOne->ButtonA()){
        float adjustment = aligner->update();
        //left and right are the Y axis (joyVector[1])
        //square for non-linear curve (smoother acceleration)
        float left = std::pow(LeftStick[1], 2) + adjustment;
        float right = std::pow(RightStick[1], 2) - adjustment;
        //motors flipped
        // GOL:         left *= -1;
        // Winchless:   right *= -1;
        right *= -1;
        drivechain->update(left, right);
    } else {
        //left and right are the Y axis (joyVector[1])
        //square for non-linear curve (smoother acceleration)
        float left = std::pow(LeftStick[1], 2);
        float right = std::pow(RightStick[1], 2);
        //motors flipped
        // GOL:         left *= -1;
        // Winchless:   right *= -1;
        right *= -1;
        drivechain->update(left, right);
    }

    if (controllerOne->ButtonX()){
        cspinner->spin();
    }
    if (controllerOne->ButtonX()){
        cspinner->matchColor();
    }
}