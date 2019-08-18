#include "Controlador.h"
#include <thread>
#include <chrono>
#include <exception>

Controlador::Controlador(SemaforoP semaforopA, SemaforoP semaforopB, SemaforoDeGiro semaforog2, SemaforoDeGiro semaforog4, DetectorDeRequerimiento *botont, DetectorDeRequerimiento *sensorInd, StreetTrafficLight semaforo1, StreetTrafficLight semaforo3, StreetTrafficLight semaforo5){
    //Semaforos vehiculares
    sem1 = semaforo1;
    sem3 = semaforo3;
    sem5 = semaforo5;
    //Semaforos de Giro
    semg2 = semaforog2;
    semg4 = semaforog2;
    //Semaforos peatonales
    semp1norteA = semaforopA;
    sempsportingB = semaforopB;
    //Detectores de Requerimiento
    sensorinductivo = sensorInd;
    botonpeaton = botont;
    
    //Estado Inicial
    state = 1;
    sem5.turnFollow();
    sem3.turnFollow();
    sempsportingB.turnGreenLightOn();
    semg4.turnRedLightOn();
    semp1norteA.turnRedLightOn();
    sem1.turnStop();
    semg2.turnRedLightOn();
}

Controlador::~Controlador()
{
}

//Metodo que opera las luces del semaforo segun los requerimientos del sensor
void Controlador::manageTraffic(){
    std::cout<<"\t"<<"A"<<"\t"<<"B"<<"\t"<<"1"<<"\t"<<"2"<<"\t"<<"3"<<"\t"<<"4"<<"\t"<<"5"<<std::endl;
    while (true) {//Se opera indefinidamente
        switch (state){
            //Flujo de autos por 1 norte
            case 1:
                //Si alguien quiere cruzar 1 norte o se acaba el tiempo en verde de 1 norte se cambia de estado
                if (botonpeaton->isOn()||(currentGreenTime >= sem5.getFollowTime())){
                    currentGreenTime = 1;
                    state = 2;
                    sem5.turnTransition();
                    sem3.turnTransition();
                    sempsportingB.turnGreenLightOff();//comienza el parpadeo
                }
                //Si no, se mantiene el estado
                else{
                    currentGreenTime += 1;
                }
                break;
            //Transision para flujo de autos por 1 norte
            case 2:
                //Si alguien queria cruzar y ya se acabo el tiempo en amarillo, se cambia de estado
                if (botonpeaton->isOn()&&(currentYellowTime >= sem5.getTransitionTime())){
                    botonpeaton->setOff();
                    currentYellowTime = 1;
                    state = 21;
                    sem5.turnStop();
                    sem3.turnStop();
                    sempsportingB.turnRedLightOn();
                    semp1norteA.turnGreenLightOn();
                    semg2.turnGreenLightOn();
                }
                //Si se acabo el tiempo en amarillo, se cambia de estado
                else if ((currentYellowTime >= sem5.getTransitionTime())){
                    currentYellowTime = 1;
                    state = 3;
                    sem5.turnStop();
                    sem3.turnStop();
                    sempsportingB.turnRedLightOn();
                    sem1.turnFollow();
                    semg2.turnGreenLightOn();
                }
                //Si no, se mantiene el estado
                else{
                    currentYellowTime += 1;
                }
                break;
            //Flujo de peatones cruzando 1 norte
            case 21:
                //Si se acaba el tiempo en verde se cambia de estado
                if (currentGreenTime >= semp1norteA.getGreenLightTime()){
                    currentGreenTime = 1;
                    state = 22;
                    semp1norteA.turnGreenLightOff();
                }
                //Si no, se mantiene el estado
                else {
                    currentGreenTime += 1;
                }
                break;
            //Transision para el flujo de peatones cruzando 1 norte
            case 22:
                //Si se acaba el tiempo de parpadeo del semaforo se cambia de estado
                if (currentYellowTime >= semp1norteA.getBlinkingTime()){
                    currentYellowTime = 1;
                    state = 3;
                    semp1norteA.turnRedLightOn();
                    sem1.turnFollow();
                }
                //Si no, se mantiene el estado
                else {
                    currentYellowTime += 1;
                }
                break;
            //Flujo de autos por sporting
            case 3:
                //Si se acaba el tiempo en verde, se cambia de estado
                if (currentGreenTime >= sem1.getFollowTime()){
                    currentGreenTime = 1;
                    state = 4;
                    sem1.turnTransition();
                    semg2.turnGreenLightOff();
                }
                //Si no, se mantiene el estado
                else {
                    currentGreenTime += 1;
                }
                break;
            //Transicion del flujo de autos por sporting
            case 4:
                //Si un auto desea virar desde 1 norte a sporting y ya se acabo el tiempo en amarillo
                if (sensorinductivo->isOn()&&(currentYellowTime >= sem1.getTransitionTime())){
                    sensorinductivo->setOff();
                    currentYellowTime = 1;
                    state = 41;
                    sem1.turnStop();
                    semg2.turnRedLightOn();
                    sem5.turnFollow();
                    semg4.turnGreenLightOn();
                }
                //Si se acaba el tiempo en verde, se cambia de estado
                else if (currentYellowTime >= sem1.getTransitionTime()){
                    currentYellowTime = 1;
                    state = 5;
                    sem1.turnStop();
                    semg2.turnRedLightOn();
                    sempsportingB.turnGreenLightOn();
                    sem5.turnFollow();
                    sem3.turnFollow();
                }
                //Si no, se mantiene el estado
                else {
                    currentYellowTime += 1;
                }
                break;
            //Viraje de autos desde 1 norte hacia sporting
            case 41:
                //Si se acaba el tiempo en verde
                if (currentGreenTime >= semg4.getGreenLightTime()){
                    currentGreenTime = 1;
                    state = 42;
                    semg4.turnGreenLightOff();
                }
                //Si no, se mantiene el estado
                else{
                    currentGreenTime += 1;
                }
                break;
            //Transicion de viraje de autos desde 1 norte hacia sporting
            case 42:
                //Si se acaba el tiempo en parpadeo
                if (currentYellowTime >= semg4.getBlinkingTime()){
                    currentYellowTime = 1;
                    state = 1;
                    semg4.turnRedLightOn();
                    sem3.turnFollow();
                    sempsportingB.turnGreenLightOn();
                }
                //Si no, se mantiene el estado
                else{
                    currentYellowTime += 1;
                }
                break;
            default:
                std::cout<<"\n Error, estado no existente!"<<std::endl;
        }
        //Se imprime el estado actual del semaforo
        std::cout<<counter<<"\t"<<semp1norteA<<"\t"<<sempsportingB<<"\t"<<sem1<<"\t"<<semg2<<"\t"<<sem3<<"\t"<<semg4<<"\t"<<sem5<<std::endl;

        //Se mantiene el estado por 1 segundo      
        try{
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            counter = counter + 1; 
        } catch(...){
            std::cout<<"Interrupcion"<<std::endl;
        }   
        
    }   
}



