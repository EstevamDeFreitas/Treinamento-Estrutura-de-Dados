#include <iostream>
#include "fila/fila.h"

int main() {
	Fila F(5);
	F.enfileirar(2291.89);
	F.enfileirar(127.28);
	F.enfileirar(490.87);
	F.enfileirar(320.19);
	F.enfileirar(229.89);
	F.exibirFila();
	F.enfileirar(36);
	F.enfileirar(23);
	F.exibirFila();
	return 0;
}