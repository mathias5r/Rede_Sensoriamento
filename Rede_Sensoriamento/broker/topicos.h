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


using namespace std;

class topicos {
public:	
	string assunto;	
	std::vector <std::string> endIP;
	std::vector <int> porta;
	int lenTopicos; //comprimento do vetor de assuntos

	topicos(){};
	topicos(string t){
		this->assunto = t;
	};
	void insertSub(string ip){
		endIP.insert(endIP.end(), ip);
	};
	void setAssunto(string t){
		this->assunto = t;
	}
	string consultaAssunto(){return this->assunto;};
	virtual ~topicos(){};


private:
	//vector <std::string> assuntos[] = {"1.2","1.2.3","1.1","1.4.1","1.4.2","1.4.3","1.4.4", "1.1","1.2","1.3"};

};
 #endif /* TOPICOS_H_ */

