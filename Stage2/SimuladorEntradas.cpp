#include "SimuladorEntradas.h"

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


