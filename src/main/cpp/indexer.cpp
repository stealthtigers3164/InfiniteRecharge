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
}

//takes a range from -1 to 1
//placeholer update funtion
//incriment indexer by one -- TODO
void indexer::update(float power){
    vOne->Set(power);
    vTwo->Set(power);
}