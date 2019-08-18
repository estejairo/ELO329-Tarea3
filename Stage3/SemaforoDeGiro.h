#ifndef SEMAFORODEGIRO_H_
#define SEMAFORODEGIRO_H_
#include <iostream>

class SemaforoDeGiro
{
private:
    int greenT,blinkT;
    bool red,green;
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

};

#endif /* SEMAFORODEGIRO_H_ */