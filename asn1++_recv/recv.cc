#include <parser_Ativo.h>
#include <iostream>
#include <sstream>
#include "TCPBaseSocket.h"

using namespace std;

int main() {
  TCPServerSocket sock(5555);

  cout << "Servidor esperando por conexões..." << endl;

  sock.wait(0);

  stringstream input;
  TAtivo::XerDeserializer decoder(input);

while (true) {

    try{

        Connection & con = sock.wait(0);

        string msg = con.recv(1024);
        cout << "Recebeu " << msg.size() << " bytes" << endl;
        input.write(msg.c_str(), msg.size()); 

        while (true) {
          // tenta decodificar uma estrutura de dados
          TAtivo * other = decoder.deserialize();

          cout << endl;

          if (other) {
            cout << "Estrutura de dados obtida da decodificação DER:" << endl;
            other->show();
          } else  break;

          // devem-se destruir explicitamente as estruturas de dados obtidas 
          // do decodificador 
          delete other;
        }
    }catch (TCPServerSocket::DisconnectedException e) {
            // esta exceção informa que uma conexão foi encerrada
            // o socket correspondente foi invalidado automaticamente
            cout << e.what() << ": " << e.get_addr() << ':';
            cout << e.get_port()<< endl;
    }
  }

  sock.close();
  return 0;
}
