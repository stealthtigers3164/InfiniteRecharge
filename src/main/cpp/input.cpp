#include <input.h>
#include <limelight.h>
#include <drive.h>
#include <color.h>
#include <Gamepad.h>
#include <math.h>
#include <iostream>
#include <shooter.h>
#include <indexer.h>
#include <lift.h>

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
    //Dankenstein:         5, 8, 0, 1
    drivechain = new drive(5, 8, 0, 1);
    //color sensor
    cspinner = new color();
    //FlyWheel
    fly = new shooter(6);
    //indexer
    indx = new indexer(12,13,2);
    //Lift/Elevator
    //lifft = new lift();
    //intake
    intaker = new intake(3);
}

void input::update(){
    
    float* LeftStick = controllerOne->LeftJoystick();
    float* RightStick = controllerOne->RightJoystick();
    //uncomment statements below to print joystick values to riolog
    //printf("Left Joystick\n\nX:%f\nY:%f\n\n", LeftStick[0], LeftStick[1]);
    //printf("Right Joystick\n\nX:%f\nY:%f\n\n", RightStick[0], RightStick[1]);

    //limelight alignment set to A button
    if (controllerOne->ButtonA()){
        //aligner->setCamera(0);
        float adjustment = aligner->drive();
        //left and right are the Y axis (joyVector[1])
        //square for non-linear curve (smoother acceleration)
        float left = (LeftStick[1] - adjustment);
        float right = (RightStick[1] + adjustment);
        //motors flipped
        // GOL:         left *= -1;
        // Winchless:   right *= -1;
        left *= -1;
        drivechain->update(left, right);
    } else {
        //left and right are the Y axis (joyVector[1])
        //square for non-linear curve (smoother acceleration)
        //aligner->setCamera(1);
        float left = std::abs(LeftStick[1]) * LeftStick[1];
        float right = std::abs(RightStick[1]) * RightStick[1];
        //motors flipped
        // GOL:         left *= -1;
        // Winchless:   right *= -1;
        left *= -1;
        drivechain->update(left, right);
    }
    //NOT USING COLOUR WHEEL IN ORLANDO
    /*
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
    }*/ 

    //IF ANY OF THE TWO BUMPERS, ACTIVATE THE FLYWHEEL
    if(controllerTwo->RightBumper() || controllerTwo->LeftBumper()){
        fly->flyyWheel(1);
    }else{
        fly->flyyWheel(0);
    }

    
    bool leftTwo = controllerTwo->LeftTriggerPressed();
    bool rightTwo = controllerTwo->RightTriggerPressed();
    //IF left is pressed but NOT right, set both 'indexers' at 0.3
    if(leftTwo && !rightTwo){
        indx->update(0.5);
    }
    //IF NEITHER of them are pressed or BOTH are pressed, set both 'indexers' to 0
    if((!leftTwo && !rightTwo) || (leftTwo && rightTwo)){
        indx->update(0);
    }
    //IF right is pressed but not left, set both 'indexers' to -0.3
    if(!leftTwo && rightTwo){
        indx->update(-0.5);
    }

    intaker->angle(controllerTwo->LeftJoystick()[1]/2);

    //LIFT/ELEVATOR
    /*float leftOne = controllerTwo->LeftTriggerValue();
    float rightOne = controllerTwo->LeftTriggerValue();
    if(leftOne != 0.1){
        lifft->update(leftOne);
    }
    if(rightOne != 0.1){
        lifft->update(-rightOne);
    }
    if(leftOne != 0.1 && rightOne != 0.1){
        lifft->update(0);
    }*/
}