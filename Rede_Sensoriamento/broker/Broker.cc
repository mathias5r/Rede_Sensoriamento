/*
 * broker.cpp
 *
 *  Created on: 25/11/2016
 *      Author: ronaldo
 */
#include "Broker.h"

using namespace std;

Broker::Broker() {
    Top[0].setAssunto("1.1");
    Top[1].setAssunto("1.2");
    Top[2].setAssunto("1.3");
        idTopicos = 3;

}

void Broker::sendNotify(string addr, string * valor, string assOID)
{

    TAtivo pkt;
    TAtivo::Choice_id & id = pkt.get_id();
    TNotify da = id.get_notify();
    da.set_hierarchy(assOID);
    char * aux = new char[10];
    sprintf(aux,"%d",valor);
    da.set_data(aux);
    pkt.check_constraints();
    pkt.show();
    ostringstream output;
    TAtivo::XerSerializer encoder(output);
    encoder.serialize(pkt);
    string data = output.str();
    TCPClientSocket sockNotify(addr,2222);
    //sockNotify.connect();
    try{
        cout << "Notify: " << sockNotify.send(data) << " bytes de " << data.size() << endl;
        
        //cout << "Data: " << sockNotify.send(data) << " bytes de " << data.size() << endl;
    }catch (TCPServerSocket::DisconnectedException e) {
        cout << e.what() << ": " << e.get_addr() << ':';
        cout << e.get_port()<< endl;
    }
    sockNotify.close();
}



void Broker::recvPublish(string addr,string assunto, string informacao){
    cout << "Entrou no recvPublish" << endl;
    for(int i =0; i < this->idTopicos; i++){
        cout << "valor de assunto" << assunto << endl;
        cout << "Valor de consultaAssunto"<< this->Top[i].consultaAssunto() << endl;
        if(this->Top[i].consultaAssunto() == assunto){
            cout << "Assunto cadastrado" << endl;
            cout << "Assunto cadastrado no topico"<< i << endl;
            int idIP = this->Top[i].endIP.size();
            for(int ii = 0;ii < idIP;ii++){
                //sendNotify(this->Top[i].endIP[ii],&informacao,assunto,this->Top[i].porta[ii]);
                sendNotify(this->Top[i].endIP[ii],&informacao,assunto);
            }
        }
    }
}
void Broker::recvSubscriber(string addr, string issue, int port){
//void Broker::recvSubscriber(string addr, int tipo, string issue, string port){
    int i = this->idTopicos;
    for ( int i; i < this->idTopicos; i++)
    {
        if(this->Top[i].assunto == issue)
        {
            this->Top[i].endIP.insert(this->Top[i].endIP.end(),addr);
            //this->Top[i].porta.insert(this->Top[i].porta.end(),port);
        }
    }
}

void Broker::recebePacote(TCPServerSocket & sock){
    //void recebePacote(TCPClientSocket & socke);
 stringstream input;
    TAtivo::XerDeserializer decoder(input);
     while(true){
    try{
         Connection & socke = sock.wait(0);
        //
        string addr;
        unsigned short port;
        socke.get_peer(addr, port);
      
        //string ip = sock.get_ip();
        // conseguiu ler algo desse socket ...
        string msg = socke.recv(1024);
        if (socke.isNew()) {                
                cout << "Nova conexão: " << addr << ':' << port << endl;

            } else { 
            
              if (msg.size()) {                
                // ...mostra-os na tela e envia-os de volta
                // para a outra ponta da conexão
                cout << "recebeu de " << addr << ':' << port;
                cout << ": " << msg << endl;
 
                //msg = "recebido: " + msg;
                //sock.send(data);
    cout << "Antes de input write:"<< endl;
    input.write(msg.c_str(), msg.size());
    cout << "Apos de input write:"<< endl;
    TAtivo * other = decoder.deserialize();
    TAtivo::Choice_id & id = other->get_id();
    //falta testar se é do tipo connect.
    //string = 
    cout << "Valor get_choice: " << id.get_choice() << endl;
     //cout << "Valor bb antes: " << bb << endl;
    int bb = id.get_choice();
    //string topico = id.get_atop();
    //string name = id.get_name();
        cout << "Valor bb depois: " << bb << endl;
    if ( bb = 1  ){ //publish
        //eh um publish
        TPublish co = id.get_publish();
        //ASN1Oid assunto = co.get_hierarchy_attr();
        string assunto  = co.get_hierarchy();
        cout << "Valor assunto: " << assunto << endl;
        string informacao = co.get_data();
        cout << "Valor info: " << informacao << endl;
        recvPublish(addr,assunto,informacao);


    }else if(bb = 2){ //subscriber
        //eh um subscriber;
         TSubscriber ci = id.get_subscriber();
         //ASN1Oid assunto = ci.get_hierarchy_attr();
         string assunto = ci.get_hierarchy();
        recvSubscriber(addr,assunto,port);
        
    }else if(bb = Broker::id_PR_Unsubscriber){
        //eh um publish e subscriber
        TUnsubscriber ce = id.get_unsubscriber();
        ASN1Oid assunto = ce.get_hierarchy_attr();
        //recvUnSubscriber(addr);
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
        //cout << "Recebeu " << msg.size() << endl;
        //cout << "MSG " << msg  << endl;
        //cout << "addr " << addr  << endl;





    }

}