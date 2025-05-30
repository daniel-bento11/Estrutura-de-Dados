#include <windows.h>
#include <iostream>

using namespace std;

struct No{
	int senha;
	No* proximo;
};

int senha = 0;

string senhas_atendidas = "";

No* inicio = nullptr;
No* fim = nullptr;

void exibir_header(string texto){
	system("cls");
	cout << "-----------------------" << endl;
	cout << texto << endl;
	cout << "-----------------------" << endl << endl;
}

void exibir_menu(){
	cout << "1. Gerar Nova Senha (Enfileirar)" << endl
	<< "2. Chamar Próximo Cliente (Desenfileirar)" << endl
	<< "3. Visualizar Próximo Cliente (Front)" << endl
	<< "4. Exibir Fila de Atendimento" << endl
	<< "5. Exibir Último da Fila" << endl
	<< "6. Exibir Número de Clientes" << endl
	<< "7. Exibir as Senhas já Atendidas" << endl
	<< "8. Sair" << endl << endl;
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

bool isEmpty(){
	return inicio==nullptr;
}

void enqueue(int valor){
	No* novo = new No();
	novo->senha = valor;
	novo->proximo = nullptr;
	
	if(isEmpty()){
		inicio = novo;
		fim = novo;
	}else{
		fim->proximo = novo;
		fim = novo;
	}
}

void dequeue(){
	No* temp = inicio;
	inicio = inicio->proximo;
	delete temp;
	
	if (inicio == nullptr){
		fim = nullptr;
	}
}

void add_string(int senha){
	senhas_atendidas = senhas_atendidas + " " + to_string(senha) + " ->";
}

void front(){
	cout << "Proxima Senha: " << inicio->senha << endl << endl;
}

void end(){
	cout << "Última Senha: " << fim->senha << endl << endl;
}

void exibir_fila(){
	No* atual = inicio;
	while (atual!=nullptr){
		cout << atual->senha;
		if(atual->proximo!=nullptr){
			cout << " -> ";
		}else{
			cout << " -> NULL";
		}
		atual = atual->proximo;
	}
	cout << endl << endl;
}

int size(){
	int size = 0;
	No* atual = inicio;
	while (atual!=nullptr){
		size++;
		atual = atual ->proximo;
	}
	return size;
}

void limpar_cache(){
	senha=0;
	senhas_atendidas ="";
	while (inicio!= nullptr){
		No* temp = inicio;
		inicio = inicio->proximo;
		delete temp;
	}
	fim = nullptr;
}

int main(){
	SetConsoleOutputCP(CP_UTF8);
	
	int opt, senha2;
	do{
		exibir_header("Lista Encadeada (FIFO)");
		exibir_menu();

		cout << "O que deseja fazer?" << endl;
		cin >> opt;
		
		if (opt == 8){
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
				senha++;
				enqueue(senha);
				exibir_header("Senha Gerada com Sucesso!");
				break;
			case 2:
				if(isEmpty()){
					exibir_header("Nenhuma Senha Aguardando");
				}else{
					exibir_header("Chamar Senha");
					senha2 = inicio->senha;
					add_string(senha2);
					dequeue();
					cout << "Senha Atendida: " << senha2 << endl << endl;
				}
				break;
				
			case 3:
				if(isEmpty()){
					exibir_header("Nenhuma Senha Aguardando!");
				}else{
					exibir_header("Próxima Senha");
					front();
				}
				break;
			case 4:
				if(isEmpty()){
					exibir_header("Nenhuma Senha Aguardando!");
				}else{
					exibir_header("Fila de Senhas");
					exibir_fila();
				}
				break;
			case 5:
				if(isEmpty()){
					exibir_header("Nenhuma Senha Aguardando!");
				}else{
					exibir_header("Última Senha");
					end();
				}
				break;
			case 6:
				if(isEmpty()){
					exibir_header("Nenhuma Senha Aguardando!");
				}else{
					exibir_header("Senhas Aguardando");
					cout << "Número de Senhas Aguardando: " << size() << endl << endl; 
				}
				break;
			case 7:
				if (senhas_atendidas==""){
					exibir_header("Nenhuma Senha Atendida!");
				}else{
					exibir_header("Senhas Atendidas");
					cout << "Senhas Atendidas: " << senhas_atendidas << " NULL " << endl << endl;
				}
				break;
			default:
				exibir_header("Opção Iválida!");
		}
		system("Pause");

	}while(true);
	
	
	limpar_cache();
	exibir_header("Adeus, Volte Logo!");
	system("Pause");
	return 0;
}