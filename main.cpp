#include <iostream>
#include <stack> //importando biblioteca stack -- pilha 
#include "funcoes.cpp" // importa a minha biblioteca de funçoes
#include <regex>
using namespace std;

int main() {
    stack<string> estacionamento, manobra; //criando pilha de estacionamento e manobra
    int opcao; 
    cppPark();

    while(true){ //cria um loop 
        
        cout << "==============================\n";
        cout << "*  0 Para Sair\n";
        cout << "*  1 Registrar Entrada\n";
        cout << "*  2 Registrar Saida\n";
        cout << "*  3 Consultar Vaga\n";
        cout << "==============================\n";
        cout << endl;

        cin >> opcao; // entrada da opção selecionada

        string placaCarro; //variavel da placa do carro

        switch(opcao){ //vou usar switchCase para ficar mais organizado
            case 0:
                cout << "Obrigado!!" << endl;
                return 0;
            case 1:
                {
                    if(estacionamento.size() == 8){ //se estacionamento estiver cheio nao permite entrada de carros
                        cout << "Não há mais vagas!!" << endl;
                        cout << endl;
                        break;
                    }else{
                        int size = 8 - estacionamento.size(); //cria uma varivel para quantos carros ainda podem entrar no estacionamento
                        cout << "Ainda há " << size << " vagas sobrando!!\nInsira a placa do seu carro: ";
                        cin.ignore(); //ignora qualquer caracter que tenha ficado 'esperando'
                        getline(cin, placaCarro);
                        if(verificaCarro(estacionamento, placaCarro)){ //usa funcao, se for true executa as linhas de codigo abaixo
                            cout << "Ja existe uma carro igual! Tente novamente." << endl;
                            cout << endl;
                            break;
                        }else if(ex_regular(placaCarro)){
                            cout << "O modelo da sua placa não é compativel! Tente novamente." << endl;
                            cout << endl;
                            break;
                        }else{ // se for false, da continuidade a entrada de informações do carro
                            estacionamento.push(placaCarro);
                            cout << endl;
                        }
                    }
                }
                break;
            case 2:
                {
                    if(estacionamento.empty()){ // se estacionamento estiver vazio não tem nada para tirar
                        cout << "Estacionamento Vazio!!" << endl;
                        cout << endl;
                        break;
                    }else{ // se tiver carros, executa as linhas abaixo
                        cout << "Insira a placa do carro a ser retirado: ";
                        cin >> placaCarro;
                        retiraCarro(estacionamento, manobra, placaCarro); // os valores estao sendo passados por REFERENCIA
                    }
                }
                break;
            case 3:
                {
                    stack<string> temp; //cria pilha temporaria para inverter a ordem dos carros -- fica melhor para a saída dos dados
                    while(!estacionamento.empty()){
                        string topo = estacionamento.top();
                        temp.push(topo);
                        estacionamento.pop();
                    }

                    int contador = 1; //contador para exibir a ordem de chegada
                    while(!temp.empty()){
                        string topo = temp.top();
                        cout << contador++ << "°: " << topo << " --->  (" << tamanho(temp) << " carros na frente)" << endl;
                        temp.pop();
                        estacionamento.push(topo); // aqui vai retirando os elementos da pilha temp, ate nao sobrar mais nada
                    }
                    cout << endl;
                }
                break;
            default:
                cout << "Opcao incorreta, tente novamente!!" << endl;
                cout << endl;
                break;
        }
    }
    return 0;
}
