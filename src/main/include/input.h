#pragma once
#include <Gamepad.h>
#include <limelight.h>
#include <drive.h>

//input class
//detects input from controllers using the gamepad wrapper

//TO DO:
//create control scheme selector
//  (probably in seperate smartdashboard class)
// This is the colour wheel button code

class input{

    public:

        input();
        void update();

    private:

        Gamepad *controller;
        limelight *aligner;
        drive *drivechain;

};