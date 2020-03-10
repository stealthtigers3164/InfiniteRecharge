#pragma once
#include <frc/DigitalInput.h>
#include <ctre/Phoenix.h>

class indexer{

    private:

        //placeholder motors one and two
        WPI_VictorSPX *vOne;
        WPI_VictorSPX *vTwo;
        //motor for roller
        frc::Spark *roller;
        //frc::DigitalInput *forwardLimitSwitch;

    public:
        bool prevSwitcher = false;
        bool switcher = false;
        int balls = 3;
        //default constructor -- do not use
        indexer();
        //placeholder constructor and args
        indexer(int pOne, int pTwo, int portRoller);
        //takes a range from -1 to 1
        void update(double power);
        //counts the amount of balls in the indexer
        int countIndex();

        void indInit();
        void indTeleOP();

};