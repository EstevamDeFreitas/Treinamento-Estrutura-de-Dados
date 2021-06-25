#include <iostream>
#include "lista.h"

No* no(double valor) {
    No* temp = new No;
    temp->proximo = NULL;
    temp->valor = valor;
    return temp;
}

Lista::Lista() {
    inicio = NULL;
    fim = NULL;
}

void Lista::adicionar(double valor) {
    No* aux = no(valor);
    if (inicio == NULL) {
        inicio = aux;
        fim = aux;
    }
    else {
        fim->proximo = aux;
        fim = fim->proximo;
    }
}

void Lista::exibir() {
    No* aux = inicio;
    while (aux != NULL) {
        std::cout << aux->valor << "\n";
        aux = aux->proximo;
    }
}

void Lista::removerItem(double valor) {
    bool primeiro_loop = true;
    No* aux = inicio;
    No* anterior = inicio;
    if (contem(valor)) {
        while (aux != NULL) {
            if (aux->valor == valor) {
                if (aux == inicio) {
                    inicio = aux->proximo;
                    delete aux;
                    aux = NULL;
                    return;
                }
                else if (aux == fim) {
                    anterior->proximo = NULL;
                    fim = anterior;
                    delete aux;
                    aux = NULL;
                    return;
                }
                else {
                    anterior->proximo = aux->proximo;
                    delete aux;
                    aux = NULL;
                    return;
                }

            }
            aux = aux->proximo;
            if (primeiro_loop) {
                primeiro_loop = false;
            }
            else {
                anterior = anterior->proximo;
            }
        }
    }
    else {
        std::cout << "Erro: item nao presente na lista\n";
    }
}

bool Lista::contem(double valor) {
    No* aux = inicio;
    while (aux != NULL) {
        if (aux->valor == valor) {
            return true;
        }
        aux = aux->proximo;
    }
    return false;
}

int Lista::tamanho() {
    No* aux = inicio;
    int tamanho = 0;
    while (aux != NULL) {
        tamanho++;
        aux = aux->proximo;
    }
    return tamanho;
}

double Lista::buscar(int posicao) {
    No* aux = inicio;
    int posicao_atual = 0;
    if (posicao < tamanho()) {
        while (aux != NULL) {
            if (posicao == posicao_atual) {
                return aux->valor;
            }
            aux = aux->proximo;
            posicao_atual++;
        }
    }
    else {
        std::cout << "Erro: tamanho menor que posicao indicada\n";
        return 0;
    }
}

void Lista::deletar() {
    No* aux = inicio;
    while (aux != NULL) {
        No* temp = aux;
        aux = aux->proximo;
        delete temp;
        temp = NULL;
    }
    inicio = NULL;
    fim = NULL;
}
