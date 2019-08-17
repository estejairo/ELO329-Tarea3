#include "TrafficLight.cpp"
class StreetTrafficLight: public TrafficLight
{
private:
    /* data */
public:
    StreetTrafficLight(int tf,int tt);
    ~StreetTrafficLight();
};

StreetTrafficLight::StreetTrafficLight(int tf,int tt):TrafficLight(tf,tt){
}

StreetTrafficLight::~StreetTrafficLight(){
}
