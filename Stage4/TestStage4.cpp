#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include "SimuladorEntradas.cpp"
#include "Controlador.cpp"
#include "MyTimer.cpp"

using namespace std;
int main (int argc, char* argv[]){
    if(argc != 2){
        cout<<"Ingresar Nombre Archivo"<<endl;
    }
    else{
        string filename = argv[1];
        int greenTime = 12;
        int blinkingTime = 6;
        try{
            //Semaforos peatonales
            SemaforoP semaforopA = SemaforoP(greenTime, blinkingTime);
            SemaforoP semaforopB = SemaforoP(greenTime, blinkingTime);

            //Semaforos de giro
            SemaforoDeGiro semaforog2 = SemaforoDeGiro(greenTime, blinkingTime);
            SemaforoDeGiro semaforog4 = SemaforoDeGiro(greenTime, blinkingTime);

            //Semaforos vehiculares
            StreetTrafficLight semaforo1 = StreetTrafficLight(greenTime, blinkingTime);
            StreetTrafficLight semaforo3 = StreetTrafficLight(greenTime, blinkingTime);
            StreetTrafficLight semaforo5 = StreetTrafficLight(greenTime, blinkingTime);

            //Detectores de requerimiento
            DetectorDeRequerimiento *botont = new DetectorDeRequerimiento();
            DetectorDeRequerimiento *sensorInd = new DetectorDeRequerimiento();


            Controlador ctrl = Controlador(semaforopA,semaforopB,semaforog2,semaforog4,botont,sensorInd,semaforo1,semaforo3,semaforo5);
            SimuladorEntradas *entradas = new SimuladorEntradas(botont, sensorInd, filename);

            //TIMER
            //El archivo se lee cada 1000 milisegundos segun lo definido en los metodos de SimuladorEntradas
            MyTimer timer = MyTimer(1000, entradas);
            ctrl.manageTraffic();//Se opera el semaforo, atento a las señales del sensor
            timer.stop();
        }catch (...){
            cout<<"Error"<<endl;
            exit(0);
        }


        return 0;
    }
}