#pragma once
#include <frc/Spark.h>

class intake{

    private:

        //motor for roller
        frc::Spark *roller;

    public:

        //default constructor -- do not use
        intake();
        //assign ports to motor objects
        intake(int portRoller);
        //toggle roller (on/off)
        void roll(bool toggle);

};