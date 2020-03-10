#include <frc/Spark.h>
#include <intake.h>

intake::intake(){
    printf("default intake constructor -- do not use");
}

intake::intake(int portAngler, int portRoller){
    roller = new frc::Spark(portRoller);
}

void intake::angle(bool toggle){
    if (toggle){
        //flip down
        angler->Set(1.0);
    } else {
        //flip up
        angler->Set(-1.0);
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