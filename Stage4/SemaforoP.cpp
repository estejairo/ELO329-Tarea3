////////////////////////////////////////////////////////////////
//
//  El siguiente codigo implementa un semaforo de 2 luces, para representar 
//  un semaforo peatonal. Incluye métodos para cambio de luz,
//  para solicitar el tiempo de encendido y para imprimir el
//  estado actual del semaforo.
//
////////////////////////////////////////////////////////////////
#include "SemaforoP.h"

SemaforoP::SemaforoP(){

}

SemaforoP::SemaforoP(int greenTime, int blinkingTime)
{
    red=true;
    greenT=greenTime;
    blinkT=blinkingTime;
}

SemaforoP::~SemaforoP()
{
}

void SemaforoP::turnRedLightOn(){
    red=true;
    green=false;

}

void SemaforoP::turnGreenLightOn(){
    green=true;
    red=false;
}

void SemaforoP::turnGreenLightOff(){
    green=false;
}

int SemaforoP::getGreenLightTime(){
    return greenT;
}

int SemaforoP::getBlinkingTime(){
    return blinkT;
}

std::ostream& operator<<(std::ostream& o, const SemaforoP& sem){
    if(sem.green){
        return o << "V";
    }
    else if(sem.red){
        return o << "R";
    }
    else{
        return o << "P";
    }
}
