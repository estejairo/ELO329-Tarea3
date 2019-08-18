#include "TrafficLight.cpp"
class StreetTrafficLight : public TrafficLight{
public:

    StreetTrafficLight(int tf,int tt);

};
StreetTrafficLight::StreetTrafficLight(int tf,int tt):TrafficLight(tf,tt){
}