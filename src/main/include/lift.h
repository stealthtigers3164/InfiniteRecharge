#pragma once

#include <frc/Spark.h>

class lift{

    private:

        //initialize motor pointer objects
        frc::Spark *motorOne;
        frc::Spark *motorTwo;

    public:

        //default constructor -- do not use
        lift();
        lift(int portOne, int portTwo);
        void update(float power);

};