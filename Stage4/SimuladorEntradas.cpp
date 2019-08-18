#include <string>
#include "DetectorDeRequerimiento.cpp"
#include <thread>
#include <chrono>
#include "Listener.h"
#include <fstream>
using namespace std;

class SimuladorEntradas: public Listener{

private:
    DetectorDeRequerimiento *sensorind;
    DetectorDeRequerimiento *botonpeaton;
    string filename;
    string linea;
    ifstream file;
public:
    SimuladorEntradas();
    SimuladorEntradas(DetectorDeRequerimiento *btn,DetectorDeRequerimiento *sensind, std::string flnm);
    void actionPerformed();
};
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
            cout<<"BOTON ON"<<peaton<<endl;
            botonpeaton->setOn();
        }
        if(stoi(autoind)){
            cout<<"SENSOR ON"<<autoind<<endl;
            sensorind->setOn();
        }

    }
    else{
        file.close();
        exit(0);
    }

}


