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
// std::ostream& operator<<(std::ostream &o, const DetectorDeRequerimiento &a) {
//     if(a.state){
//         return o<<("1");
//     }
//     else{
//         return o << "0";
//     }
// }