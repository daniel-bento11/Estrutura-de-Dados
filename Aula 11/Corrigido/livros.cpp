#include <Windows.h>
#include <iostream>
#define max 1

using namespace std;

struct Livro{
	int cod;
	string nome;
	Livro* proximo;
};

Livro* topo1 = nullptr;
Livro* topo2 = nullptr;
Livro* fila_inicio = nullptr;
Livro* fila_fim = nullptr;

int qtdP1 = 0;
int qtdP2= 0;


void exibir_menu(){
	cout << "1. Inserir Livro" << endl;
	cout << "2. Retirar Livro" << endl;
	cout << "3. Exibir Prateleiras" << endl;
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

bool verificar_existencia(int cod, Livro* prateleira){
	while (prateleira!=nullptr){
		if (prateleira->cod==cod){
			return true;
		}else{
			prateleira=prateleira->proximo;
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

Livro* remover_livro(Livro* topo, int pilha_numero) {
    if (topo == nullptr) {
        exibir_header("Pilha Vazia!");
    } else {
        exibir_header("Livro Removido");
        cout << topo->cod << ". " << topo->nome << " REMOVIDO\n\n";
        topo = pop(topo);
        if (fila_inicio != nullptr) {
            topo = push(topo, criar_livro(fila_inicio->cod, fila_inicio->nome));
            cout << fila_inicio->cod << ". " << fila_inicio->nome 
                 << " Removido da Espera e Adicionado na Prateleira " 
                 << pilha_numero << "\n\n";
            dequeue();
        }
    }
    return topo;
}

Livro* limpar_memoria(Livro* prateleira){
	Livro* atual = prateleira;
	Livro* temp = nullptr;
	while (atual!=nullptr){
		temp = atual;
		atual = atual->proximo;
		delete temp;
	}
	return atual;
}

int main(){

	SetConsoleOutputCP(CP_UTF8);
	int opt, cod, pilha;
	string nome;
	do{
		exibir_header("Prateleiras de Livro");
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
						exibir_header("Livro Adicionado na Primeira Prateleira");
						qtdP1++;
					}else if(qtdP2<max){
						topo2 = push(topo2, criar_livro(cod, nome));
						exibir_header("Livro Adicionado na Segunda Prateleira");
						qtdP2++;
					}else{
						enqueue(criar_livro(cod, nome));
						exibir_header("Livro Adicionado na Espera! Prateleiras Cheias!");
					}
				}
				break;
			case 2:
				exibir_header("Remover Livro da Pilha");
				pilha = pegar_valor("Informe a Pilha que Deseja Remover: ");
				switch(pilha){
					case 1:
						topo1 = remover_livro(topo1, 1);
						qtdP1--;
						break;
					case 2:
						topo2 = remover_livro(topo2, 2);
						qtdP2--;
						break;
					default:
						exibir_header("Opção Inválida!");	
				}
				break;
			case 3:
				exibir_header("Prateleiras");
				cout << "Prateleira 1" << endl << endl;
				exibir_pilha(topo1);
				cout << "---------------------" << endl << endl;
				cout << "Prateleira 2" << endl << endl;
				exibir_pilha(topo2);
				cout << "---------------------" << endl << endl;
				cout << "Fila de Espera" <<  endl << endl;
				exibir_fila();
				cout << "---------------------" << endl << endl;
				break;
			default:
				exibir_header("Opção Inválida!");
		}
		system("Pause");
		
	}while(true);
	
	topo1=limpar_memoria(topo1);
	topo2=limpar_memoria(topo2);
	fila_fim=limpar_memoria(fila_inicio);
	exibir_header("Adeus, Volte Logo!");
	system("Pause");
	return 0;	
}
