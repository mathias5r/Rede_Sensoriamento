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

    TCPServerSocket ts(3333);
    Broker bk;
    int sock_fd = ts.get_descriptor();  
    int sock_fdco = 0;//co.get_descriptor();
    int maior =  sock_fd;

    while(1){
        fd_set r;
        FD_ZERO(&r);
        FD_SET(sock_fd, &r);
        FD_SET(sock_fdco, &r);
        int n = 0;
        try{
            if( !(n = select(maior+1, &r, 0, 0, 0)) == 0 ){
                cout << "INFO: Há " << n << " descritores prontos" << endl;
                if(n < 0){
                    perror("select()");

                }else if(n){
                    if (FD_ISSET(sock_fd, &r)) {
                        Connection & sock = ts.wait(0);
                        sock_fdco = sock.get_descriptor();
                        if(sock_fdco > sock_fd){maior = sock_fdco;}else{maior = sock_fd;}
                        bk.recebePacote(&ts);  
                    }if(FD_ISSET(sock_fdco,&r)){
                        Connection & sock = ts.wait(0);
                        bk.recebePacote(&ts); 
                    }
                }
            }
        }catch (TCPServerSocket::DisconnectedException e) {
                cout << e.what() << ": " << e.get_addr() << ':';
                cout << e.get_port()<< endl;
            }
        }   
    } 
