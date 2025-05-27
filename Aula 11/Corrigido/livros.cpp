#include <Windows.h>
#include <iostream>
#include <iomanip>
# define max 5

using namespace std;

struct Pilha
{
	int codigo;
	string nome;
	Pilha* proximo;
};

Pilha* Pilha1 = new Pilha;
Pilha* Pilha2 = new Pilha;
Pilha* Espera = new Pilha;

Pilha* topop1 = nullptr;
Pilha* topop2 = nullptr;
Pilha* espera1 = nullptr;

int pilha1=0;
int pilha2=0;
int espera=0;

void exibir_menu(){
	cout << "1. Inserir Livro" << endl;
	cout << "2. Retirar Livro" << endl;
	cout << "3. Exibir Pratileiras" << endl;
	cout << "4. Sair" << endl << endl;
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
		if (valor <= 0){
			cout << "Valor deve ser maior que Zero" << endl << endl;
			continue;
		}
		return valor;
	}
}

string pegar_string(string mensagem){
	string valor;
	
	while(true){
		cin.ignore();
		cout << mensagem;
		getline(cin,valor);
		if (!valor.empty()){
			return valor;
		}else{
			cout << "Não pode ser vazio!" << endl << endl ;
		}
	}
}

bool verificar_existencia(int cod){
	if (pilha1>0){
		Pilha* atual = topop1;
	    while (atual != nullptr) {
	        if (atual->codigo==cod){
	        	return true;
			}
	        atual = atual->proximo;
	    }
	}
	if (pilha2>0){
		Pilha* atual = topop2;
	    while (atual != nullptr) {
	        if (atual->codigo==cod){
	        	return true;
			}
	        atual = atual->proximo;
	    }
	}
	if (espera>0){
		Pilha* atual = espera1;
	    while (atual != nullptr) {
	        if (atual->codigo==cod){
	        	return true;
			}
	        atual = atual->proximo;
	    }
	}
	return false;
}

Pilha* push(Pilha* newLivro, Pilha* topo){
	newLivro->proximo=topo;
	topo = newLivro;
	return topo;
}


int main(){
	
	SetConsoleOutputCP(CP_UTF8);
	
	
	system("pause");
	return 0;
}