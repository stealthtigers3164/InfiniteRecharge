#pragma once
#include <ctre/Phoenix.h>

class shooter{

    private:

        TalonSRX *mTurret;
        TalonSRX *mFlywheel;

        //output power for the take back half algorithm
        //power of the turret flywheel
        float tbhPow;
        //previous error
        float previousError;
        //tbh variable
        float tbh;


    public:

        //default constructor -- do not use
        shooter();
        //constructor to define motor ports
        shooter(int pFlywheel);
        //set turret power to rotate turret
        //will not rotate if limitswitch is pressed -- todo
        void updateTurret(float power);
        //spin flywheel
        //prevent shooting if flywheel is not up to rpm -- todo
        void updateFlywheel(float setpoint);
        //returns rpm as a float
        float rpm();
        //set the flywheel to the specified power
        void flyWheel(float power);

};