#ifndef SIMULADORENTRADAS_H_
#define SIMULADORENTRADAS_H_

#include <string>
#include "DetectorDeRequerimiento.h"
#include <thread>
#include "Listener.h"

#include <fstream>

using namespace std;

class SimuladorEntradas: public Listener{

private:
    DetectorDeRequerimiento *botoncito;
    DetectorDeRequerimiento *boton;
    string filename;
    string linea;
    ifstream file;
public:
    SimuladorEntradas();
    SimuladorEntradas(DetectorDeRequerimiento *btn, string flnm);
    void actionPerformed();
    void def_atributos(DetectorDeRequerimiento *btn,string flnm);
};

#endif /* SIMULADORENTRADAS_H_ */