#include <string>
#include "DetectorDeRequerimiento.cpp"
#include <thread>
#include <chrono>
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
SimuladorEntradas::~SimuladorEntradas(){

}
SimuladorEntradas::SimuladorEntradas(DetectorDeRequerimiento *sensind, std::string flnm){
    sensorinductivo=sensind;
    file.open(flnm,ios_base::in);

}
void SimuladorEntradas::actionPerformed() {
    if(!file.eof()){
        getline(file,linea);
        if(stoi(linea)){
            sensorinductivo->setOn();
        }
        else{
            sensorinductivo->setOff();
        }
    }
    else{
        file.close();
        exit(0);
    }

}


