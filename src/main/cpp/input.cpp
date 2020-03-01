#include <input.h>
#include <limelight.h>
#include <drive.h>
#include <color.h>
#include <Gamepad.h>
#include <controls.h>
#include <math.h>
#include <iostream>
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
    client = new controls();
}

void input::update(){
    
    float* LeftStick = controllerOne->LeftJoystick();
    float* RightStick = controllerOne->RightJoystick();
    //uncomment statements below to print joystick values to riolog
    //printf("Left Joystick\n\nX:%f\nY:%f\n\n", LeftStick[0], LeftStick[1]);
    //printf("Right Joystick\n\nX:%f\nY:%f\n\n", RightStick[0], RightStick[1]);

    //limelight alignment set to A button
    if (alignment(client->getControl("limelight"))){
        float adjustment = aligner->drive();
        //left and right are the Y axis (joyVector[1])
        //square for non-linear curve (smoother acceleration)
        float left = ((std::abs(LeftStick[1])/LeftStick[1]) * std::pow(LeftStick[1], 2)) + adjustment;
        float right = ((std::abs(RightStick[1])/RightStick[1]) * std::pow(RightStick[1], 2)) - adjustment;
        //motors flipped
        // GOL:         left *= -1;
        // Winchless:   right *= -1;
        right *= -1;
        drivechain->update(left, right);
    } else {
        //left and right are the Y axis (joyVector[1])
        //square for non-linear curve (smoother acceleration)
        float left = (std::abs(LeftStick[1])/LeftStick[1]) * std::pow(LeftStick[1], 2);
        float right = (std::abs(RightStick[1])/RightStick[1]) * std::pow(RightStick[1], 2);
        //motors flipped
        // GOL:         left *= -1;
        // Winchless:   right *= -1;
        right *= -1;
        drivechain->update(left, right);
    }

    if (controllerOne->getButtonDown(Gamepad::controller::X)){
        spinToggle = !spinToggle;
    }
    if (spinToggle){
        spinToggle = cspinner->spin();
    } else {
        cspinner->resetSpin();
    }

    if (controllerOne->getButtonDown(Gamepad::controller::Y)){
        matchToggle = !matchToggle;
    }
    if (matchToggle){
        matchToggle = cspinner->matchColor();
    }

    //pseudo code
    /*

    if (button down){
        limelight::turret();
    } else {
        float pow;
        if (button for left){
            pow -= 0.5f;
        }
        if (button for right){
            pow += 0.5f;
        }
        shooter::updateTurret(pow);
    }

    if (button down){
        //change setpoint to desired rpm
        shooter::updateFlywheel(setpoint);
        if (rpm == setpoint){
            //shoot one ball
            indexer::shoot();
        } else {
            //set flywheel to zero speed
            shooter::updateFlywheel(0);
        }
    }

    */
}

bool input::alignment(controls::keybind keybind){
    switch (keybind.controller){
        case 1:
            return controllerOne->button(controllerOne->toEnum[keybind.button]);
            break;
        case 2:
            return controllerTwo->button(controllerTwo->toEnum[keybind.button]);
            break;
        default:
            return false;
            break;
    }
}