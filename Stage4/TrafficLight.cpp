enum TrafficLightState{STOP=0,TRANSITION=1,FOLLOW=2};

class TrafficLight{
    public:
        TrafficLight();
        TrafficLight(int ft, int tt);
        ~TrafficLight();
        void turnStop();
        void turnTransition();
        void turnFollow();
        int getFollowTime();
        int  getTransitionTime();
        TrafficLightState getState(); 
        friend std::ostream& operator<<(std::ostream& ,const TrafficLight &);
    private:
        int followTime;
        int transitionTime;
        TrafficLightState state;
    };
TrafficLight::~TrafficLight(){
    
}

TrafficLight::TrafficLight(){
    
}
TrafficLight::TrafficLight(int ft, int tt){
    followTime =ft;
    transitionTime=tt;
    state=STOP;

}


void TrafficLight::turnStop(){
    state=STOP;
}
void TrafficLight::turnTransition(){
    state=TRANSITION;
}
void TrafficLight::turnFollow(){
    state=FOLLOW;
}
int TrafficLight::getFollowTime(){

    return followTime;
}
int TrafficLight::getTransitionTime(){
    return transitionTime;
}
TrafficLightState TrafficLight::getState(){
    return state;
}
std::ostream& operator<<(std::ostream& o, const TrafficLight& sem){
    if(sem.state==TrafficLightState::FOLLOW){
        return o << "V";
    }
    else if(sem.state==TrafficLightState::STOP){
        return o << "R";
    }
    else{
        return o << "A";
    }
    

}