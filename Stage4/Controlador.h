#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

#include "SemaforoDeGiro.h"
#include "SemaforoP.h"
#include "StreetTrafficLight.h"
#include "DetectorDeRequerimiento.h"

class Controlador
{
private:
    SemaforoDeGiro semg2,semg4;
    DetectorDeRequerimiento *sensorinductivo,*botonpeaton;
    SemaforoP semp1norteA,sempsportingB;
    StreetTrafficLight sem5,sem3,sem1;
    int state = 1;
    int counter = 0;
    int currentGreenTime=1;
    int currentYellowTime=1;
public:
    Controlador(SemaforoP semaforopA, SemaforoP semaforopB, SemaforoDeGiro semaforog2, SemaforoDeGiro semaforog4, DetectorDeRequerimiento *botont, DetectorDeRequerimiento *sensorInd, StreetTrafficLight semaforo1, StreetTrafficLight semaforo3, StreetTrafficLight semaforo5);
    ~Controlador();
    void manageTraffic();
};

#endif /* CONTROLADOR_H_ */