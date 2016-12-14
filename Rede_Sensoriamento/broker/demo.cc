#include <iostream>
//#include "Sensor.h"
#include "Broker.h"
#include "TCPBaseSocket.h"
#include <pthread.h>

#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>


void *task1(void *);

int main() {

    char * info = new char[12];
    char * ip = new char[15];
    info = (char*)"Test message";
    ip = (char*)"127.0.0.1";
    pthread_t threadA[3];
    //TCPClientSocket tc(ip,2222);
    TCPServerSocket ts(3333);
    Broker bk;
   ;

    // Broker bk;
    // bk.recebePacote(sock);
    int sock_fd = ts.get_descriptor();  
    
    //Connection co(sock_fd);
    int sock_fdco = 0;//co.get_descriptor();

int maior =  sock_fd;
if(sock_fdco > sock_fd){maior = sock_fdco;}else{maior = sock_fd;}
    while(1){
            fd_set r;

        // inicia o conjunto de descritores, e nele
        // acrescenta fd1 e fd2
        FD_ZERO(&r);
        FD_SET(sock_fd, &r);
        FD_SET(sock_fdco, &r);
        //FD_SET(this->aplicacao, &r);
    int n = 0;
    if( !(n = select(maior+1, &r, 0, 0, 0)) == 0 ){

            cout << "INFO: Há " << n << " descritores prontos" << endl;


            if(n < 0){
                perror("select()");

            }else if(n){

                // testa se fd1 está pronto para ser acessado
                if (FD_ISSET(sock_fd, &r)) {
                    cout << "NOVA CONEXÃO" << endl;
                    Connection & sock = ts.wait(0);
                    sock_fdco = sock.get_descriptor();
                    if(sock_fdco > sock_fd){maior = sock_fdco;}else{maior = sock_fd;}
                        bk.recebePacote(&ts);  
                    // this->arq.set_received(true);
                    // this->arq.handle();
                    // this->arq.set_received(false);
                    // this->begin = clock();

                }if(FD_ISSET(sock_fdco,&r)){
                    cout << "Conexão Antiga" << endl;
                     Connection & sock = ts.wait(0);
                     bk.recebePacote(&ts); 
                }
        
            cout << "Eu voltei, pois aqui é meu lugar!" << endl;

            }
        }
    }
}   //while(1){};
    

//      int noThread = 0;

//      while (noThread < 3)
//      {
//         Connection & sock = ts.wait(0);
//         //Broker bk;
//         //bk.recebePacote(ts);  
// //         int i=0; 
//          pthread_create(&threadA[noThread], 0, task1, (void*)&ts); 
//          noThread++;
//      }
//      for(int i = 0; i < 3; i++)
//      {
//          pthread_join(threadA[i], 0);
//      }
//      return 0;
// }

void * task1 (void *dummyPt)
{    
   // TCPServerSocket & sock = (TCPServerSocket)dummyPt;
    cout << "MSG "<< endl;
    Broker bk;
    bk.recebePacote((TCPServerSocket*)dummyPt);  
    return 0;
}
//recebe publish do sensor; os assuntos estão registrados;



    // this->tty_fd = open(path,O_RDWR|O_NOCTTY);
    // if (tty_fd < 0) throw -10;
    // config(this->tty_fd, rate);

    // Tun iface("ptp0" , "192.168.1.2", "192.168.1.1");
    // iface.start();
    // }   Serial t("/dev/ttyUSB0",B9600);
    // Framework f(t,1,FRAME_MAXSIZE);
    // ARQ arq(f, iface);
    // Dispacher d(arq,t.get_fd(),iface.get());

    // int Tun::get() {
    //  if (fd >= 0) return fd;
    //  throw -3;
