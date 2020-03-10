#include <indexer.h>
#include <ctre/Phoenix.h>
#include <frc/Spark.h>

//default constructor -- do not use
indexer::indexer(){
    printf("default indexer constructor -- do not use");
}

//placeholder constructor and args
//SET THEM TO WPI_VICTORSPX, SET ROLLER TO SPARK
indexer::indexer(int pOne, int pTwo, int portRoller){
    vOne = new WPI_VictorSPX(pOne);
    vTwo = new WPI_VictorSPX(pTwo);
    roller = new frc::Spark(portRoller);
    //forwardLimitSwitch = new frc::DigitalInput(1);
}
//takes a range from -1 to 1
//placeholer update funtion
//incriment indexer by one -- TODO
void indexer::update(double power){
    vOne->Set(-power);
    vTwo->Set(power);
    roller->Set(power);
}

//returns the current number of balls in the indexer as counted by the limit switch
int indexer::countIndex(){
    if((prevSwitcher != switcher) && switcher){ 
        balls++;
    }
    prevSwitcher = switcher;
    return(balls);
}