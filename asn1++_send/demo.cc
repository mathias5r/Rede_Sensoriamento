#include <iostream>
#include "Sensor.h"

using namespace std;

int main() {

    char * info = new char[12];
    char * ip = new char[15];
    info = (char*)"Test message";
    ip = (char*)"127.0.0.1";
    TCPClientSocket sock;
    sock.connect(ip, DEFAULT_PORT);
    Sensor s1(info,ip,sock);
    s1.subscriber();

    while(1){
        s1.send_value();
        sleep(5000);
    }
}
