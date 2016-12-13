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
 cout << "-----------Entrou no notify--------:"<< endl;
 cout << "Valor da informaçao"<< valor << endl;
    TAtivo pkt;
    TAtivo::Choice_id & id = pkt.get_id();
    TNotify da = id.get_notify();
    da.set_hierarchy(assOID);
    char * aux = new char[10];
    //sprintf(aux,"%s",valor);
    da.set_data(valor);
    pkt.check_constraints();
    pkt.show();
    ostringstream output;
    TAtivo::XerSerializer encoder(output);
    encoder.serialize(pkt);
    string data = output.str();
    cout << "-----------Envia notify--------:"<< endl;
    //TCPClientSocket sockNotify(addr,port);
    //sockNotify.connect();
    try{
        cout << "Notify: " << s->send(data) << " bytes de " << data.size() << endl;
        
        //cout << "Data: " << sockNotify.send(data) << " bytes de " << data.size() << endl;
    }catch (TCPServerSocket::DisconnectedException e) {
        cout << e.what() << ": " << e.get_addr() << ':';
        cout << e.get_port()<< endl;
    }
    //sockNotify.close();
}



void Broker::recvPublish(string addr,string assunto, string informacao){
    cout << "Entrou no recvPublish" << endl;
    for(int i =0; i < this->idTopicos; i++){
        cout << "valor de assunto" << assunto << endl;
        cout << "Valor de consultaAssunto"<< Top[i].consultaAssunto() << endl;
        if(this->Top[i].consultaAssunto() == assunto){
            cout << "Assunto cadastrado" << endl;
            cout << "Assunto cadastrado no topico"<< i << endl;
            cout << "Tamanho da fila de IPs"<< Top[i].endIP.size() << endl;
            int idIP = Top[i].endIP.size();
            for(int ii = 0;ii < idIP;ii++){
                 cout << "-----------Entrou no notify--------:"<< endl;
                sendNotify(Top[i].endIP[ii],informacao,assunto,Top[i].porta[ii],Top[i].si[ii]);

                //sendNotify(this->Top[i].endIP[ii],&informacao,assunto);
            }
        }
    }
}
//void Broker::recvSubscriber(string addr, string issue, int port, TCPServerSocket & s){
void Broker::recvSubscriber(string addr, string issue, int port, Connection * s){
//void Broker::recvSubscriber(string addr, int tipo, string issue, string port){
    //int i = this->idTopicos;
    for ( int i=0; i < this->idTopicos; i++)
    {
        if(this->Top[i].consultaAssunto() == issue)
        {
            cout << "cadastrado participante"<< endl;
            cout << "cadastrado participante no topico"<< i << endl;
            Top[i].endIP.insert(Top[i].endIP.end(),addr);
            Top[i].porta.insert(Top[i].porta.end(),port);
            Top[i].si.insert(Top[i].si.end(),s);
            cout << "Tamanho da fila de IPs"<< Top[i].endIP.size() << endl;
        }
    }
    return;
}

void Broker::recebePacote(TCPServerSocket * sock){
    //void recebePacote(TCPClientSocket & socke);

 stringstream input;
    TAtivo::XerDeserializer decoder(input);
     while(true){
    try{
         Connection & socke = sock->wait(0);
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
 
    input.write(msg.c_str(), msg.size());

    TAtivo * other = decoder.deserialize();
    cout << "Apos de decoder:"<< endl;
    TAtivo::Choice_id & id = other->get_id();
    cout << "depois de decoder"<< endl;
    //falta testar se é do tipo connect.
   
    //string = 
    cout << "Valor get_choice: " << id.get_choice() << endl;
     //cout << "Valor bb antes: " << bb << endl;
    int bb = id.get_choice();
    //string topico = id.get_atop();
    //string name = id.get_name();
        cout << "Valor bb depois: " << bb << endl;
    if ( bb == 1  ){ //publish
        //eh um publish
        cout << "Mensagem publish: " << endl;
        TPublish co = id.get_publish();
        //ASN1Oid assunto = co.get_hierarchy_attr();
        string assunto  = co.get_hierarchy();
        cout << "Valor assunto: " << assunto << endl;
        string informacao = co.get_data();
        cout << "Valor info: " << informacao << endl;
        recvPublish(addr,assunto,informacao);


    }else if(bb == 2){ //subscriber
        //eh um subscriber;
          cout << "Mensagem subscriber: " << endl;
         TSubscriber ci = id.get_subscriber();
         //cout << "Valor id.get_subscriber: " << id.get_subscriber() << endl;
         cout << "Valor id.get_hierarchy: " << ci.get_hierarchy() << endl;
         //ASN1Oid assunto = ci.get_hierarchy_attr();
         string assunto = ci.get_hierarchy();

        recvSubscriber(addr,assunto,port,&socke);
        //recvSubscriber(addr,assunto,port,*sock);
        
    }else if(bb == 3){
        //eh um publish e subscriber
        cout << "Mensagem recvUnSubscriber: " << endl;
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

    return;



    }

}