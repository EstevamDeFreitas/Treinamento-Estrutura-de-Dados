//Construção da Fila, com algumas operações para sua manipulação

#pragma once

struct Enfileirado {
	double valor;
	Enfileirado* proximo;
};

Enfileirado* novoEnfileiramento(double valor);

class Fila {
private:
	Enfileirado* primeiro;
	Enfileirado* ultimo;
	int tamanho = 0;
public:
	Fila(int tamanho);

	void enfileirar(double valor);

	double desenfileirar();

	void exibirFila();

	bool vazia();

	bool cheia();

	int qtdaElementos();

	void deleta();
};