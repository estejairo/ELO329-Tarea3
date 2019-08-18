#ifndef CONTROLADOR_H_
#define CONTROLADOR_H_

#include "SemaforoP.h"
#include <thread>
#include <chrono>
#include <exception>

class Controlador
{
private:
    SemaforoP semP;
    DetectorDeRequerimiento *boton;
public:
    Controlador(SemaforoP smp, DetectorDeRequerimiento *btn);
    ~Controlador();
    void manageTraffic();
};

#endif /* CONTROLADOR_H_ */