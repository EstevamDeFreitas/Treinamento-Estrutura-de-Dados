//Construção da Lista ligada, com algumas operações para sua manipulação

#pragma once

template <typename T>
struct No {
    T valor;
    No<T>* proximo;
};

template <typename C>
class Lista {
private:
    No<C>* inicio;
    No<C>* fim;

    No<C>* no(C valor) {
        No<C>* temp = new No<C>;
        temp->proximo = NULL;
        temp->valor = valor;
        return temp;
    }
public:
    Lista() {
        inicio = NULL;
        fim = NULL;
    }

    void adicionar(C valor) {
        No<C>* aux = no(valor);
        if (inicio == NULL) {
            inicio = aux;
            fim = aux;
        }
        else {
            fim->proximo = aux;
            fim = fim->proximo;
        }
    }

    void exibir() {
        No<C>* aux = inicio;
        while (aux != NULL) {
            std::cout << aux->valor << "\n";
            aux = aux->proximo;
        }
    }

    void removerItem(C valor) {
        bool primeiro_loop = true;
        No<C>* aux = inicio;
        No<C>* anterior = inicio;
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

    bool contem(C valor) {
        No<C>* aux = inicio;
        while (aux != NULL) {
            if (aux->valor == valor) {
                return true;
            }
            aux = aux->proximo;
        }
        return false;
    }

    int tamanho() {
        No<C>* aux = inicio;
        int tamanho = 0;
        while (aux != NULL) {
            tamanho++;
            aux = aux->proximo;
        }
        return tamanho;
    }

    C buscar(int posicao) {
        No<C>* aux = inicio;
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

    void deletar() {
        No<C>* aux = inicio;
        while (aux != NULL) {
            No<C>* temp = aux;
            aux = aux->proximo;
            delete temp;
            temp = NULL;
        }
        inicio = NULL;
        fim = NULL;
    }

};