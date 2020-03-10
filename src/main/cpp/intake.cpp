#include <frc/Spark.h>
#include <intake.h>

intake::intake(){
    printf("default intake constructor -- do not use");
}

intake::intake(int portAngler){
    angler = new frc::Spark(portAngler);
}

void intake::angle(float toggle){
    angler->Set(toggle);
}
