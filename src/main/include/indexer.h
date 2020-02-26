#pragma once
#include <frc/Victor.h>

class indexer{

    private:

        //placeholder motors one and two
        frc::Victor *vOne;
        frc::Victor *vTwo;

    public:
        bool prevSwitcher = false;
        bool switcher = false;
        int balls = 3;
        //default constructor -- do not use
        indexer();
        //placeholder constructor and args
        indexer(int pOne, int pTwo);
        //takes a range from -1 to 1
        void update(float power);
        //counts the amount of balls in the indexer
        int countIndex();

};