#include <lift.h>
#include <frc/Spark.h>
#include <iostream>

//default constructor
//do not use
lift::lift(){
    printf("Please assign ports to the lift motors!");
}

//declare motors with port arguments
lift::lift(int portOne, int portTwo){
    motorOne = new frc::Spark(portOne);
    motorTwo = new frc::Spark(portTwo);
}


//set motor power to power argument
void lift::update(float power){
    motorOne->Set(power);
    motorTwo->Set(power);
}