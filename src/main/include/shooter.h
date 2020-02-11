#pragma once
#include <ctre/Phoenix.h>

class shooter{

    private:

        TalonSRX *mTurret;
        TalonSRX *mFlywheel;

    public:

        shooter();
        shooter(int pTurret, int pFlywheel);
        void updateTurret(float power);
        void updateFlywheel(float power);

};