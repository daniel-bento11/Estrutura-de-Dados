/*Exercicico3 - Versão do exercicio2 com 
remoção de um nó.*/

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

// Função para remover um nó 
No* removerNo(No* cabeca, int valorRemover)
{
    // Caso a lista esteja vazia
    if (cabeca == nullptr) {
        cout << "\nLista vazia, não é possível remover.\n";
        return nullptr;
    }

    // Caso o nó a ser removido seja o cabeca
    if (cabeca->valor == valorRemover) {
        No* temp = cabeca;
        cabeca = cabeca->proximo;
        delete temp;
        cout << "\nNó com valor " 
		     << valorRemover 
			 << " removido do início da lista.\n";
        return cabeca; // Nova cabeça da lista
    }

    // Percorrer a lista para encontrar o nó 
	// anterior ao nó a ser removido
    No* atual = cabeca;
    while (atual->proximo != nullptr && atual->proximo->valor != valorRemover) 
	{
        atual = atual->proximo;
    }

    // Se o nó a ser removido for encontrado
    if (atual->proximo != nullptr) {
        No* temp = atual->proximo;
        atual->proximo = atual->proximo->proximo;
        delete temp;
        cout << "\nNó com valor " << valorRemover 
		     << " removido da lista.\n";
    } 
	else {
        cout << "\nNó com valor " << valorRemover 
		     << " não encontrado na lista.\n";
    }
    return cabeca; 
}

/*===== Programa Principal =====*/

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    int valorPrimeiro, valorSegundo, valorTerceiro;
    int valorInserir, valorAnterior;
    int valorRemover;

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

    // Conectando os nós iniciais
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
    No* atual_insercao = primeiro;
    while (atual_insercao != nullptr && atual_insercao->valor != valorAnterior)
    {
        atual_insercao = atual_insercao->proximo;
    }

    //====== Inserindo o novo nó ======//
    if (atual_insercao != nullptr)
    {
        novoNo->proximo = atual_insercao->proximo;
        atual_insercao->proximo = novoNo;

        cout << "\n==== Lista Encadeada Após Inserção do Nó " 
		     << valorInserir << " ====\n";
        exibirLista(primeiro);
    }
    else{
        cout << "\nErro: Elemento " << valorAnterior 
		     << " não encontrado para realizar a inserção.\n";
    }

    // Obtendo o valor do nó a ser removido
    cout << "\nDigite o valor do nó a ser removido: ";
    cin >> valorRemover;

    //====== Removendo o nó ====== //
    
    primeiro = removerNo(primeiro, valorRemover);

    // Exibindo a lista após a remoção
    cout << "\n==== Lista Encadeada após remoção do Nó " 
	     << valorRemover << " ====\n";
    exibirLista(primeiro);

    return 0;
}