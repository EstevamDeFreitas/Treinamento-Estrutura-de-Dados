//Construção da Fila, com algumas operações para sua manipulação

#pragma once

template <typename T>
struct Enfileirado {
	T valor;
	Enfileirado<T>* proximo;
};

template <typename C>
class Fila {
private:
	Enfileirado<C>* primeiro;
	Enfileirado<C>* ultimo;
	int tamanho = 0;

	Enfileirado<C>* novoEnfileiramento(C valor) {
		Enfileirado<C>* aux = new Enfileirado<C>;
		aux->proximo = NULL;
		aux->valor = valor;
		return aux;
	}
public:
	Fila(int tamanho) {
		if (tamanho > 0) {
			this->tamanho = tamanho;
		}
		primeiro = NULL;
		ultimo = NULL;
	}

	void enfileirar(C valor) {
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
				Enfileirado<C>* temp = ultimo;
				ultimo->proximo = novoEnfileiramento(valor);
				ultimo = ultimo->proximo;
			}
		}
		return;
	}

	C desenfileirar() {
		if (primeiro != NULL) {
			Enfileirado<C>* temp = primeiro;
			C retorno = temp->valor;
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

	void exibirFila() {
		Enfileirado<C>* temp = primeiro;
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

	bool vazia() {
		return primeiro == NULL;
	}

	bool cheia() {
		return qtdaElementos() == tamanho;
	}

	int qtdaElementos() {
		Enfileirado<C>* temp = primeiro;
		int contagem = 0;
		while (temp != NULL) {
			contagem++;
			temp = temp->proximo;
		}
		return contagem;
	}

	void deleta() {
		while (primeiro != NULL) {
			Enfileirado<C>* temp = primeiro;
			if (primeiro == ultimo) {
				ultimo == NULL;
			}
			primeiro = primeiro->proximo;
			delete temp;
			temp = NULL;
		}
	}
};