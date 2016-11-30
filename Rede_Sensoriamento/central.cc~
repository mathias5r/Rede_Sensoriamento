#include <iostream>
#include "Device.h"

using namespace std;

int main() {
 
    char * broker_ip = new char[15];
    char * topic_name = new char[20];
    char * atop_topic = new char[20];
    
    broker_ip = (char*)"127.0.0.1";
    topic_name = (char*)"Teste";
    atop_topic = (char*)"null";
    
    TCPClientSocket sock;
    sock.connect(broker_ip, DEFAULT_PORT);

    Device central(1, sock);
   
    central.add_topic(topic_name, atop_topic);

    char * buffer = new char[256];

    while(1){
        central.receive(buffer);
        cout << buffer << endl;
    }
}
