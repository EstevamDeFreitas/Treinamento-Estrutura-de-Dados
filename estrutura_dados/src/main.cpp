#include <iostream>
#include "lista.h"
#include "pilha.h"

int main() {
	Pilha P;
	P.empurra(90.99);
	P.empurra(28);
	P.empurra(72);

	P.deleta();

	std::cout<<P.vazia();

	return 0;
}