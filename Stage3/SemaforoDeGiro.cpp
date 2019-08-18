////////////////////////////////////////////////////////////////
//
//  El siguiente codigo implementa un semaforo de 2 luces, para representar 
//  un semaforo peatonal. Incluye métodos para cambio de luz,
//  para solicitar el tiempo de encendido y para imprimir el
//  estado actual del semaforo. 
//
////////////////////////////////////////////////////////////////
#include "SemaforoDeGiro.h"

class SemaforoDeGiro
{
private:
    int greenT,blinkT;
    bool red,green;
    friend std::ostream& operator<<(std::ostream&, const SemaforoDeGiro&);
public:
    SemaforoDeGiro();
    SemaforoDeGiro(int greenTime, int blinkingTime);
    ~SemaforoDeGiro();
    void turnRedLightOn();
    void turnGreenLightOn();
    void turnGreenLightOff();
    int getGreenLightTime();
    int getBlinkingTime();

};
SemaforoDeGiro::SemaforoDeGiro(){

}

SemaforoDeGiro::SemaforoDeGiro(int greenTime, int blinkingTime)
{
    red=true;
    green=false;
    greenT=greenTime;
    blinkT=blinkingTime;
}

SemaforoDeGiro::~SemaforoDeGiro()
{
}

void SemaforoDeGiro::turnRedLightOn(){
    red=true;
    green=false;

}

void SemaforoDeGiro::turnGreenLightOn(){
    green=true;
    red=false;
}

void SemaforoDeGiro::turnGreenLightOff(){
    green=false;
}

int SemaforoDeGiro::getGreenLightTime(){
    return greenT;
}
int SemaforoDeGiro::getBlinkingTime(){
    return blinkT;
}

std::ostream& operator<<(std::ostream& o, const SemaforoDeGiro& sem){
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
