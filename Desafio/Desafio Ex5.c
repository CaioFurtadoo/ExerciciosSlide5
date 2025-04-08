#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = novo->direita = NULL;
    return novo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

void buscar(No* raiz, int valor) {
    if (raiz == NULL) {
        printf("\nValor %d não foi encontrado na árvore.\n", valor);
        return;
    }

    if (valor == raiz->valor) {
        printf("\nValor %d encontrado!\n", valor);
    } else if (valor < raiz->valor) {
        buscar(raiz->esquerda, valor);
    } else {
        buscar(raiz->direita, valor);
    }
}

void exibirEmOrdem(No* raiz) {
    if (raiz != NULL) {
        exibirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        exibirEmOrdem(raiz->direita);
    }
}

No* encontrarMenor(No* raiz) {
    while (raiz && raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }
    return raiz;
}

No* remover(No* raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        if (raiz->esquerda == NULL) {
            No* temp = raiz->direita;
            free(raiz);
            return temp;
        } else if (raiz->direita == NULL) {
            No* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }

        No* substituto = encontrarMenor(raiz->direita);
        raiz->valor = substituto->valor;
        raiz->direita = remover(raiz->direita, substituto->valor);
    }

    return raiz;
}

int main() {
    No* raiz = NULL;
    int escolha, numero;

    do {
        printf("\n==============================\n");
        printf("     ÁRVORE BINÁRIA - MENU\n");
        printf("==============================\n");
        printf("1. Inserir um número\n");
        printf("2. Remover um número\n");
        printf("3. Buscar um número\n");
        printf("4. Mostrar valores em ordem\n");
        printf("0. Sair do programa\n");
        printf("------------------------------\n");
        printf("Escolha uma opção: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("\nDigite o valor que deseja inserir: ");
                scanf("%d", &numero);
                raiz = inserir(raiz, numero);
                printf("Valor %d inserido com sucesso!\n", numero);
                break;

            case 2:
                printf("\nDigite o valor que deseja remover: ");
                scanf("%d", &numero);
                raiz = remover(raiz, numero);
                printf("Se o valor existia, ele foi removido.\n");
                break;

            case 3:
                printf("\nQual valor deseja buscar? ");
                scanf("%d", &numero);
                buscar(raiz, numero);
                break;

            case 4:
                printf("\nValores na árvore (em ordem): ");
                exibirEmOrdem(raiz);
                printf("\n");
                break;

            case 0:
                printf("\nSaindo do programa...\n");
                break;

            default:
                printf("\nOpção inválida. Tente novamente.\n");
        }

    } while (escolha != 0);

    return 0;
}
