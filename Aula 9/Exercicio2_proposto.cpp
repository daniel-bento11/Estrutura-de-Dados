/*Exercicico2 - Versão do exercicio1 com 
entrada de dados */

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
        else {
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

    int valorPrimeiro, valorSegundo, valorTerceiro;
	int valorInserir, valorAnterior;

    // Obtendo os valores para os nós iniciais
    cout << "Digite o valor do primeiro nó: ";
    cin >> valorPrimeiro;
    No* primeiro = criarNo(valorPrimeiro);

    cout << "Digite o valor do segundo nó: ";
    cin >> valorSegundo;
    No* segundo = criarNo(valorSegundo);

    cout << "Digite o valor do terceiro nó: ";
    cin >> valorTerceiro;
    No* terceiro = criarNo(valorTerceiro);

    // Conectando os nós criados
    primeiro->proximo = segundo;
    segundo->proximo = terceiro;
    terceiro->proximo = nullptr;

    // Exibindo a lista original
    cout << "\n==== Lista Encadeada Original ====\n";
    exibirLista(primeiro);

    // Obtendo o valor do novo nó a ser inserido
    cout << "\nDigite o valor do nó a ser inserido: ";
    cin >> valorInserir;
    No* novoNo = criarNo(valorInserir);

    // Obtendo o valor do nó anterior ao ponto de inserção
    cout << "Digite o valor do nó anterior ao ponto de inserção: ";
    cin >> valorAnterior;

    // Localizando o nó anterior ao ponto de inserção
    No* atual = primeiro;
    while (atual != nullptr && atual->valor != valorAnterior)
    {
        atual = atual->proximo;
    }

    // Inserindo o novo nó
    if (atual != nullptr)
    {
        novoNo->proximo = atual->proximo;
        atual->proximo = novoNo;

        cout << "\n==== Lista Encadeada após inserção do Nó " << valorInserir << " ====\n";
        exibirLista(primeiro);
    }
    else
    {
        cout << "\nErro: Elemento " << valorAnterior 
		     << " não encontrado para realizar a inserção.\n";
    }

    return 0;
}