#include "DetectorDeRequerimiento.h"

DetectorDeRequerimiento::DetectorDeRequerimiento(){
    state=false;
}

bool DetectorDeRequerimiento::isOn(){
    return state;
}
void DetectorDeRequerimiento::setOn(){
    state=true;
}
void DetectorDeRequerimiento::setOff(){
    state=false;
}