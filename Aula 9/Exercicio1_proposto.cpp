//Exercicio1 - Proposto1 - Lista encadeada desordenada

#include <iostream>
#include <Windows.h>

using namespace std;

// Estrutura do Nó
struct No {
    int valor;
    No* proximo;
};

// Função para criar um novo nó
No* criarNo(int valor) 
{
    No* novoNo = new No;
    novoNo->valor = valor;
    novoNo->proximo = nullptr;
    return novoNo;
}

// Função para exibir a lista encadeada
void exibirLista(No* cabeca) 
{
    No* atual = cabeca;
    cout << "\n<<<< Lista Encadeada >>>\n";
    while (atual != nullptr) 
	{
    	cout << atual->valor;
    	if (atual->proximo != nullptr) {
        	cout << " -> ";
    	} 
		else{
        	cout << " -> NULL";
    	}
    	atual = atual->proximo;
	}    
    cout << endl;
}

// Programa Principal //

int main() 
{
    SetConsoleOutputCP(CP_UTF8);
    
    // Criando os nós
    No* primeiro = criarNo(25);
    No* segundo  = criarNo(15);
    No* terceiro = criarNo(35);

    // Conectando os nós
    primeiro->proximo = segundo;
    segundo->proximo = terceiro;
    terceiro->proximo = nullptr;

    // Exibindo a lista original
    cout << "\n==== Lista Encadeada Original ====\n";
    exibirLista(primeiro);

    // Criando o novo nó a ser inserido
    No* novoNo = criarNo(20);

    // Localizando o nó anterior ao ponto de inserção 
	// (o nó com valor 15)
    No* atual = primeiro;
    while (atual != nullptr && atual->valor != 15) 
	{
        atual = atual->proximo;
    }

    // Inserindo o novo nó
    if (atual != nullptr) 
	{
    	//O próximo do novo nó aponta para o antigo 
		//próximo do atual
        novoNo->proximo = atual->proximo; 
        
        //O próximo do atual agora aponta para o novo nó
        atual->proximo = novoNo;  
		       
        cout << "\n==== Lista Encadeada Após Inserção do Nó 20 ====\n";
        exibirLista(primeiro);
        
    } else {
        cout << "\nErro: Elemento 15 não encontrado.\n";
    }

    return 0;
}