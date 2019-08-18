#ifndef TRAFFICLIGHT_H_
#define TRAFFICLIGHT_H_
#include <iostream>
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

#endif /* TRAFFICLIGHT_H_ */