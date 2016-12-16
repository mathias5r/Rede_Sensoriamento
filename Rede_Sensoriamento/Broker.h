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

/*
	A classe broker é responsável por Desserializar, identicar o tipo de mensagem recebida, sendo ela Subscriber, Publish, unSubcriber e Notitfy. Tais 
	mensagens possuem seus respectivos métodos que realizam suas funções conforme o especificação de uma aplicação publish/subscriber.
	
	O Broker inicializa o socket server e cria estaticamente os tópicos ao ser criado um objeto Broker. As conexões abertas
	são armazenadas em um vetor endereços dentro da classe Tópicos.

*/
class Broker {
public:
	Broker();
	virtual ~Broker(){};
	// Serializa a mensagem em ASN1 com o valor da mensagem(recebido por publish) e o tópico e enviar para um sub.
	void sendNotify(string  addr, string valor, string assOID, int port,Connection * s);
	// Ao receber um mensagem tipo Publish é verificado o respectivo tópico
	// e encaminado o valor contido em Publish, individualmente para cara integrante do vetor de subs cadastrados no tópico
	// do publish recebido.
	void recvPublish(string endIP,string assunto, string informacao);
	// Neste método, é adicionado o novo subscriber no vector de subs. Para tal, é verificado qual o tópico deseja se inscrever.
	void recvSubscriber(string addr, string issue, int port,Connection * s);
	// Todas as conexões entrantes são tratadas por este método. Sendo realizado a desserialização da mensagem e encaminhado
	// para os metodos que tratam as mensagens do padrão publish/subscriber.
	void recebePacote( TCPServerSocket * socke);
	// Retira da lista de subs o subscriber, informando de qual tópico se desejar desvincular.
    void recvUnsubscriber(string addr, string issue);
private:
	// Tópico é uma classe. Em nosso exemplo criamos três objetos do tipo tópicos: "1.1", "1.2" e "1.3". Cada tópico armazena uma lista
	// de subscribers.
	topicos Top[3];
	int idTopicos;
};

#endif /* BROKER_H_ */