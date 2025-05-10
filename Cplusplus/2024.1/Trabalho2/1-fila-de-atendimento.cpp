#include <iostream>
#include <queue>
#include <string>

using namespace std;

void adicionarCliente(queue<string>& fila) {
    string nome;
    cout << "Digite o nome do cliente: ";
    cin >> nome;
    fila.push(nome);
    cout << "Cliente " << nome << " adicionado à fila de espera." << endl;
}

void atenderCliente(queue<string>& fila) {
    if (fila.empty()) {
        cout << "Nenhum cliente na fila de espera." << endl;
    } else {
        cout << "Cliente " << fila.front() << " atendido." << endl;
        fila.pop();
    }
}

void exibirFila(queue<string> fila) {
    if (fila.empty()) {
        cout << "Nenhum cliente na fila de espera." << endl;
    } else {
        cout << "Clientes na fila de espera:" << endl;
        while (!fila.empty()) {
            cout << fila.front() << endl;
            fila.pop();
        }
    }
}

int main() {
    queue<string> fila;
    int opcao;

    do {
        cout << "\nMenu de Operações:" << endl;
        cout << "1. Adicionar cliente à lista de espera" << endl;
        cout << "2. Atender cliente" << endl;
        cout << "3. Exibir todos os clientes na lista de espera" << endl;
        cout << "4. Sair" << endl;
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                adicionarCliente(fila);
                break;
            case 2:
                atenderCliente(fila);
                break;
            case 3:
                exibirFila(fila);
                break;
            case 4:
                cout << "Saindo do programa..." << endl;
                break;
            default:
                cout << "Opção inválida. Tente novamente." << endl;
        }
    } while (opcao != 4);

    return 0;
}