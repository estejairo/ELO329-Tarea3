enum TrafficLightState{STOP=0,TRANSITION=1,FOLLOW=2};

class TrafficLight{
    public:
        TrafficLight(int ft, int tt);
        ~TrafficLight();
        void turnStop();
        void turnTransition();
        void turnFollow();
        int getFollowtime();
        int  getTransitionTime();
        TrafficLightState getState(); 
        //friend ostream & operator <<(ostream&out,const TrafficLight &semaforo);
    private:
        int followTime;
        int transitionTime;
        TrafficLightState state;
    };

TrafficLight::TrafficLight(int ft, int tt){
    followTime =ft;
    transitionTime=tt;
    state=STOP;

}
TrafficLight::~TrafficLight(){
    
}
// ostream & operator << (ostream &out, const TrafficLight &semaforo){

//     out << sme"+i" << c.imag << endl;
//     return out;
// }

void TrafficLight::turnStop(){
    state=STOP;
}
void TrafficLight::turnTransition(){
    state=TRANSITION;
}
void TrafficLight::turnFollow(){
    state=FOLLOW;
}
int TrafficLight::getFollowtime(){

    return followTime;
}
int TrafficLight::getTransitionTime(){
    return transitionTime;
}
TrafficLightState TrafficLight::getState(){
    return state;
}