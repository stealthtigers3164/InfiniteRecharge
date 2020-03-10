#include <frc/Spark.h>
#include <intake.h>

intake::intake(){
    printf("default intake constructor -- do not use");
}

intake::intake(int portAngler){
    angler = new frc::Spark(portAngler);
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
