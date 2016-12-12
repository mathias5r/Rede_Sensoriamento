#include <iostream>
//#include "Sensor.h"
#include "Broker.h"
#include "TCPBaseSocket.h"
#include <pthread.h>

void *task1(void *);

int main() {

    char * info = new char[12];
    char * ip = new char[15];
    info = (char*)"Test message";
    ip = (char*)"127.0.0.1";
    pthread_t threadA[3];
    //TCPClientSocket tc(ip,2222);
    TCPServerSocket ts(3333);
    // Connection & sock = ts.wait();
    // Broker bk;
    // bk.recebePacote(sock);  

    
    //while(1){};
    

    // int noThread = 0;

    // while (noThread < 3)
    // {
       // Connection & sock = ts.wait(0);
        Broker bk;
        bk.recebePacote(ts);  
//         int i=0; 
//         pthread_create(&threadA[noThread], 0, task1, (void*)&sock); 
//         noThread++;
//     }
//     for(int i = 0; i < 3; i++)
//     {
//         pthread_join(threadA[i], 0);
//     }
//     return 0;
}

void * task1 (void *dummyPt)
{    
    //  Connection & sock = (Connection)dummyPt;
  //  cout << "MSG "<< endl;
 //   Broker bk;
 //   bk.recebePacote((Connection&)dummyPt);  
    return 0;
}
//recebe publish do sensor; os assuntos estão registrados;