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

    printf("Árvore em ordem crescente: ");
    emOrdem(raiz);
    printf("\n");

    return 0;
}
