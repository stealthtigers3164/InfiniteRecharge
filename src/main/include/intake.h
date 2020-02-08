#pragma once
#include <frc/Spark.h>

class intake{

    private:

        //motor for angler
        frc::Spark *angler;
        //motor for roller
        frc::Spark *roller;

    public:

        //default constructor -- do not use
        intake();
        //assign ports to motor objects
        intake(int portAngler, int portRoller);
        //update angle of angler
        //limit switch??
        void angle(bool toggle);
        //toggle roller (on/off)
        void roll(bool toggle);

};