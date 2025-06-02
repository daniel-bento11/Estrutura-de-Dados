#include <Windows.h>
#include <iostream>
#define max 1

using namespace std;

struct Livro{
	int cod;
	string nome;
	Livro* proximo;
};

Livro* Pilha1 = new Livro;
Livro* Pilha2= new Livro;
Livro* Fila = new Livro;

Livro* topo1 = nullptr;
Livro* topo2 = nullptr;
Livro* fila_inicio = nullptr;
Livro* fila_fim = nullptr;

int qtdP1 = 0;
int qtdP2= 0;


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

bool verificar_existencia(int cod, Livro* pratileira){
	while (pratileira!=nullptr){
		if (pratileira->cod==cod){
			return true;
		}else{
			pratileira=pratileira->proximo;
		}
	}
	return false;
}

Livro* criar_livro(int cod, string nome){
	Livro* newLivro = new Livro;
	newLivro->cod = cod;
	newLivro->nome = nome;
	newLivro->proximo=nullptr;
	return newLivro;
}

Livro* push(Livro* topo, Livro* newLivro){
    newLivro->proximo = topo;
    return newLivro;
}

void enqueue(Livro* newLivro) {
    if (fila_inicio==nullptr) {
        fila_inicio = newLivro;
		fila_fim = newLivro;
    } else {
        fila_fim->proximo = newLivro;
        fila_fim = newLivro;
    }
}

Livro* pop(Livro* topo) {
    Livro* temp = topo;
    Livro* novoTopo = topo->proximo;
    delete temp;
    return novoTopo;
}

void dequeue() {
    Livro* temp = fila_inicio;
    fila_inicio = fila_inicio->proximo;
    delete temp;

    if (fila_inicio == nullptr) {
        fila_fim = nullptr;
    }
}

void exibir_pilha(Livro* topo){
	if (topo==nullptr){
		cout << "VAZIA" << endl;
	}else{
		while (topo!=nullptr){
			cout << topo->cod << ". " << topo->nome << endl;
			topo = topo->proximo;
		}
	}	
}

void exibir_fila(){
	Livro* atual = fila_inicio;
	if (atual == nullptr){
		cout << "VAZIA" << endl;
	}else{
		while (atual!= nullptr){
			if (atual->proximo==nullptr){
				cout << atual->cod << ". " << atual->nome << endl;
			}else{
				cout << atual->cod << ". " << atual->nome << " -> ";
			}
			atual = atual->proximo;
		}
	}
}



int main(){

	SetConsoleOutputCP(CP_UTF8);
	int opt, cod, pilha;
	string nome;
	do{
		exibir_header("Pratileiras de Livro");
		exibir_menu();
		cout << "O que deseja fazer?" << endl;
		cin >> opt;

		if (opt == 4){
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
				exibir_header("Inserir Novo Livro");
				cod = pegar_valor("Informe o Código do Livro: ");
				if (verificar_existencia(cod, topo1) or verificar_existencia(cod,topo2) or verificar_existencia(cod, fila_inicio)){
					exibir_header("Código Já Cadastrado!");
				}else{
					nome = pegar_string("Informe o Nome do Livro: ");
					if (qtdP1<max){
						topo1=push(topo1, criar_livro(cod, nome));
						exibir_header("Livro Adicionado na Primeira Pratileira");
						qtdP1++;
					}else if(qtdP2<max){
						topo2 = push(topo2, criar_livro(cod, nome));
						exibir_header("Livro Adicionado na Segunda Pratileira");
						qtdP2++;
					}else{
						enqueue(criar_livro(cod, nome));
						exibir_header("Livro Adicionado na Espera! Pratileiras Cheias!");
					}
				}
				break;
			case 2:
				exibir_header("Remover Livro da Pilha");
				pilha = pegar_valor("Informe a Pilha que Deseja Remover: ");
				switch(pilha){
					case 1:
						if(topo1==nullptr){
							exibir_header("Pilha Vazia!");
						}else{
							exibir_header("Livro Removido!");
							qtdP1--;
							cout << topo1->cod << ". "<< topo1->nome << " REMOVIDO" << endl << endl ;
							topo1= pop(topo1);
							if(fila_inicio!=nullptr){
								topo1 = push(topo1, fila_inicio);
								cout << fila_inicio->cod << ". " << fila_inicio->nome << " Removido da Espera e Adicionado na Primeira Pratileira" << endl << endl;
								dequeue();
							}
						}
						break;
					case 2:
						if (topo2==nullptr){
							exibir_header("Pilha Vazia!");
						}else{
							exibir_header("Livro Removido");
							qtdP2--;
							cout << topo2->cod << ". "<< topo2->nome  << " REMOVIDO" << endl << endl ;
							topo2= pop(topo2);
							if(fila_inicio!=nullptr){
								topo2 = push(topo2, fila_inicio);
								cout << fila_inicio->cod << ". " << fila_inicio->nome << " Removido da Espera e Adicionado na Segunda Pratileira" << endl << endl;
								dequeue();
							}
						}
						break;
					default:
						exibir_header("Opção Inválida!");	
				}
				break;
			case 3:
				exibir_header("Pratileiras");
				cout << "Pratileira 1" << endl;
				exibir_pilha(topo1);
				cout << "---------------------" << endl << endl;
				cout << "Pratileira 2" << endl;
				exibir_pilha(topo2);
				cout << "---------------------" << endl << endl;
				cout << "Fila de Espera" <<  endl;
				exibir_fila();
				cout << "---------------------" << endl << endl;
				break;
			default:
				exibir_header("Opção Inválida!");
		}
		system("Pause");
		
	}while(true);
	exibir_header("Adeus, Volte Logo!");
	system("Pause");
	return 0;	
}
