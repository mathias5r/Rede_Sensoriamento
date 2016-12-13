#include <iostream>	
#include <cstdlib>
#include <ctime>
#include "Device.h"
#include "Database.h"
#include <unistd.h>

using namespace std;

int main() {
 
    string broker_ip = "10.0.0.2";
    string topic = "1.1";
    
    Device sensor(broker_ip,DEFAULT_PORT);
   
    char * buffer = new char[256];

    //while(1){
        srand((unsigned)time(0)); //para gerar números aleatórios reais.
        int maior = 100;
        int menor = 30;
        int aleatorio = rand()%(maior-menor+1) + menor;
        std::cout << "Value = " << aleatorio << std::endl;
        ostringstream msg;
        msg << "Val: " << aleatorio; 
        if(sensor.publish(msg.str(),topic)){
            cout << "Publish Realizado com Sucesso!" << endl;
        }else{
            cout << "Publish Falhou!" << endl;
        }
        //sleep(5);
        //cout << "TESTE" << endl;
    //}
}
