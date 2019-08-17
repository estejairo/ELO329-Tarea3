
#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_

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


#endif	/* TRAFFICLIGHT_H_ */