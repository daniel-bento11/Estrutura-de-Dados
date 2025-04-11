/* =====================================
   ========== Listas Encadeadas ======== 
   =====================================

/*As listas encadeadas são estruturas de dados 
dinâmicas que armazenam elementos chamados nós 
, onde cada nó contém um valor, que pode ser
um único valor ou uma estutura com vários membros, 
e um ponteiro para o próximo nó da lista. 

Ao contrário dos arrays (ou vetores), que possuem 
um tamanho fixo definido na sua criação e armazenam 
seus elementos em blocos contínuos de memória, as 
listas encadeadas oferecem uma abordagem mais dinâmica 
e flexível para organizar dados.

Os nós não precisam estar armazenados em posições 
contínuas de memória. Eles podem estar espalhados 
pela memória, e a ordem da lista é mantida através 
dos ponteiros.

/*Exemplo1.Criando e Exibindo uma Lista Encadeada 
Simples (3 nós).*/

#include <iostream>
#include <Windows.h>

using namespace std;

struct No {
    int valor;
    No* proximo; // ponteiro para o próximo registro
};

int main() 
{
	SetConsoleOutputCP(CP_UTF8);
    // Criando o primeiro nó
    No* primeiroNo = new No;
    primeiroNo->valor = 10;
    cout << "PrimeiroNo : " << primeiroNo->valor << "\n";
    // Por enquanto, aponta para NULL
    primeiroNo->proximo = nullptr;

    // Criando o segundo nó
    No* segundoNo = new No;
    segundoNo->valor = 20;
    cout << "SegundoNo : " << segundoNo->valor << "\n";
    // Aponta para NULL. Ainda não conectado
    segundoNo->proximo = nullptr; 

    // Conectando o primeiro nó ao segundo nó
    primeiroNo->proximo = segundoNo;

    // Criando o terceiro nó
    No* terceiroNo = new No;
    terceiroNo->valor = 30;
    cout << "TerceiroNo : " << terceiroNo->valor << "\n";
    // Fim da lista por enquanto
    terceiroNo->proximo = nullptr; 

    // Conectando o segundo nó ao terceiro nó
    segundoNo->proximo = terceiroNo;


    /*primeiroNo é a cabeça da lista encadeada: 
	  10 -> 20 -> 30 -> NULL */

    //Percorrendo e exibindo a lista
    No* atual = primeiroNo;
    
    cout << "\n ==== Lista encadeada ====\n\n ";
    while (atual != nullptr) 
	{
    	cout << atual->valor;
    	if (atual->proximo != nullptr) {
        	cout << " -> ";
    	} 
		else {
        	cout << " -> NULL";
    	}
    	atual = atual->proximo;
	}    
    cout << endl;

    return 0;
}

