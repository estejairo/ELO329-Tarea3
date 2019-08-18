#include "TrafficLight.cpp"
class StreetTrafficLight: public TrafficLight
{
private:
    /* data */
public:
    StreetTrafficLight();
    StreetTrafficLight(int tf,int tt);
    ~StreetTrafficLight();
};

StreetTrafficLight::~StreetTrafficLight(){
}

StreetTrafficLight::StreetTrafficLight(){
}


StreetTrafficLight::StreetTrafficLight(int tf,int tt):TrafficLight(tf,tt){
}

