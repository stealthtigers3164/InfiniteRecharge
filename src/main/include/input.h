#pragma once
#include <Gamepad.h>
#include <limelight.h>
#include <drive.h>
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

        Gamepad *controllerOne;
        Gamepad *controllerTwo;
        limelight *aligner;
        drive *drivechain;
        color *cspinner;
        controls *client;
        
        static const int setpoint = 500;
        bool spinToggle = false;
        bool matchToggle = false;

};