#ifndef SEMAFORODEGIRO_H_
#define SEMAFORODEGIRO_H_

#include <iostream>

class SemaforoDeGiro
{
private:
    int greenT,blinkT;
    int state; //0=Green, 1=Yellow, 2=Red
    friend std::ostream& operator<<(std::ostream&, const SemaforoDeGiro&);
public:
    SemaforoDeGiro();
    SemaforoDeGiro(int greenTime, int blinkingTime);
    ~SemaforoDeGiro();
    void turnRedLightOn();
    void turnGreenLightOn();
    void turnGreenLightOff();
    int getGreenLightTime();
    int getBlinkingTime();
    int getState();
};

#endif /* SEMAFORODEGIRO_H_ */