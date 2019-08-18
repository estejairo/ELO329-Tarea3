#include "SimuladorEntradas.h"
#include <chrono>

SimuladorEntradas::SimuladorEntradas(){

}

SimuladorEntradas::SimuladorEntradas(DetectorDeRequerimiento *btn,DetectorDeRequerimiento *sensind, std::string flnm){
    botonpeaton=btn;
    sensorind=sensind;
    file.open(flnm,ios_base::in);
}

void SimuladorEntradas::actionPerformed() {
    string peaton,autoind;
    if(!file.eof()){
        getline(file,linea);
        peaton=linea.substr(0,linea.find("\t"));
        autoind=linea.substr(linea.find("\t"));
        if(stoi(peaton)){
            botonpeaton->setOn();
        }
        if(stoi(autoind)){
            sensorind->setOn();
        }

    }
    else{
        file.close();
        exit(0);
    }

}


