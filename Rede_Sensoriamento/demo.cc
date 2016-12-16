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


/*
    O protocolo de aplicação é baseado no modelo publish/subscriber, sendo que o conteúdo da mensagem a ser transmitida é codificada
    em ASN1++ conforme espeficicação do projeto. Os participantes podem ser tanto publish como subscriber, sendo que o subscribers
    são notificados imediatamente a cada publish recebido. 
    Pela complexidade de sincronismo entre Thread o projeto foi modificado, no que se refere a multiplas requisições de pub/sub,
    para o modelo com select, através de descritores de arquivos, um para novas conexões e outra para antigas conexões.
    O sock_fd é o descritor de arquivo para novas conexões e o sock_fdco para atuar em conexões já existentes.
    As novas conexões de subscribers são armazenadas em um vetor de subs contido no objeto da classe tópico.

    Elementos do projeto:
 
    Broker: registrar os subscribers em tópicos e informa-los com os dados do respectivo tópico.
    Participantes: Os participantes podem ser publish e/ou subscribers. A cada publish enviado, todos os subscribers registrados
    no tópico do publish recebido, serão notificados.

    O vocabulário do protocolo é composto por:
 
    Subscriber: Anuncia ao Broker o intenção em se registrar em tópico.
    Publish: Mensagem enviada ao broker anunciando um novo dado para um respectivo tópico.
    Notify: Informa ao subscriber o novo dado recebido em um respectivo tópico.
    Unsubcriber: Elimina um subscriber registrado em um específico tópico.
*/


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
