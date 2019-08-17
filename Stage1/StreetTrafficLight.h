
#ifndef STREETTRAFFICLIGHT_H_
#define STREETTRAFFICLIGHT_H_

#include "TrafficLight.h"

class StreetTrafficLight: public TrafficLight
{
private:
    /* data */
public:
    StreetTrafficLight(int tf,int tt);
    ~StreetTrafficLight();
};

#endif	/* TRAFFICLIGHT_H_ */
