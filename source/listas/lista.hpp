//Header com aplicação de conceitos vistos na aula de Listas ligadas, a lista a seguir é unidimensional
//contem um ponteiro para seu inicio e para o seu fim.

#include <iostream>

struct No{
    double valor;
    No *proximo;
};

No* no(double valor){
    No *temp = new No;
    temp->proximo = NULL;
    temp->valor = valor;
    return temp;
}

class Lista{
    private:
        No *inicio, *fim;

    public:
        Lista(){
            inicio = NULL;
            fim = NULL;
        }

        void adicionar(double valor){
            No *aux = no(valor);

            if(inicio == NULL){
                inicio = aux;
                fim = aux;
            }
            else{
                fim->proximo = aux;
                fim = fim->proximo;
            }

        }

        void exibir(){
            No *aux = inicio;
            while(aux != NULL){
                std::cout<<aux->valor<<"\n";
                aux = aux->proximo;
            }
        }

        void remover(double valor){
            bool primeiro_loop = true;

            No *aux = inicio;
            No *anterior = inicio;
            while(aux != NULL){
                if(aux->valor == valor){
                    if(aux == inicio){
                        inicio = aux->proximo;
                        delete aux;
                        aux = NULL;
                        return;
                    }
                    else if(aux == fim){
                        anterior->proximo = NULL;
                        fim = anterior;
                        delete aux;
                        aux = NULL;
                        return;
                    }
                    else{
                        anterior->proximo = aux->proximo;
                        delete aux;
                        aux = NULL;
                        return;
                    }
                    
                }
                aux = aux->proximo;
                if(primeiro_loop){
                    primeiro_loop = false;
                }
                else{
                    anterior = anterior->proximo;
                }
            }
        }

};
