#include "MyTimer.h"
#include "MyListener.h"
#include <unistd.h>  // sleep
#include <iostream>   //cout

using namespace std;
int main () {
   MyListener listener;
   MyTimer timer (100, listener);  // es sus programas use solo una
                                 // instancia de MyTimer.
   for (int i=1; i<3; i++) {
      sleep(1);
      cout << "i="<< i<< endl;
   }
   timer.stop();
   exit(0);
}