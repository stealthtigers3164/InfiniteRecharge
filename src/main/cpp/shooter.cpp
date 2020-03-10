#include <shooter.h>
#include <ctre/Phoenix.h>
#include <cmath>

shooter::shooter(){
    printf("default shooter constructor -- do not use");
}

shooter::shooter(int pFlywheel){
    //mTurret = new TalonSRX(pTurret);
    mFlywheel = new TalonSRX(pFlywheel);
}

void shooter::updateTurret(float power){
    //mTurret->Set(ControlMode::PercentOutput, power);
    mFlywheel->Set(ControlMode::PercentOutput, 1);
}

void shooter::updateFlywheel(float setpoint){
    //error = rpm setpoint - current rpm
    float error = setpoint - rpm();
    //change the float to change gain -- calibration
    tbhPow += 0.1 * error;
    //power clamp function
    if (tbhPow > 1) {
        tbhPow = 1;
    } else if (tbhPow < 0){
        tbhPow = 0;
    }
    //zero crossing
    if (std::signbit(error) != std::signbit(previousError)){
        //take back half algorithm
        //correct syntax, do not change
        tbhPow = previousError = 0.5 * (tbhPow + tbh);
        previousError = error;
    }
    //set power to tbh algorithm result
    mFlywheel->Set(ControlMode::PercentOutput, tbhPow);
}

void shooter::flyWheel(float power){
    mFlywheel->Set(ControlMode::PercentOutput, power);
}

//returns the rpm of the flywheel motor
float shooter::rpm(){
    //ticks per 100 milliseconds
    float rpm = mFlywheel->GetSelectedSensorVelocity();
    //1000 ms / 1 sec -- ms to sec conversion
    //60 sec / 1 min -- sec to min conversion
    //1 rotation / 4096 ticks -- ticks to rotations conversion
    rpm *= (1000 * 60) / 4096;
    return rpm;
}