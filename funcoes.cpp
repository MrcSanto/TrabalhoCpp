#include <iostream>
#include <stack>
using namespace std;

void cppPark(){ // funcao para imprimir a logo cppPark
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

int tamanho(stack<string> pilha){ //funcao int para retornar o tamanho de uma pilha
    int contador = 0;             // vai ser usado na main e em outras funçoẽs
    while(!pilha.empty()){
        pilha.pop();
        contador++;             //usa passagem por parametro para nao afetar as pilhas originais
    }
    return contador -1 ;
}

void restauraPilha(stack<string> &pilha1, stack<string> &pilha2 ){ // funcao para restaurar uma pilha
    while(!pilha1.empty()){        
        string topo = pilha1.top();
        pilha2.push(topo);                  //serve para quando desempilhar uma pilha1 empilhar na pilha 2 novamente
        pilha1.pop();
    }
}
    
bool verificaCarro(const stack<string> &estacionamento, string placa){ //funcao para verificar se no input de placas há alguma repetida
    stack<string> pilha = estacionamento;
    while(!pilha.empty()){
        string topo = pilha.top();
        pilha.pop();
        if(placa == topo){ //aqui é feita a verificação das placas, se for true tem carros iguais e pede para inserir novamente
            return true;
        }
    }
    return false; // se for falso nao tem carros iguais, logo o programa continua a inserir os dados
}

void retiraCarro(stack<string> &estacionamento, stack<string> &manobra, string placa){ // funcao usada para retirar os carros do estacionamento
    if(verificaCarro(estacionamento, placa)){ // usa a funcao verificaCarro para validar se existe tal carro no input
        while(!estacionamento.empty()){
            string topo = estacionamento.top();
            if(placa == topo){ 
               cout << "Tem " << tamanho(manobra)+1 << " carro(s) na sua frente para retirar." << endl; //usa funcao tamanho
               estacionamento.pop(); // carro nao esta mais na area de manobra, foi embora
               break;
            }
            manobra.push(topo); //adiciona a outra pilha
            estacionamento.pop();
       }
       restauraPilha(manobra, estacionamento); // por meio da função restauraPilha é inserido os carros da Área de manobra para a Área de estacionamento
    }else{
        cout << "O carro " << placa << " não esta estacionado aqui!" << endl;
        cout << endl;
    }
}
