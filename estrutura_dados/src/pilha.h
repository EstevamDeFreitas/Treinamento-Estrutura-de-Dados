//Constru��o da estrutura pilha, com algumas opera��es

#pragma once

struct Elemento {
	double valor;
	Elemento* proximo;
};

Elemento* elementoNovo(double valor, Elemento* anterior);

class Pilha {
private:
	Elemento* extremidade;
public:
	Pilha();

	double topo();

	void empurra(double valor);

	double puxa();

	void deleta();

	bool vazia();
};
