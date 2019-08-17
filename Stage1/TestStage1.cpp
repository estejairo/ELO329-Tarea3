#include<iostream>
#include "StreetTrafficLight.h"
#include <string>
#include <thread>
#include <chrono>

using namespace std;
int main (int argc, char* argv[]){
    if(argc != 3){
        cout<<"Ingresar N y RedTime"<<endl;
    }
    else{
        int N = stoi(argv[1]);
        int redTime = stoi(argv[2]);
        int greenTime=5;
        int yellowtime=3;
        StreetTrafficLight sem_1 = StreetTrafficLight(greenTime,yellowtime); 
        
        int currentRedTime = 0;
        int currentYellowTime = 1;
        int currentGreenTime = 1;

        sem_1.turnStop();

        //Ciclo de N segundos de duracion (aprox)
        for (int i=0; i<=N; i++){
            // Logica para encender las luces
            if ((currentRedTime < redTime)&&(sem_1.getState()==0)){ //verifica si esta en rojo y aun queda tiempo
                currentRedTime+=1;
            }
            else if ((currentRedTime == redTime)&&(sem_1.getState()==0)){ //Verifica si esta en rojo y debe cambiar a luz Verde
                sem_1.turnFollow();
                currentRedTime = 1;
            }
            else if ((currentYellowTime < sem_1.getTransitionTime())&&(sem_1.getState()==1)){ //verifica si esta en amarillo y aun queda tiempo
                currentYellowTime+=1;
            }
            else if ((currentYellowTime == sem_1.getTransitionTime())&&(sem_1.getState()==1)){ //Verifica si esta en Amarillo y debe cambiar a luz Roja
                sem_1.turnStop();
                currentYellowTime = 1;
            }
            else if ((currentGreenTime < sem_1.getFollowtime())&&(sem_1.getState()==2)){ //verifica si esta en verde y aun queda tiempo
                currentGreenTime+=1;
            }
            else if ((currentGreenTime == sem_1.getFollowtime())&&(sem_1.getState()==2)){ //Verifica si esta en Verde y debe cambiar a luz Amarilla
                sem_1.turnTransition();
                currentGreenTime = 1;
            }

            cout<< i <<"\t"<< sem_1.getState()<<endl; //Estado del semaforo cada segundo
            //Esperar 1 segundo
            std::this_thread::sleep_for(chrono::milliseconds(1000));
            //cout<<"algo"<<endl;
        }
        sem_1.~StreetTrafficLight();
        return 0;
    }
}
