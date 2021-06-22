#include <iostream>
#include "lista.h"

int main() {
	Lista L;
	L.adicionar(9);
	L.adicionar(28);
	L.adicionar(7.89);
	L.exibir();
	L.deletar();
	L.exibir();
	return 0;
}