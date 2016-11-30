/*
 * Sensor.h
 *
 *  Created on: 25 de nov de 2016
 *      Author: mathias
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#define INFO_SIZE 12
#define IP_SIZE 15
#define DEFAULT_PORT 5555

#include "TCPBaseSocket.h"
#include <parser_Ativo.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>

using namespace std;

class Sensor {
public:
	Sensor(char * info, char * ip, TCPClientSocket & sock);
	virtual ~Sensor();
	int get_value();
	void send_value();
	void subscriber();
private:
	char * info;
	char * ip;
	TCPClientSocket & sock;
};

#endif /* SENSOR_H_ */
