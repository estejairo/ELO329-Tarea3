#include <string>
#include "DetectorDeRequerimiento.cpp"
#include <thread>
#include <chrono>
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
SimuladorEntradas::SimuladorEntradas(){

}
SimuladorEntradas::SimuladorEntradas(DetectorDeRequerimiento *btn, string flnm){
    boton=btn;
    file.open(flnm,ios_base::in);

}
void SimuladorEntradas::def_atributos(DetectorDeRequerimiento *btn, string flnm){
    boton=btn;
    file.open(flnm,ios_base::in);
}
void SimuladorEntradas::actionPerformed() {
    if(!file.eof()){
        getline(file,linea);
        if(stoi(linea)){
            //cout<<"BOTON ON"<<linea<<endl;
            boton->setOn();
        }
        else{
            boton->setOff();
        }
    }
    else{
        file.close();
        exit(0);
    }

}


