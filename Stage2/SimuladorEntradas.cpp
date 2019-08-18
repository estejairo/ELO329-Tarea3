#include <string>
#include "DetectorDeRequerimiento.cpp"
#include <thread>
#include <chrono>
#include "Listener.h"
#include <fstream>
using namespace std;

class SimuladorEntradas: public Listener{

private:
    DetectorDeRequerimiento botoncito;
    DetectorDeRequerimiento boton;
    string filename;
    string linea;
    ifstream file;
public:
    SimuladorEntradas();
    SimuladorEntradas(DetectorDeRequerimiento btn, std::string flnm);
    void actionPerformed();
    void def_atributos(DetectorDeRequerimiento btn,std::string flnm);
};
SimuladorEntradas::SimuladorEntradas(){

}
SimuladorEntradas::SimuladorEntradas(DetectorDeRequerimiento btn, std::string flnm){
    boton=btn;
    file.open(flnm,ios_base::in);

}
void SimuladorEntradas::def_atributos(DetectorDeRequerimiento btn, std::string flnm){
    boton=btn;
    file.open(flnm,ios_base::in);
}
void SimuladorEntradas::actionPerformed() {
    if(!file.eof()){
        getline(file,linea);
        if(linea==("1")){
            boton.setOn();
        }
    }
    else{
        file.close();
        exit(0);
    }

}


