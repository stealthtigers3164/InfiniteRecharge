#include <frc/Victor.h>
#include <frc/DigitalInput.h>
#include <indexer.h>

//default constructor -- do not use
indexer::indexer(){
    printf("default indexer constructor -- do not use");
}

//placeholder constructor and args
indexer::indexer(int pOne, int pTwo){
    vOne = new frc::Victor(pOne);
    vTwo = new frc::Victor(pTwo);
    forwardLimitSwitch = new frc::DigitalInput(1);
}

//takes a range from -1 to 1
//placeholer update funtion
//incriment indexer by one -- TODO
void indexer::update(float power){
    vOne->Set(power);
    vTwo->Set(power);
}

int indexer::countIndex(){
    if((prevSwitcher != switcher) && switcher){ 
        balls++;
    }
    prevSwitcher = switcher;
}