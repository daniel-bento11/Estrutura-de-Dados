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
    No* first = nullptr;
    // Criando o primeiro nó
    No* primeiroNo = new No;
    primeiroNo->valor = 10;
    cout << "PrimeiroNo : " << primeiroNo->valor << "\n";
    
    primeiroNo->proximo = nullptr;
	first = primeiroNo;
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
    novoNo->valor = 22;
    cout << "\nNovoNo : " << novoNo->valor << "\n";
    novoNo->proximo = nullptr;
    
    No* atual = first;
    No* anterior = nullptr;
    while(atual != nullptr){
    	if (atual->valor>novoNo->valor){
    		novoNo->proximo = atual;
    		if(atual!=first){
 				anterior -> proximo = novoNo;
			}
			else{
				first = novoNo;
			}
    		break;
		}
		
		anterior = atual;
		atual = atual->proximo;
		if (atual == nullptr){
			anterior -> proximo = novoNo;
		}
	}
	

    // Percorrendo e exibindo a lista atualizada
    atual = first;
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

