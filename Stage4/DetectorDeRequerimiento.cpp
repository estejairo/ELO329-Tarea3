#include <iostream>


class DetectorDeRequerimiento
{
private:
    bool state;
public:
    DetectorDeRequerimiento();
    bool isOn();
    void setOn();
    void setOff();

};

DetectorDeRequerimiento::DetectorDeRequerimiento(){
    state=false;
}

bool DetectorDeRequerimiento::isOn(){
    return state;
}
void DetectorDeRequerimiento::setOn(){
    state=true;
}
void DetectorDeRequerimiento::setOff(){
    state=false;
}