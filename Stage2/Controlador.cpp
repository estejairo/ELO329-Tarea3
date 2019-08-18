#include "Controlador.h"


Controlador::Controlador(SemaforoP smp,DetectorDeRequerimiento *btn){
    semP=smp;
    boton=btn;

}

Controlador::~Controlador()
{
}
//Metodo que opera las luces del semaforo segun los requerimientos del sensor
void Controlador::manageTraffic(){
    std::cout<<"\tA"<<std::endl;
    int counter = 0;//Variable lleva el conteo del tiempo transcurrido
    while (true) {//Se opera indefinidamente
        if (boton->isOn()){// Si hay un requerimiento, se opera el semaforo
            boton->setOff();// Al comenzar a atenderlo, se apaga el requerimiento
            semP.turnGreenLightOn();//Se enciende la luz verde (lo que era requerido)
            for (int i=0; i<(semP.getGreenLightTime()); i++){
                std::cout<<counter<<"\t"<<semP<<std::endl;//Se imprime el tiempo y el estado
                try{
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000)); //Se desactiva el proceso durante el tiempo en verde
                    counter += 1;// Se agrega el tiempo transcurrido al contador
                } catch(...){
                    std::cout<<"Interrupcion"<<std::endl;
                }
            }
            //Comienza el parpadeo. Se enciende y apaga arbitrariamente cada 1 segundo.
            //El ciclo dura la mitad del tiempo de parpadeo, ya que en cada ciclo está un segundo
            //encendido y otro segundo apagado.
            semP.turnGreenLightOff();//Se apaga la luz verde
            for (int i=0; i<(semP.getBlinkingTime()); i++){//Comienza el parpadeo
                std::cout<<counter<<"\t"<<semP<<std::endl;//Imprime el estado del semaforo
                try{
                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));//Se espera 1 segundo
                    counter+=1;//Se agrega el tiempo transcurrido al contador
                }catch(...){
                    std::cout<<"Interrupcion"<<std::endl;
                }
            }
            /*Se apaga finalmente la luz verde y se enciende la roja, dando por finalizada 
            la atencion al requerimiento*/
            //semP.turnRedLightOn();
            //std::cout<<counter<<"\t"<<semP<<std::endl;//Se imprime el estado del semaforo
        }
        semP.turnRedLightOn();
        std::cout<<counter<<"\t"<<semP<<std::endl; //Se imprime el estado actual del semaforoS        
        try{
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));//Si no hay requerimiento, se espera un segundo
            counter = counter + 1; 
        } catch(...){
            std::cout<<"Interrupcion"<<std::endl;
        }       
    }   
}
