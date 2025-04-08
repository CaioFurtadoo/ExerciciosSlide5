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

struct Node* menorValor(struct Node* raiz) {
    struct Node* atual = raiz;
    while (atual && atual->esquerda != NULL)
        atual = atual->esquerda;
    return atual;
}

struct Node* remover(struct Node* raiz, int valor) {
    if (raiz == NULL)
        return raiz;

    if (valor < raiz->valor)
        raiz->esquerda = remover(raiz->esquerda, valor);
    else if (valor > raiz->valor)
        raiz->direita = remover(raiz->direita, valor);
    else {
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }
        else if (raiz->esquerda == NULL) {
            struct Node* temp = raiz->direita;
            free(raiz);
            return temp;
        }
        else if (raiz->direita == NULL) {
            struct Node* temp = raiz->esquerda;
            free(raiz);
            return temp;
        }
        struct Node* temp = menorValor(raiz->direita);
        raiz->valor = temp->valor;
        raiz->direita = remover(raiz->direita, temp->valor);
    }
    return raiz;
}

void emOrdem(struct Node* raiz) {
    if (raiz != NULL) {
        emOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        emOrdem(raiz->direita);
    }
}

int main() {
    struct Node* raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(valores) / sizeof(valores[0]);

    for (int i = 0; i < n; i++)
        raiz = inserir(raiz, valores[i]);
        
    raiz = remover(raiz, 20);
    raiz = remover(raiz, 30);
    raiz = remover(raiz, 50);

    printf("Árvore em ordem crescente: ");
    emOrdem(raiz);
    printf("\n");

    return 0;
}
