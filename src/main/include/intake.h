#pragma once
#include <frc/Spark.h>

class intake{

    private:

        //motor for angler
        frc::Spark *angler;

    public:

        //default constructor -- do not use
        intake();
        //assign ports to motor objects
        intake(int portAngler);
        //update angle of angler
        //limit switch??
        void angle(bool toggle);
        //toggle roller (on/off)
        void roll(bool toggle);

};