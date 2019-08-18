#ifndef SEMAFOROP_H_
#define SEMAFOROP_H_

#include <iostream>

class SemaforoP
{
private:
    int greenT,blinkT;
    bool red,green;
    friend std::ostream& operator<<(std::ostream&, const SemaforoP&);
public:
    SemaforoP();
    SemaforoP(int greenTime, int blinkingTime);
    ~SemaforoP();
    void turnRedLightOn();
    void turnGreenLightOn();
    void turnGreenLightOff();
    int getGreenLightTime();
    int getBlinkingTime();

};

#endif	/* SEMAFOROP_H_ */
