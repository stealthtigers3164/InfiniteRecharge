#pragma once
#include <Gamepad.h>
#include <limelight.h>
#include <drive.h>
#include <lift.h>
#include <color.h>
#include <controls.h>

//input class
//detects input from controllers using the gamepad wrapper

//TO DO:
//create control scheme selector
//  (probably in seperate smartdashboard class)

class input{

    public:

        input();
        void update();

    private:

        bool button(controls::keybind keybind);
        bool buttonDown(controls::keybind keybind);
        bool buttonUp(controls::keybind keybind);

        Gamepad* controllerOne;
        Gamepad* controllerTwo;
        controls*client;
        drive* drivechain;
        limelight* aligner;
        intake* roller;
        shooter* turret;
        lift* climb;
        color* cspinner;
        
        
        static const int setpoint = 500;
        bool spinToggle = false;
        bool matchToggle = false;

};