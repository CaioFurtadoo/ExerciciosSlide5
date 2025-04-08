#include <stdio.h>
#include <stdlib.h>

struct Node {
    int valor;
    struct Node* esquerda;
    struct Node* direita;
};

struct Node* novoNo(int valor) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->valor = valor;
    temp->esquerda = temp->direita = NULL;
    return temp;
}

struct Node* inserir(struct Node* raiz, int valor) {
    if (raiz == NULL)
        return novoNo(valor);

    if (valor < raiz->valor)
        raiz->esquerda = inserir(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = inserir(raiz->direita, valor);

    return raiz;
}

void buscar(struct Node* raiz, int valor) {
    if (raiz == NULL) {
        printf("Valor %d NÃO encontrado na árvore.\n", valor);
        return;
    }

    if (valor == raiz->valor) {
        printf("Valor %d encontrado na árvore.\n", valor);
    } else if (valor < raiz->valor) {
        buscar(raiz->esquerda, valor);
    } else {
        buscar(raiz->direita, valor);
    }
}

int main() {
    struct Node* raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++)
        raiz = inserir(raiz, valores[i]);

    int buscas[] = {60, 25, 40};
    int qtdBuscas = sizeof(buscas) / sizeof(buscas[0]);

    for (int i = 0; i < qtdBuscas; i++) {
        buscar(raiz, buscas[i]);
    }

    return 0;
}