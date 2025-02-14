#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da estrutura do prato
typedef struct Prato {
    char nome[50];
    struct Prato* proximo;
} Prato;

// Função para criar um novo prato
Prato* criarPrato(const char* nome) {
    Prato* novoPrato = (Prato*)malloc(sizeof(Prato));
    if (novoPrato == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    strcpy(novoPrato->nome, nome);
    novoPrato->proximo = NULL;
    return novoPrato;
}

// Função para adicionar um prato à pilha
void adicionarPrato(Prato** topo, const char* nome) {
    Prato* novoPrato = criarPrato(nome);
    novoPrato->proximo = *topo;
    *topo = novoPrato;
    printf("Prato %s adicionado à pilha.\n", nome);
}

// Função para remover um prato do topo da pilha
void removerPrato(Prato** topo) {
    if (*topo == NULL) {
        printf("Nenhum prato na pilha para remover.\n");
        return;
    }
    Prato* pratoRemovido = *topo;
    *topo = (*topo)->proximo;
    printf("Prato %s removido da pilha.\n", pratoRemovido->nome);
    free(pratoRemovido);
}

// Função para exibir todos os pratos na pilha
void exibirPratos(const Prato* topo) {
    if (topo == NULL) {
        printf("Nenhum prato na pilha.\n");
        return;
    }
    const Prato* atual = topo;
    printf("Pratos na pilha:\n");
    while (atual != NULL) {
        printf("%s\n", atual->nome);
        atual = atual->proximo;
    }
}

// Função principal
int main() {
    Prato* topo = NULL;
    int opcao;
    char nome[50];

    do {
        printf("\nMenu de Operações:\n");
        printf("1. Adicionar prato à pilha\n");
        printf("2. Remover prato do topo da pilha\n");
        printf("3. Exibir todos os pratos na pilha\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer de entrada

        switch (opcao) {
            case 1:
                printf("Digite o nome do prato: ");
                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; // Remover a nova linha
                adicionarPrato(&topo, nome);
                break;
            case 2:
                removerPrato(&topo);
                break;
            case 3:
                exibirPratos(topo);
                break;
            case 4:
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 4);

    // Liberar a memória alocada para a pilha de pratos
    while (topo != NULL) {
        Prato* temp = topo;
        topo = topo->proximo;
        free(temp);
    }

    return 0;
}
