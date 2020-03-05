#include <input.h>
#include <intake.h>
#include <shooter.h>
#include <indexer.h>
#include <limelight.h>
#include <drive.h>
#include <color.h>
#include <lift.h>
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
    //control picker client
    client = new controls();
    //ports may change with comp. robot
    //BL, FL, FR, BR
    // GOL:                6, 7, 9, 8
    // Winchless:          1, 2, 3, 0
    drivechain = new drive(0, 1, 2, 3);
    //limelight code
    aligner = new limelight();
    //intake motors
    //roller motor
    roller = new intake(2, 3);
    //turret and flywheel
    //turret is first port, flywheel is second port
    turret = new shooter(0, 1);
    //lift for end-game climb
    //temporary ports
    //actual ports TBD
    climb = new lift(4, 7);
    //color sensor
    cspinner = new color(5);
}

void input::update(){
    
    float* LeftStick = controllerOne->LeftJoystick();
    float* RightStick = controllerOne->RightJoystick();
    //uncomment statements below to print joystick values to riolog
    //printf("Left Joystick\n\nX:%f\nY:%f\n\n", LeftStick[0], LeftStick[1]);
    //printf("Right Joystick\n\nX:%f\nY:%f\n\n", RightStick[0], RightStick[1]);

    //limelight alignment set to A button
    if (button(client->getControl("limelight"))){
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

    //climb code
    if(button(client->getControl("lift up"))){
        climb->update(1.0f);
    } else if (button(client->getControl("lift down"))){
        climb->update(-1.0f);
    } else {
        climb->update(0.0f);
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

bool input::button(controls::keybind keybind){
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

bool input::buttonDown(controls::keybind keybind){
    switch (keybind.controller){
                case 1:
            return controllerOne->getButtonDown(controllerOne->toEnum[keybind.button]);
            break;
        case 2:
            return controllerTwo->getButtonDown(controllerTwo->toEnum[keybind.button]);
            break;
        default:
            return false;
            break;
    }
}

bool input::buttonUp(controls::keybind keybind){
    switch (keybind.controller){
                case 1:
            return controllerOne->getButtonUp(controllerOne->toEnum[keybind.button]);
            break;
        case 2:
            return controllerTwo->getButtonUp(controllerTwo->toEnum[keybind.button]);
            break;
        default:
            return false;
            break;
    }
}