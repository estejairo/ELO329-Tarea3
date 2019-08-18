#include "MyListener.h"
#include <iostream>
using namespace std;
MyListener::MyListener(){
   i=0;
}
void MyListener::actionPerformed() {
   i++;
   cout << i<< endl;
}