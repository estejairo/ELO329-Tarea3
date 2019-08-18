#include "Controlador.h"
#include <thread>
#include <chrono>
#include <exception>

Controlador::Controlador(SemaforoDeGiro smg,DetectorDeRequerimiento *sensind){
    semg=smg;
    sensorinductivo=sensind;

}

//Metodo que opera las luces del semaforo segun los requerimientos del sensor
void Controlador::manageTraffic(){
    int counter = 0;//Variable lleva el conteo del tiempo transcurrido
    while (true) {//Se opera indefinidamente
        if (sensorinductivo->isOn()){// Si hay un requerimiento, se opera el semaforo
            sensorinductivo->setOff();// Al comenzar a atenderlo, se apaga el requerimiento
            semg.turnGreenLightOn();//Se enciende la luz verde (lo que era requerido)
            for (int i=0; i<(semg.getGreenLightTime()); i++){
                std::cout<<counter<<"\t"<<semg<<std::endl;//Imprime el estado del semaforo
                try{
                std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //Se desactiva el proceso durante el tiempo en verde
                counter = counter + 1;// Se agrega el tiempo transcurrido al contador
                } catch(...){
                std::cout<<"Interrupcion"<<std::endl;
                }
            }
            semg.turnGreenLightOff();

            //Comienza el parpadeo. Se enciende y apaga arbitrariamente cada 1 segundo.
            //El ciclo dura la mitad del tiempo de parpadeo, ya que en cada ciclo está un segundo
            //encendido y otro segundo apagado.
            for (int i=0; i<(semg.getBlinkingTime()); i++){//Comienza el parpadeo
                std::cout<<counter<<"\t"<<semg<<std::endl;//Imprime el estado del semaforo
                try{
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));//Se espera 1 segundo
                    counter+=1;//Se agrega el tiempo transcurrido al contador
                }catch(...){
                    std::cout<<"Interrupcion"<<std::endl;
                }
            }
            semg.turnRedLightOn();
        }
        else{
            std::cout<<counter<<"\t"<<semg<<std::endl; //Se imprime el estado actual del semaforoS
            try{
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));//Si no hay requerimiento, se espera un segundo
            } catch(...){
                std::cout<<"Interrupcion"<<std::endl;
            }
            counter = counter + 1; 
            semg.turnRedLightOn();
        }
    }   
}
