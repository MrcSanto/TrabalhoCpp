#include <iostream>
#include <stack> //importando biblioteca stack -- pilha 
#include "funcoes.cpp"
using namespace std;

int main() {
    stack<string> estacionamento, manobra; //criando pilha de estacionamento e manobra
    int opcao; 
    cppPark();

    while(true){
        
        cout << "*  0 Para Sair\n";
        cout << "*  1 Registrar Entrada\n";
        cout << "*  2 Registrar Saida\n";
        cout << "*  3 Consultar Vaga\n";
        cout << endl;

        cin >> opcao;

        string placaCarro; //variavel da placa do carro

        switch(opcao){
            case 0:
                cout << "Obrigado!!" << endl;
                return 0;
            case 1:
                {
                    if(estacionamento.size() == 8){
                        cout << "Não há mais vagas!!" << endl;
                        cout << endl;
                        break;
                    }else{
                        int size = 8 - estacionamento.size();
                        cout << "Ainda há " << size << " vagas sobrando!!\nInsira a placa do seu carro:";
                        cin.ignore();
                        getline(cin, placaCarro);
                        if(verificaCarro(estacionamento, placaCarro)){ //ver dps funciona parcialmente
                            cout << "Ja existe uma carro igual! Tente novamente." << endl;
                            cout << endl;
                            break;
                        }else{
                            estacionamento.push(placaCarro);
                            cout << endl;
                        }
                    }
                }
                break;
            case 2:
                {
                    if(estacionamento.empty()){
                        cout << "Estacionamento Vazio!!" << endl;
                        cout << endl;
                        break;
                    }else{

                        cout << "Insira a placa do carro a ser retirado:";
                        cin >> placaCarro;
                        retiraCarro(estacionamento, manobra, placaCarro);
                    }
                }
                break;
            case 3:
                {
                    stack<string> temp;
                    while(!estacionamento.empty()){
                        string topo = estacionamento.top();
                        temp.push(topo);
                        estacionamento.pop();
                    }

                    int contador = 1;
                    while(!temp.empty()){
                        string topo = temp.top();
                        cout << contador++ << "°: " << topo << " --->  (" << tamanho(temp) << " carros na frente)" << endl;
                        temp.pop();
                        estacionamento.push(topo);
                    }
                    cout << endl;
                }
                break;
            case 4:
                while(!manobra.empty()){

                    string topo = manobra.top();
                    cout << topo << endl;
                    manobra.pop();
                }
                break;
            default:
                cout << "Opcao incorreta, tente novamente!!" << endl;;
                break;
        }


    }
    return 0;
}
