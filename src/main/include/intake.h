#pragma once
#include <frc/Spark.h>
#include <frc/DigitalInput.h>

class intake{

    private:

        //motor for angler
        frc::Spark *angler;
        //motor for roller
        frc::Spark *roller;
        //limit switch for upper limit
        frc::DigitalInput *switchUp;
        //limit switch for lower limit
        frc::DigitalInput *switchDown;

    public:

        //default constructor -- do not use
        intake();
        //assign ports to motor objects
        intake(int portAngler, int portRoller, int limitUp, int limitDown);
        //update angle of angler
        //limit switch??
        void angle(bool toggle);
        //toggle roller (on/off)
        void roll(bool toggle);
        //limit switch for the upper limit
        //returns true if arm is up
        //otherwise, returns false
        bool upperLimit();
        //limit switch for the lower limit
        //returns true if the arm is down
        //otherwise, returns false
        bool lowerLimit();

};