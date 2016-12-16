/*
 * Device.h
 *
 *  Created on: 25 de nov de 2016
 *      Author: mathias
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#define INFO_SIZE 12
#define IP_SIZE 15
#define DEFAULT_PORT 3333

#include "TCPBaseSocket.h"
#include "Database.h"
#include <parser_Ativo.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <string>

#define MAX_LEVEL 10

using namespace std;

/*
	A classe Device é responsável por enviar as mensagens para o Broker ou receber as mensagens deste. 	
*/

class Device {
public:
    Device(const string & addr_broker, int port) {
        sock.connect(addr_broker, port);
    };
    virtual ~Device(){};
    // Códifica a mensagem publish com o dado "msg" e envia com o tópico topic como informação.
    bool publish(string msg, string topic);
    // Codifica a mensagem subcribe e envia com o tópico topic como informação.
    bool subscriber(string topic);
    // Codifica a mensagem unsubcribe e envia com o tópico topic como informação.
    bool unsubscriber(string topic);
    // Recebe mensagem do Broker, decodifica e apresenta para aplicaço.	
    string notified();
private:
	TCPClientSocket sock;
    vector<string> Topics; 
};

#endif /* SENSOR_H_ */
