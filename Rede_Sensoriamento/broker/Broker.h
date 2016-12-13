/*
 * broker.h
 *
 *  Created on: 25/11/2016
 *      Author: ronaldo
 */

#ifndef BROKER_H_
#define BROKER_H_

#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <pthread.h>
#include <list>
#include <string>
#include <cctype>
#include "topicos.h"
#include "TCPBaseSocket.h"
#include <parser_Ativo.h>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>



class Broker {
public:
	Broker();
	virtual ~Broker(){};
	enum Type{ id_PR_publish,id_PR_Subscriber,id_PR_Notify, id_PR_Unsubscriber };
	void sendNotify(string  addr, string * valor, string assOID, int port);
	void recvPublish(string endIP,string assunto, string informacao);
	void recvSubscriber(string addr, string issue, int port,Connection * s);
	//void recvSubscriber(string addr, string issue, int port,TCPServerSocket & s);
	void recebePacote( TCPServerSocket * socke);
private:
	//TCPServerSocket & sock;
	//TCPServerSocket & sockSub;
	topicos Top[3];

	int idTopicos;
};

#endif /* BROKER_H_ */
