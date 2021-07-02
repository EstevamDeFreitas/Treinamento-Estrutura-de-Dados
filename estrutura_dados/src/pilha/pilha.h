//Construção da estrutura pilha, com algumas operações

#pragma once

template <typename T>
struct Elemento {
	T valor;
	Elemento<T>* proximo;
};

template <typename C>
class Pilha {
private:
	Elemento<C>* extremidade;
	Elemento<C>* elementoNovo(C valor, Elemento<C>* anterior) {
		Elemento<C>* temp = new Elemento<C>;
		temp->proximo = anterior;
		temp->valor = valor;
		return temp;
	}
public:
	Pilha() {
		extremidade = NULL;
	}

	C topo() {
		return extremidade->valor;
	}

	void empurra(C valor) {
		Elemento<C>* aux = elementoNovo(valor, extremidade);
		extremidade = aux;
	}

	C puxa() {
		if (extremidade != NULL) {
			Elemento<C>* aux = extremidade;
			C temp = aux->valor;
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

	void deleta() {
		if (extremidade == NULL) return;
		Elemento<C>* aux = extremidade;
		extremidade = extremidade->proximo;
		delete aux;
		aux = NULL;
		return deleta();
	}

	bool vazia() {
		return extremidade == NULL ? true : false;
	}
};
