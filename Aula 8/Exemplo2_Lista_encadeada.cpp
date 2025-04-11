/*Exemplo2.Criando e Exibindo uma Lista Encadeada 
Simples (3 nós) com inserção no meio da lista.*/

#include <iostream>
#include <Windows.h>

using namespace std;

struct No {
    int valor;
    No* proximo; 
};

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    // Criando o primeiro nó
    No* primeiroNo = new No;
    primeiroNo->valor = 10;
    cout << "PrimeiroNo : " << primeiroNo->valor << "\n";
    
    primeiroNo->proximo = nullptr;

    // Criando o segundo nó
    No* segundoNo = new No;
    segundoNo->valor = 20;
    cout << "SegundoNo : " << segundoNo->valor << "\n";

    segundoNo->proximo = nullptr;

    // Conectando o primeiro nó ao segundo nó
    primeiroNo->proximo = segundoNo;

    // Criando o terceiro nó
    No* terceiroNo = new No;
    terceiroNo->valor = 30;
    cout << "TerceiroNo : " << terceiroNo->valor << "\n";
    
    terceiroNo->proximo = nullptr;

    // Conectando o segundo nó ao terceiro nó
    segundoNo->proximo = terceiroNo;

    // Criando o novo nó com o valor 25
    No* novoNo = new No;
    novoNo->valor = 25;
    cout << "\nNovoNo : " << novoNo->valor << "\n";
    novoNo->proximo = nullptr;

    // Encontrando o nó anterior ao ponto de inserção 
	//(o nó com valor 20)
    No* atual = primeiroNo;
    while (atual != nullptr && atual->valor != 20) 
	{
        atual = atual->proximo;
    }

    // Inserindo o novo nó entre o nó atual (20) e o 
	//próximo nó (30)
    if (atual != nullptr) {
    	// O próximo do novo nó aponta para o antigo 
		//próximo do atual
        novoNo->proximo = atual->proximo; 
        
        // O próximo do atual agora aponta para o novo nó
        atual->proximo = novoNo;        
    } else {
        cout << "\nErro: Elemento 20 não encontrado.\n";
    }

    // Percorrendo e exibindo a lista atualizada
    atual = primeiroNo;
    cout << "\n==== Lista encadeada Atualizada ====\n\n";
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

