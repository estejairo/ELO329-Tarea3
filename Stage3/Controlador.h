#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

#include "SemaforoDeGiro.h"
#include "DetectorDeRequerimiento.h"


class Controlador
{
private:
    SemaforoDeGiro semg;
    DetectorDeRequerimiento *sensorinductivo;
public:
    Controlador(SemaforoDeGiro smg, DetectorDeRequerimiento *sensind);
    void manageTraffic();
};

#endif /* CONTROLADOR_H_ */