#include <iostream>
#include <Windows.h>

using namespace std;

struct No
{
    int valor;
    No* proximo;
};

No* topop = nullptr;

void exibir_menu(){
	cout << "1. Push (Inserir elemento)" << endl;
	cout << "2. Pop (Remover elemento do topo)" << endl;
	cout << "3. Peek (Ver o topo)" << endl;
	cout << "4. Exibir Pilha" << endl;
	cout << "5. Size (Tamanho da Pilha)" << endl;
	cout << "6. Sair" << endl << endl;
}

void exibir_header(string text){
	system("cls");
	cout<< "---------------------" << endl;
	cout<< text << endl;
	cout<< "---------------------" << endl << endl;
}

double pegar_valor(string mensagem){
	double valor;
	while(true){
		cout << mensagem;
		cin >> valor;
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "Entrada inválida !!" << endl << endl;
			continue;
		}
		if (valor < 0){
			cout << "Valor não pode ser negativo" << endl << endl;
			continue;
		}
		return valor;
	}
}

void push(int valor){
	No* novoNo = new No;
	novoNo->valor = valor;
	novoNo->proximo = topop;
	topop = novoNo;
	exibir_header("Valor Inserido com Sucesso!");
}

void exibir_pilha(){
	No* atual = topop;
    while (atual != nullptr) {
        cout << "- "<< atual->valor << endl;
        atual = atual->proximo;
    }
    cout << endl;
}

void pop(){
    No* temp = topop;
    No* novoTopo = topop->proximo;
    delete temp;
    topop=novoTopo;
    exibir_header("Topo Excluído com Sucesso!");
}

void peek(){
    cout << topop->valor << endl << endl;
}

int len_pilha(){
	int valor = 0;
	No* atual = topop;
    while (atual != nullptr) {
        valor++;
        atual = atual->proximo;
    }
    return valor;
	
}

void limpar_memoria(){
	No* atual = topop;
	
	if(atual != nullptr){
		No* proximo = nullptr;
		while (atual != nullptr){
			proximo = atual->proximo;
			delete atual;
			atual = proximo;
		}
	}
	topop = nullptr;
}

int main (){
	SetConsoleOutputCP(CP_UTF8);
	int opt, valor;
	do{
		exibir_header("Menu da Pilha");
		exibir_menu();
		
		cout << "O que deseja fazer?" << endl;
		cin >> opt;
		
		if (opt == 6){
			break;
		}
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			exibir_header("Entrada Inválida");
			system("pause");
			continue;
		}
		switch(opt){
			case 1:
				exibir_header("Inserir Valor na Pilha");
				valor = pegar_valor("Informe o Valor a ser Inserido na Pilha: ");
				push(valor);
				break;
			case 2:
				if(topop!=nullptr){
					pop();
				}else{
					exibir_header("Nenhum Valor na Pilha!");
				}
				break;
			case 3:
				if(topop!=nullptr){
					exibir_header("Valor no Topo");
					peek();
				}else{
					exibir_header("Nenhum Valor na Pilha!");
				}
				break;
			case 4:
				if (topop!=nullptr){
					exibir_header("Valores da Pilha");
					exibir_pilha();
					
				}else{
					exibir_header("Nenhum Valor na Pilha!");
				}
				break;
			case 5:
				valor = len_pilha();
				if (topop!=nullptr){
					exibir_header("Tamanho da Pilha");
				}else{
					exibir_header("Nenhum Valor na Pilha!");
					
				}
				cout << "Tamanho da Pilha: " << valor << endl << endl;
				break;
			default:
				exibir_header("Opção Inválida!");
				
		}
		system("pause");
	}while(true);
	
	limpar_memoria();
	exibir_header("Adeus, volte logo!");
	system("pause");
	return 0;
}