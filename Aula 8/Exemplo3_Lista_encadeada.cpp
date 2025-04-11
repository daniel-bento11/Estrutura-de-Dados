/*Exemplo3.Criando, exibindo uma Lista Encadeada 
Simples (3 nós) e deletando os nós da lista*/

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
    primeiroNo->proximo = nullptr;

    // Criando o segundo nó
    No* segundoNo = new No;
    segundoNo->valor = 20;
    segundoNo->proximo = nullptr;

    // Conectando o primeiro nó ao segundo nó
    primeiroNo->proximo = segundoNo;

    // Criando o terceiro nó
    No* terceiroNo = new No;
    terceiroNo->valor = 30;
    terceiroNo->proximo = nullptr;

    // Conectando o segundo nó ao terceiro nó
    segundoNo->proximo = terceiroNo;

    // Percorrendo e exibindo a lista
    No* atual = primeiroNo;
    
    cout << "\n=== Lista encadeada ===\n";
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

    // Liberando a memória de todos os nós
    No* atual_deletar = primeiroNo;
    
    while (atual_deletar != nullptr)
	{
        No* proximoNo = atual_deletar->proximo;
        delete atual_deletar;
        atual_deletar = proximoNo;
    }
    
    //0 (ou algum endereço de memória nulo específico, 
	//como 0x0)
	cout << "\n=== Lista com nós deletados ===\n";
	cout << atual_deletar;
    return 0;
}
