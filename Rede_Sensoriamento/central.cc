#include <iostream>
#include "Device.h"

using namespace std;

int main() {

    string broker_ip = "10.0.0.2";
    string topic = "1.1";   
    
    Device central(broker_ip,DEFAULT_PORT);
   
    central.subcriber(topic);

    while(1){
        string buffer = central.notified();
        cout << buffer << endl;
    }
}
