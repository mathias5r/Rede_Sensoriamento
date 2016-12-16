/*
 * topicos.h
 *
 *  Created on: 25/11/2016
 *      Author: ronaldo
 */

#ifndef TOPICOS_H_
#define TOPICOS_H_

#include <sys/select.h>
#include <sys/time.h>
#include <unistd.h>
#include <iostream>
#include <fcntl.h>
#include <pthread.h>
#include <list>
#include <string>
#include <cctype>
#include <vector>
#include "TCPBaseSocket.h"

 /*
 O modelo do projeto é referenciado pelo tópico. Cada tópico será um objeto que possuirá uma lista de subscribers. 
 Os métodos são para inserir novos subscribers no vetor de subs, consultar o tópico.
 Neste modelo não é usado a opção de acesso a hierarquia do tópico. O acesso ao tópico é pelo caminho absoluto.


 */
using namespace std;

class topicos {
public:	
	string assunto;	
	// O vetor de sub é composto por endereço IP, porta, e Connection.
	std::vector <std::string> endIP;
	std::vector <int> porta;
	std::vector <TCPServerSocket> ss;
	vector<Connection*> si;
	int lenTopicos; 
	topicos(){};
	topicos(string t){
		this->assunto = t;
	};
	// Insere um novo subscriber na lista de subs através do endereço IP.
	void insertSub(string ip){
		endIP.insert(endIP.end(), ip);
	};
	// Define o novo tópico.
	void setAssunto(string t){
		this->assunto = t;
	}
	// retorna um tópico existente.
	string consultaAssunto(){return this->assunto;};
	virtual ~topicos(){};


private:


};
 #endif /* TOPICOS_H_ */

