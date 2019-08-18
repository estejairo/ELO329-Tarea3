#ifndef DETECTORDEREQUERIMIENTO_H_
#define DETECTORDEREQUERIMIENTO_H_

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

#endif /* DETECTORDEREQUERIMIENTO_H_ s */