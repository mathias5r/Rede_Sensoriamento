/*
 * Device.cc
 *
 *  Created on: 25 de nov de 2016
 *      Author: mathias
 */

#include "Device.h"

Device::Device(int type, TCPBaseSocket & sock) : sock(sock) {
    if(type >= 0 && type <= 2){
        this->type = type;
    }else{
        cout << "Tipo de dispositivo não identificado: " << type << endl;    
    }
}

int Device::add_topic(char * name, char * atop){

    TAtivo pkt;
    TAtivo::Choice_id & id = pkt.get_id();
    TIniciate i = id.get_iniciate();

    i.set_name(name);
    i.set_atop(atop);
    i.set_type(this->type); // True - Publish, False - Subscriber

    pkt.check_constraints();
    pkt.show();

    ostringstream output;
    TAtivo::XerSerializer encoder(output);
    encoder.serialize(pkt);
    string data = output.str();

    try{
        cout << "Sent: " << this->sock.send(data) << " bytes de " << data.size() << endl;
    }catch (TCPServerSocket::DisconnectedException e) {
        cout << e.what() << ": " << e.get_addr() << ':';
        cout << e.get_port()<< endl;
        return -1;
    }

    return data.size();
}

int Device::receive(char * buffer){

    TAtivo pkt;
    TAtivo::Choice_id & id = pkt.get_id();
    TData d = id.get_data();

    d.set_payload(buffer);
    
    pkt.check_constraints();
    pkt.show();

    ostringstream output;
    TAtivo::XerSerializer encoder(output);
    encoder.serialize(pkt);
    string data = output.str();

    try{
        cout << "Sent: " << this->sock.send(data) << " bytes de " << data.size() << endl;
    }catch (TCPServerSocket::DisconnectedException e) {
        cout << e.what() << ": " << e.get_addr() << ':';
        cout << e.get_port()<< endl;
        return -1;
    }

    return data.size();    
}


int Device::send(char * buffer){

    stringstream input;
    TAtivo::XerDeserializer decoder(input);

    string msg;
    
    try{
        msg = sock.recv(1024);
        cout << "Recebeu " << msg.size() << " bytes" << endl;
    }catch (TCPServerSocket::DisconnectedException e) {
        cout << e.what() << ": " << e.get_addr() << ':';
        cout << e.get_port()<< endl;
        return -1;
    }

    input.write(msg.c_str(), msg.size()); 

    TAtivo * other = decoder.deserialize();
    TAtivo::Choice_id & id = other->get_id();
    TData d = id.get_data();

    buffer = (char *)d.get_payload().c_str();
  
    return msg.size();
}
    

