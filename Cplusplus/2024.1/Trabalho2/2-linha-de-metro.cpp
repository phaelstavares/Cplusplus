#include <iostream>
#include <string>

// Definição da estrutura da estação
struct Estacao {
    std::string nome;
    Estacao* proxima;

    // Construtor para inicializar uma nova estação
    Estacao(const std::string& nome) : nome(nome), proxima(nullptr) {}
};

// Função para adicionar uma estação à linha
void adicionarEstacao(Estacao*& linha, const std::string& nome) {
    Estacao* novaEstacao = new Estacao(nome);
    if (linha == nullptr) {
        linha = novaEstacao;
    } else {
        Estacao* atual = linha;
        while (atual->proxima != nullptr) {
            atual = atual->proxima;
        }
        atual->proxima = novaEstacao;
    }
    std::cout << "Estação " << nome << " adicionada à linha.\n";
}

// Função para remover uma estação da linha
void removerEstacao(Estacao*& linha, const std::string& nome) {
    if (linha == nullptr) {
        std::cout << "Linha vazia, nenhuma estação para remover.\n";
        return;
    }

    Estacao* atual = linha;
    Estacao* anterior = nullptr;

    while (atual != nullptr && atual->nome != nome) {
        anterior = atual;
        atual = atual->proxima;
    }

    if (atual == nullptr) {
        std::cout << "Estação " << nome << " não encontrada na linha.\n";
        return;
    }

    if (anterior == nullptr) {
        linha = atual->proxima;
    } else {
        anterior->proxima = atual->proxima;
    }

    delete atual;
    std::cout << "Estação " << nome << " removida da linha.\n";
}

// Função para exibir todas as estações na linha
void exibirEstacoes(Estacao* linha) {
    if (linha == nullptr) {
        std::cout << "Nenhuma estação na linha.\n";
        return;
    }
    Estacao* atual = linha;
    std::cout << "Estações na linha:\n";
    while (atual != nullptr) {
        std::cout << atual->nome << "\n";
        atual = atual->proxima;
    }
}

// Função principal
int main() {
    Estacao* linha = nullptr;
    int opcao;
    std::string nome;

    do {
        std::cout << "\nMenu de Operações:\n";
        std::cout << "1. Adicionar estação à linha\n";
        std::cout << "2. Remover estação da linha\n";
        std::cout << "3. Exibir todas as estações na linha\n";
        std::cout << "4. Sair\n";
        std::cout << "Escolha uma opção: ";
        std::cin >> opcao;
        std::cin.ignore(); // Limpar o buffer de entrada

        switch (opcao) {
            case 1:
                std::cout << "Digite o nome da estação: ";
                std::getline(std::cin, nome);
                adicionarEstacao(linha, nome);
                break;
            case 2:
                std::cout << "Digite o nome da estação a ser removida: ";
                std::getline(std::cin, nome);
                removerEstacao(linha, nome);
                break;
            case 3:
                exibirEstacoes(linha);
                break;
            case 4:
                std::cout << "Saindo do programa...\n";
                break;
            default:
                std::cout << "Opção inválida. Tente novamente.\n";
        }
    } while (opcao != 4);

    // Liberar a memória alocada para a linha de metrô
    while (linha != nullptr) {
        Estacao* temp = linha;
        linha = linha->proxima;
        delete temp;
    }

    return 0;
}
