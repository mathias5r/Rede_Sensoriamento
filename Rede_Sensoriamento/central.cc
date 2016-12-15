#include <iostream>
#include "Device.h"
#include <unistd.h>

using namespace std;

int main() {

    string broker_ip = "10.0.0.253";
    string topic1 = "1.1";
    string topic2 = "1.2";   
    
    Device central(broker_ip,3333);
   
    central.subscriber(topic1);
   // sleep(10);
   // central.subscriber(topic2);

    while(1){
        string buffer = central.notified();
        cout << buffer << endl;
    }
}
