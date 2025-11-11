
// Desafio Detective Quest
// Tema 4 - Árvores e Tabela Hash


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Sala {
    char nome[50];
    struct Sala *esquerda;
    struct Sala *direita;
} Sala;

Sala* criarSala(const char *nome) {
    Sala *nova = (Sala*)malloc(sizeof(Sala));
    if (!nova) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    strcpy(nova->nome, nome);
    nova->esquerda = NULL;
    nova->direita = NULL;
    return nova;
}

void conectarSalas(Sala *pai, Sala *esq, Sala *dir) {
    pai->esquerda = esq;
    pai->direita = dir;
}

void explorarSalas(Sala *atual) {
    char opcao;
    while (1) {
        printf("\nVocê está em: %s\n", atual->nome);

        if (!atual->esquerda && !atual->direita) {
            printf("Fim do caminho! Não há mais portas aqui.\n");
            return;
        }

        printf("Para onde deseja ir?\n");
        if (atual->esquerda) printf(" (e) Esquerda -> %s\n", atual->esquerda->nome);
        if (atual->direita)  printf(" (d) Direita  -> %s\n", atual->direita->nome);
        printf(" (s) Sair da exploração\nEscolha: ");
        scanf(" %c", &opcao);

        if (opcao == 's' || opcao == 'S') {
            printf("Você decidiu encerrar a exploração.\n");
            break;
        } else if ((opcao == 'e' || opcao == 'E') && atual->esquerda) {
            atual = atual->esquerda;
        } else if ((opcao == 'd' || opcao == 'D') && atual->direita) {
            atual = atual->direita;
        } else {
            printf("Opção inválida ou caminho inexistente. Tente novamente.\n");
        }
    }
}

int main() {
    // Criação das salas
    Sala *hall = criarSala("Hall de Entrada");
    Sala *biblioteca = criarSala("Biblioteca");
    Sala *cozinha = criarSala("Cozinha");
    Sala *sotao = criarSala("Sótão");
    Sala *jardim = criarSala("Jardim");

    // Conexão das salas (árvore fixa)
    conectarSalas(hall, biblioteca, cozinha);
    conectarSalas(biblioteca, sotao, NULL);
    conectarSalas(cozinha, NULL, jardim);

    // Início do jogo
    printf("🏰 Bem-vindo à Mansão Misteriosa!\n");
    explorarSalas(hall);

    // Liberação de memória
    free(sotao);
    free(jardim);
    free(biblioteca);
    free(cozinha);
    free(hall);

    printf("\nObrigado por jogar Detective Quest - Nível Novato!\n");
    return 0;
}