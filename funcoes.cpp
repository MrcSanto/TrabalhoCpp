#include <iostream>
#include <stack>
using namespace std;

void cppPark(){
    cout <<
    "                     _____                _\n"
    "                    |  __ \\              | |\n"
    "  ___  _ __   _ __  | |__) |  __ _  _ __ | | __\n"
    " / __|| '_ \\ | '_ \\ |  ___/  / _` || '__|| |/ /\n"
    "| (__ | |_) || |_) || |     | (_| || |   |   <\n"
    " \\___|| .__/ | .__/ |_|      \\__,_||_|   |_|\\_\\ \n"
    "      | |    | | \n"
    "      |_|    |_| \n"
    "\n"
    "\n";

}

int tamanho(stack<string> pilha){
    int contador = 0;
    while(!pilha.empty()){
        pilha.pop();
        contador++;
    }
    return contador -1 ;
}

void invertePilha(stack<string> pilha1, stack<string> pilha2 ){ // funcao para inverter ou restaurar uma pilha
    while(!pilha1.empty()){        
        string topo = pilha1.top();
        pilha2.push(topo);
        pilha1.pop();
    }
}
    
bool verificaCarro(const stack<string> &estacionamento, string placa){
    stack<string> pilha = estacionamento;
    while(!pilha.empty()){
        string topo = pilha.top();
        pilha.pop();
        if(placa == topo){
            return true;
        }
    }
    return false;
}

void retiraCarro(stack<string> &estacionamento, stack<string> &manobra, string placa){
    if(verificaCarro(estacionamento, placa)){
        while(!estacionamento.empty()){
            string topo = estacionamento.top();
            if(placa == topo){
               cout << "Tem " << tamanho(manobra)+1 << " carro(s) na sua frente para retirar." << endl;
               estacionamento.pop();
               break;
            }
            manobra.push(topo); //adiciona a outra pilha
            estacionamento.pop();
       }
       restauraPilha(manobra, estacionamento);
    }else{
        cout << placa << "nao esta estacionado aqui" << endl;
    }
}
