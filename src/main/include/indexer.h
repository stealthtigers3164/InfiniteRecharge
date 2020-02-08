#pragma once
#include <frc/Victor.h>

class indexer{

    private:

        //placeholder motors one and two
        frc::Victor *vOne;
        frc::Victor *vTwo;

    public:

        //default constructor -- do not use
        indexer();
        //placeholder constructor and args
        indexer(int pOne, int pTwo);
        //takes a range from -1 to 1
        void update(float power);

};