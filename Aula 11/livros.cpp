#include <iostream>
#include <Windows.h>
#define max 1

using namespace std;

int pilha1=0;
int pilha2=0;
int espera=0;

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

void cadastrar_livro(Pilha* newLivro){
	if (pilha1<max){
		newLivro->proximo = topop1;
		topop1 = newLivro;
		exibir_header("Livro Cadastrado! Livro Inserido na Pratileira 1");
		pilha1++;
	}else if (pilha2<max){
		newLivro->proximo = topop2;
		topop2 = newLivro;
		exibir_header("Livro Cadastrado! Livro Inserido na Pratileira 2");
		pilha2++;
	}else{
		Pilha* atual = espera1;
		newLivro->proximo = nullptr;
		if (atual != nullptr){
			while(atual->proximo != nullptr){
				atual = atual->proximo;
			}
			atual->proximo = newLivro;
		}else{
			espera1 = newLivro;
		}
		exibir_header("Pratileiras Cheias! Livro Inserido na Fila de Espera");
		espera++;
	}
}

void exibir_pratileira1(){
	if (pilha1>0){
		Pilha* atual = topop1;
	    while (atual != nullptr) {
	    	cout << atual->codigo << " - "<< atual->nome;
	    	if (atual==topop1){
	    		cout << "  - TOPO";
			}
			if (atual->proximo==nullptr){
				cout << "  - BASE";
			}
			
			cout << endl;
	        atual = atual->proximo;
	    }
	    cout << endl;
	}else{
		cout << "Nenhum Livro na Pratileira 1" << endl << endl;
	}
}

void exibir_pratileira2(){
	if (pilha2>0){
		Pilha* atual = topop2;
	    while (atual != nullptr) {
	    	cout << atual->codigo << " - "<< atual->nome;
	    	if (atual==topop2){
	    		cout << "  - TOPO";
			}
			if (atual->proximo==nullptr){
				cout << "  - BASE";
			}
			
			cout << endl;
	        atual = atual->proximo;
	    }
	    cout << endl;
	}else{
		cout << "Nenhum Livro na Pratileira 2" << endl << endl;
	}

}

void exibir_espera(){
	if (espera>0){
		Pilha* atual = espera1;
		while (atual != nullptr){
			cout << " - " << atual->nome;
			atual = atual->proximo;
		}
		cout << endl;
	}else{
		cout << "Nenhum Livro na Espera" << endl << endl;	
	}

}

void remover_livro_espera(int pilha){
	Pilha* first = espera1;
	Pilha* newFirst = espera1->proximo;
	espera1 = newFirst;
	if (pilha == 1){
		first->proximo = topop1;
		topop1 = first;
		cout << first->nome << "  Removido da Espera e Adicionado na Pratileira 1!" << endl << endl;
		pilha1++;
		espera--;
	}else{
		first->proximo = topop2;
		topop2 = first;
		cout << first->nome << "  Removido da Espera e Adicionado na Pratileira 2!" << endl << endl;
		pilha2++;
		espera--;
	}
	espera1 = newFirst;
	delete first;
}

void remover_livro(int pilha){
	if (pilha == 1){
		Pilha* temp = topop1;
		Pilha* novoTopo = topop1->proximo;
		topop1=novoTopo;
		exibir_header("Livro Removido da Pratileira 1!");
		cout << temp->codigo << " - " << temp->nome << " (REMOVIDO) "<<endl << endl;
		delete temp;
		pilha1--;
	}else{
		Pilha* temp = topop2;
		Pilha* novoTopo = topop2->proximo;
		topop2=novoTopo;
		exibir_header("Livro Removido da Pratileira 2!");
		cout << temp->codigo << " - " << temp->nome << " (REMOVIDO) "<<endl << endl;
		pilha2--;
	}
	if (espera>0){
		remover_livro_espera(pilha);
	}
}



int main(){
	SetConsoleOutputCP(CP_UTF8);
	int opt, cod, pilha;
	string nome;
	do{
		exibir_header("Controle de Pratileiras");
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
				exibir_header("Cadastrar Livro");
				cod = pegar_valor("Informe o Código do Livro: ");
				if(!verificar_existencia(cod)){
					nome = pegar_string("Informe o Nome do Livro: ");
					Pilha* newLivro = new Pilha;
					newLivro->codigo=cod;
					newLivro->nome=nome;
					cadastrar_livro(newLivro);
				}else{
					exibir_header("Código já Cadastrado!");
				}
				break;
			case 2:
				if (pilha1>0 or pilha2>0){
					exibir_header("Retirar Livro da Pilha!");
					pilha = pegar_valor("Informe de Qual Pilha Deseja Remover: ");
					switch(pilha){
						case 1:
							if (pilha1>0){
								remover_livro(1);
							}else{
								exibir_header("Nenhum Livro na Pilha 1!");
							}
							break;
						case 2:
							if (pilha2>0){
								remover_livro(2);
							}else{
								exibir_header("Nenhum Livro na Pilha 2!");
							}
							break;
						default:
							exibir_header("Opção Inválida!");
					}
					
				}else{
					exibir_header("Nenhum Livro Cadastrado!");
				}
				break;
			case 3:
				if (pilha1>0 or pilha2>0 or espera>0){
					exibir_header("Livros Encontrados!");
					cout << "Pratileira 1" << endl << endl;
					exibir_pratileira1();
					
					cout << "---------------------" << endl;
					
					cout << "Pratileira 2" << endl << endl;
					exibir_pratileira2();
					
					cout << "---------------------" << endl;
					
					cout << "Fila de Espera" << endl << endl;
					exibir_espera();
					
					cout << "---------------------" << endl;
					
				}else{
					exibir_header("Nenhum Livro Cadastrado!");
				}
				break;
			default:
				exibir_header("Opção Inválida!");
		}
		system("pause");
		
	}while(true);
	
	exibir_header("Adeus, volte logo!");
	system("pause");
	return 0;
}