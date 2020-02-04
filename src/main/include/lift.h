#pragma once
#include <frc/Spark.h>

class lift{

    private:

        frc::Spark *mOne;
        frc::Spark *mTwo;

    public:

        lift();
        lift(int mOne, int mTwo);

        void update(float one, float two);

}