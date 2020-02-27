#include <frc/Victor.h>
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

//returns the current number of balls in the indexer as counted by the limit switch
int indexer::countIndex(){
    if((prevSwitcher != switcher) && switcher){ 
        balls++;
    }
    prevSwitcher = switcher;
    /* added this uhhhhhhhh
    switcher = (button what?) >> (gets whatever buttons value based on what is operating it )
    if (limit switch >> get()) 
    output = fmin(output, 0)
    Lol i have a link we can refer too 
    */
}