#ifndef SIMULADORENTRADAS_H_
#define SIMULADORENTRADAS_H_

#include <string>
#include "DetectorDeRequerimiento.h"
#include "SimuladorEntradas.h"
#include <thread>
#include "Listener.h"
#include <fstream>
using namespace std;

class SimuladorEntradas: public Listener{

private:
    DetectorDeRequerimiento *sensorinductivo;
    string filename;
    string linea;
    ifstream file;
public:
    ~SimuladorEntradas();
    SimuladorEntradas(DetectorDeRequerimiento *sensind, std::string flnm);
    void actionPerformed();
};

#endif /* SIMULADORENTRADAS_H_ */