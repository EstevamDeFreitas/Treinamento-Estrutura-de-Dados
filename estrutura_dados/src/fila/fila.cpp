#include <iostream>
#include "fila.h"

Enfileirado* novoEnfileiramento(double valor) {
	Enfileirado* aux = new Enfileirado;
	aux->proximo = NULL;
	aux->valor = valor;
	return aux;
}

Fila::Fila(int tamanho) {
	if (tamanho > 0) {
		this->tamanho = tamanho;
	}
	primeiro = NULL;
	ultimo = NULL;
}

void Fila::enfileirar(double valor) {
	if (tamanho > 0 && cheia()) {
		std::cout << "Erro: Fila cheia\n";
		return;
	}
	else {
		if (primeiro == NULL) {
			primeiro = novoEnfileiramento(valor);
			ultimo = primeiro;
		}
		else {
			Enfileirado* temp = ultimo;
			ultimo->proximo = novoEnfileiramento(valor);
			ultimo = ultimo->proximo;
		}
	}
	return;
}

double Fila::desenfileirar() {
	if (primeiro != NULL) {
		Enfileirado* temp = primeiro;
		double retorno = temp->valor;
		primeiro = primeiro->proximo;
		delete temp;
		temp = NULL;
		return retorno;
	}
	else {
		std::cout << "Erro: Fila vazia\n";
		return NULL;
	}
}

int Fila::qtdaElementos() {
	Enfileirado* temp = primeiro;
	int contagem = 0;
	while (temp != NULL) {
		contagem++;
		temp = temp->proximo;
	}
	return contagem;
}

void Fila::exibirFila() {
	Enfileirado* temp = primeiro;
	while (temp != NULL) {
		std::cout << temp->valor;
		temp = temp->proximo;
		if (temp != NULL) std::cout << " <- ";
		else std::cout << "\n";
	}
	if (primeiro == NULL) {
		std::cout << "A fila esta vazia\n";
	}
}

bool Fila::vazia() {
	return primeiro == NULL;
}

bool Fila::cheia() {
	return qtdaElementos() == tamanho;
}

void Fila::deleta() {
	while (primeiro != NULL) {
		Enfileirado* temp = primeiro;
		if (primeiro == ultimo) {
			ultimo == NULL;
		}
		primeiro = primeiro->proximo;
		delete temp;
		temp = NULL;
	}
}