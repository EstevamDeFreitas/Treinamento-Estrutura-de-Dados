//Constru��o da Lista ligada, com algumas opera��es para sua manipula��o

#pragma once

#include <iostream>

struct No {
    double valor;
    No* proximo;
};

No* no(double valor);

class Lista {
private:
    No* inicio, * fim;
public:
    Lista();

    void adicionar(double valor);

    void exibir();

    void removerItem(double valor);

    bool contem(double valor);

    int tamanho();

    double buscar(int posicao);

    void deletar();

};