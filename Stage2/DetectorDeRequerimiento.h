#ifndef DETECTORDEREQUERIMIENTO_H_
#define DETECTORDEREQUERIMIENTO_H_

#include <iostream>


class DetectorDeRequerimiento
{
private:
    bool state;
    //friend std::ostream& operator<<(std::ostream& o, const DetectorDeRequerimiento& a);
public:
    DetectorDeRequerimiento();
    bool isOn();
    void setOn();
    void setOff();

};

#endif /* DETECTORDEREQUERIMIENTO_H_ */