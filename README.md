# Treinamento-Estrutura-de-Dados

![GitHub last commit](https://img.shields.io/github/last-commit/EstevamDeFreitas/Treinamento-Estrutura-de-Dados)
![](https://img.shields.io/badge/Status-Em%20Desenvolvimento-yellow)

Construção de alguns tipos de estruturas de dados vistos no curso de estrutura de dados da Digital Innovation One.

Todas as estruturas de dados foram feitas em C++, e recebem qualquer tipo de valor para armazenamento exceto structs.

Exemplo de aplicação:
```cpp
#include <iostream>
#include "fila/fila.h"

int main(){ 
	Fila<const char*> filaDoBanco(0);

	filaDoBanco.enfileirar("Joana");
	filaDoBanco.enfileirar("Marcos");
	
	std::cout << "Ha " << filaDoBanco.qtdaElementos() << " pessoas esperando na fila\n";

	std::cout << filaDoBanco.desenfileirar() << " foi atendida\n";

	return 0;
}
```

## Estruturas Implementadas
 - Filas.
 - Pilhas.
 - Listas Ligadas.

## Estruturas a serem implementadas
 - Árvores Binárias.
 - Hashmap.
 - Grafos.

O projeto foi feito dentro do Visual Studio Community 2019.

Estou aberto a sujestões e críticas :smile:.
