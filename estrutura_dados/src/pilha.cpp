#include <iostream>
#include "pilha.h"

Elemento* elementoNovo(double valor, Elemento* anterior) {
	Elemento* temp = new Elemento;
	temp->proximo = anterior;
	temp->valor = valor;
	return temp;
}

Pilha::Pilha() {
	extremidade = NULL;
}

double Pilha::topo() {
	return extremidade->valor;
}

void Pilha::empurra(double valor) {
	Elemento* aux = elementoNovo(valor, extremidade);
	extremidade = aux;
}

double Pilha::puxa() {
	if (extremidade != NULL) {
		Elemento* aux = extremidade;
		double temp = aux->valor;
		if (extremidade->proximo != NULL) {
			extremidade = extremidade->proximo;
			delete aux;
			aux = NULL;
			return temp;
		}
		else {
			extremidade = NULL;
			delete aux;
			aux = NULL;
			return temp;
		}
	}
	else {
		std::cout << "Erro: Pilha vazia\n";
		return 0;
	}
}

void Pilha::deleta() {
	if (extremidade == NULL) return;
	Elemento* aux = extremidade;
	extremidade = extremidade->proximo;
	delete aux; 
	aux = NULL;
	return deleta();
}

bool Pilha::vazia() {
	return extremidade == NULL ? true : false;
}