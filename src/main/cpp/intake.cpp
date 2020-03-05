#include <frc/Spark.h>
#include <frc/DigitalInput.h>
#include <intake.h>

intake::intake(){
    printf("default intake constructor -- do not use");
}

intake::intake(int portAngler, int portRoller, int limitUp, int limitDown){
    angler = new frc::Spark(portAngler);
    roller = new frc::Spark(portRoller);
    switchUp = new frc::DigitalInput(limitUp);
    switchDown = new frc::DigitalInput(limitDown);
}

void intake::angle(bool toggle){
    if (toggle){
        //flip down
        angler->Set(0.5);
    } else {
        //flip up
        angler->Set(-0.5);
    }
}

void intake::roll(bool toggle){
    if (toggle){
        //roll if toggled on
        roller->Set(1.0);
    } else {
        //turn off roller if toggled off
        roller->Set(0.0);
    }
}

bool intake::upperLimit(){
    return upperLimit->get();
}

bool intake::lowerLimit(){
    return lowerLimit->get();
}