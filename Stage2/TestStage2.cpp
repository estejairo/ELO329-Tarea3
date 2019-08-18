#include<iostream>
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
        int greenTime = 5;
        int blinkingTime = 10;
        try{
            SemaforoP semaforop = SemaforoP(greenTime, blinkingTime);
            DetectorDeRequerimiento *botont = new DetectorDeRequerimiento();
            Controlador ctrl = Controlador(semaforop,botont);
            SimuladorEntradas *entradas = new SimuladorEntradas(botont, filename);
            //SimuladorEntradas entradas;
            //TIMER
            //El archivo se lee cada 1000 milisegundos segun lo definido en los metodos de SimuladorEntradas
            MyTimer timer = MyTimer(1000, entradas);
            //timer.resume();//Comienza la lectura en paralelo
            ctrl.manageTraffic();//Se opera el semaforo, atento a las señales del sensor
            timer.stop();
            delete entradas;
            delete botont;
        }catch (...){
            cout<<"Error"<<endl;
            exit(0);
        }


        return 0;
    }
}
