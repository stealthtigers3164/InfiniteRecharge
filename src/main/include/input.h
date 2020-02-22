#pragma once
#include <Gamepad.h>
#include <limelight.h>
#include <drive.h>
#include <color.h>
#include <Dashboard.h>

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

        bool alignment(inputChooser controls);

        Gamepad *controllerOne;
        Gamepad *controllerTwo;
        limelight *aligner;
        drive *drivechain;
        color *cspinner;
        
        static const int setpoint = 500;
        bool spinToggle = false;
        bool matchToggle = false;

};