#include "SimuladorEntradas.h"

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


