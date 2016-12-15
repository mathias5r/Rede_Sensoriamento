/*
 * broker.cpp
 *
 *  Created on: 25/11/2016
 *      Author: ronaldo
 */
#include "Broker.h"
#include <pthread.h>

 using namespace std;

 Broker::Broker() {
    Top[0].setAssunto("1.1");
    Top[1].setAssunto("1.2");
    Top[2].setAssunto("1.3");
    idTopicos = 3;

}

void Broker::sendNotify(string addr, string  valor, string assOID, int port,Connection * s)
{
   TAtivo pkt;
   TAtivo::Choice_id & id = pkt.get_id();
   TNotify da = id.get_notify();
   da.set_hierarchy(assOID);
   char * aux = new char[10];
   da.set_data(valor);
   pkt.check_constraints();
   pkt.show();
   ostringstream output;
   TAtivo::XerSerializer encoder(output);
   encoder.serialize(pkt);
   string data = output.str();

   try{
    cout << "Notify: " << s->send(data) << " bytes de " << data.size() << endl;
    }catch (TCPServerSocket::DisconnectedException e) {
        cout << e.what() << ": " << e.get_addr() << ':';
        cout << e.get_port()<< endl;
    }
}



void Broker::recvPublish(string addr,string assunto, string informacao){
    for(int i =0; i < this->idTopicos; i++){
        if(this->Top[i].consultaAssunto() == assunto){
            int idIP = Top[i].endIP.size();
            for(int ii = 0;ii < idIP;ii++) sendNotify(Top[i].endIP[ii],informacao,assunto,Top[i].porta[ii],Top[i].si[ii]);
        }
    }
}

void Broker::recvSubscriber(string addr, string issue, int port, Connection * s){
    for ( int i=0; i < this->idTopicos; i++)
    {
        if(this->Top[i].consultaAssunto() == issue)
        {
            Top[i].endIP.insert(Top[i].endIP.end(),addr);
            Top[i].porta.insert(Top[i].porta.end(),port);
            Top[i].si.insert(Top[i].si.end(),s);
        }
    }
    return;
}

void Broker::recvUnsubscriber(string addr, string issue){
    for ( int i=0; i < this->idTopicos; i++)
    {
        if(this->Top[i].consultaAssunto() == issue)
        {
            int j;
            for( j=0 ; j < Top[i].endIP.size() ; i++ ){
                if( this->Top[i].endIP.at(j) == addr ){
                    this->Top[i].endIP.erase(this->Top[i].endIP.begin()+j);
                    this->Top[i].porta.erase(this->Top[i].porta.begin()+j);
                    this->Top[i].si.erase(this->Top[i].si.begin()+j);
                }
            }
        }
    }
}
void Broker::recebePacote(TCPServerSocket * sock){
    stringstream input;
    TAtivo::XerDeserializer decoder(input);
    while(true){
        try{
         Connection & socke = sock->wait(0);
         string addr;
         unsigned short port;
         socke.get_peer(addr, port);
         string msg = socke.recv(1024);
        if (socke.isNew()) {                
            cout << "Nova conexão: " << addr << ':' << port << endl;
        }else { 
            if (msg.size()) {                
                cout << "recebeu de " << addr << ':' << port;
                cout << ": " << msg << endl;

                input.write(msg.c_str(), msg.size());
                TAtivo * other = decoder.deserialize();
                TAtivo::Choice_id & id = other->get_id();
                int bb = id.get_choice();
                if ( bb == 1  ){ //publish
                    cout << "Mensagem publish: " << endl;
                    TPublish co = id.get_publish();
                    string assunto  = co.get_hierarchy();
                    string informacao = co.get_data();
                    recvPublish(addr,assunto,informacao);
                }else if(bb == 2){ //subscriber
                    cout << "Mensagem subscriber: " << endl;
                    TSubscriber ci = id.get_subscriber();
                    string assunto = ci.get_hierarchy();
                    recvSubscriber(addr,assunto,port,&socke);
                }else if(bb == 4){
                    //eh um unsubcriber
                    cout << "Mensagem UnSubscriber: " << endl;
                    TUnsubscriber ce = id.get_unsubscriber();
                    string assunto = ce.get_hierarchy();
                    recvUnsubscriber(addr,assunto);
                }
                cout << endl;

                if (other) {
                    cout << "Estrutura de dados obtida da decodificação DER:" << endl;
                    other->show();
                }

                delete other;
            }    
        }
    }catch(TCPServerSocket::DisconnectedException e) {
        cout << e.what() << ": " << e.get_addr() << ':';
        cout << e.get_port()<< endl;
    }
    return;
    }

}