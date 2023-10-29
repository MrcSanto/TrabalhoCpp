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
    return contador-1;
}

void restauraPilha(stack<string> &pilha1, stack<string> &pilha2 ){
    while(!pilha1.empty()){
        string topo = pilha1.top();
        pilha2.push(topo);
        pilha1.pop();
    }
}
/* ver pq nao funciona
bool verificaPlaca(const stack<string> &estacionamento){
    stack<string> pilha = estacionamento;
    while(!pilha.empty()){
        string placa = pilha.top();
        pilha.pop();

        stack<string> comparacao = pilha;
        while(!comparacao.empty()){
            if(placa == comparacao.top()){
                return true;
            }
            comparacao.pop();
        }
    }
    return false;
}
*/
void retiraCarro(stack<string> &estacionamento, stack<string> &manobra, string placa){
    int contador = -1;
    while(!estacionamento.empty()){
        string elemento = estacionamento.top();
        estacionamento.pop();
        manobra.push(elemento);
        ++contador;
        if(elemento == placa){
            cout << "Tem " << contador << " carro(s) na sua frente para retirar" << endl;
            estacionamento.pop();
        }else{
            cout << "Não há tal carro estacionado!! Tente novamente." << endl;
            break;
        }
    }
    restauraPilha(manobra, estacionamento);

}
