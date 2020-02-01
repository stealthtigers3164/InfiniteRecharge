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
    controllerOne = new Gamepad(0);
    controllerTwo = new Gamepad(1);
    aligner = new limelight();
    //ports may change with comp. robot
    //BL, FL, FR, BR
    drivechain = new drive(1, 2, 3, 0);
}

bool input::foo(){
    return true;
}

bool (input::*lime)(){ input::foo };

void assignButton(bool (*func)(), Gamepad::controller button, Gamepad *controller){
    switch (button){
        case Gamepad::controller::A:
            func = controller->ButtonA;
            break;
        case Gamepad::controller::B:
            func = controller->ButtonB;
            break;
        case Gamepad::controller::X:
            func = controller->ButtonX;
            break;
        case Gamepad::controller::Y:
            func = controller->ButtonY;
            break;
        case Gamepad::controller::LBUMPER:
            func = controller->LeftBumper;
            break;
        case Gamepad::controller::RBUMPER:
            func = controller->RightBumper;
            break;
        case Gamepad::controller::BACK:
            func = controller->ButtonBack;
            break;
        case Gamepad::controller::START:
            func = controller->ButtonBack;
            break;
        case Gamepad::controller::bLJOY:
            func = controller->ButtonLeftJoy;
            break;
        case Gamepad::controller::bRJOY:
            func = controller->ButtonRightJoy;
            break;
        default:
            break;
    }
}

void input::update(){
    
    float* LeftStick = controllerOne->LeftJoystick();
    float* RightStick = controllerOne->RightJoystick();
    //uncomment statements below to print joystick values to riolog
    //printf("Left Joystick\n\nX:%f\nY:%f\n\n", LeftStick[0], LeftStick[1]);
    //printf("Right Joystick\n\nX:%f\nY:%f\n\n", RightStick[0], RightStick[1]);

    //limelight alignment set to A button
    if (controllerOne->ButtonX()){
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