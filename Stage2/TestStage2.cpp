#include<iostream>
#include <string>
#include <thread>
#include <chrono>
#include "SimuladorEntradas.cpp"
#include "Controlador.cpp"
#include "MyTimer.h"
using namespace std;
int main (int argc, char* argv[]){
    if(argc != 2){
        cout<<"Ingresar Nombre Archivo"<<endl;
    }
    else{
        string filename = argv[1];
        int greenTime = 5;
        int blinkingTime = 10;
        try{
            SemaforoP semaforop = SemaforoP(greenTime, blinkingTime);
            DetectorDeRequerimiento botont;
            Controlador ctrl = Controlador(semaforop,botont);
            SimuladorEntradas entradas=SimuladorEntradas(botont,filename);
            //TIMER
            //El archivo se lee cada 1000 milisegundos segun lo definido en los metodos de SimuladorEntradas
            MyTimer timer = MyTimer(1000, entradas);
            //timer.resume();//Comienza la lectura en paralelo
            ctrl.manageTraffic();//Se opera el semaforo, atento a las señales del sensor
        }catch (...){
            cout<<"Error"<<endl;
            exit(0);
        }


        return 0;
    }
}
