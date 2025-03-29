#include <Windows.h>
#include <iostream>
#include <iomanip>
#define maxFunc 10

using namespace std;


//Declaração variáveis Globais
struct Funcionario{
	int codigo;
	string nome;
	int idade;
	double salario;
};

Funcionario funcionarios[maxFunc];
int nmr_funcionarios_cadastrados = 0;
int id_cadastrados = 0;


//Funções
void exibir_header(string texto){
	system("cls");
	cout << texto << endl;
	cout << "-------------------------" << endl << endl;
}

void exibir_menu(){
	cout << "1. Cadastrar Funcionário" << endl;
	cout << "2. Pesquisar Funcionário" << endl;
	cout << "3. Excluir Funcionário" << endl;
	cout << "4. Listar Todos Funcionários" << endl;
	cout << "5. Sair" << endl << endl;
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
			cout << "Valor deve ser maior que 0" << endl << endl;
			continue;
		}
		return valor;
	}
}

string pegar_string(string mensagem){
	string valor;
	while(true){
		cout << mensagem;
		cin.ignore();
		getline(cin,valor);
		if (!valor.empty()){
			return valor;
		}else{
			cout << "Não pode ser vazio!" << endl << endl ;
		}
	}
}

void cadastrar_func(string nome, int idade, double salario){
	int id = id_cadastrados+1;
	funcionarios[nmr_funcionarios_cadastrados].codigo = id;
	funcionarios[nmr_funcionarios_cadastrados].nome = nome;
	funcionarios[nmr_funcionarios_cadastrados].idade = idade;
	funcionarios[nmr_funcionarios_cadastrados].salario = salario;
	
	id_cadastrados++;
	nmr_funcionarios_cadastrados++;

	exibir_header("Funcionário Cadastrado com Sucesso!");
}

void exibir_funcionarios(){
	
		cout << setw(10) << left << "Código" << setw(20) << left << "Nome" 
	    << setw(10) << left << "Idade" << setw(15) << left << "Salário (R$)" << endl;
    	cout << "------------------------------------------------------------" << endl;
    			
		for(int i=0; i<nmr_funcionarios_cadastrados; i++){
			cout << setw(10) << left << funcionarios[i].codigo
            << setw(20) << left << funcionarios[i].nome
            << setw(10) << left << funcionarios[i].idade
            << setw(15) << left << fixed << setprecision(2) 
			<< funcionarios[i].salario << endl;
		}
			 	
		cout << "------------------------------------------------------------" << endl << endl;
}


int pesquisar_funcionario(int id){
		for (int i =0; i<nmr_funcionarios_cadastrados;i++){
		if(funcionarios[i].codigo == id){
			return i;
		}
	}
	exibir_header("Nenhum Funcionário Encontrado com o Código " + to_string(id) + "!");
	return maxFunc;
}

void exibir_funcionario_pesquisado(int id){
		int funcionario = pesquisar_funcionario(id);
		
		if (funcionario != 10){
			exibir_header("Funcionário Encontrado!");
	
			cout << setw(10) << left << "Código" << setw(20) << left << "Nome" 
		    << setw(10) << left << "Idade" << setw(15) << left << "Salário (R$)" << endl;
	    	cout << "------------------------------------------------------------" << endl;
	    			
				cout << setw(10) << left << funcionarios[funcionario].codigo
	            << setw(20) << left << funcionarios[funcionario].nome
	            << setw(10) << left << funcionarios[funcionario].idade
	            << setw(15) << left << fixed << setprecision(2) 
				<< funcionarios[funcionario].salario << endl;
				 	
			cout << "------------------------------------------------------------" << endl << endl;
		}
}

void excluir_funcionario(int id){
	int funcionario = pesquisar_funcionario(id);
	
	if(funcionario != 10){
		string nome_funcionario = funcionarios[funcionario].nome;
		for(int i = funcionario+1; i<nmr_funcionarios_cadastrados; i++){
			funcionarios[i-1]=funcionarios[i];
		}
		nmr_funcionarios_cadastrados--;
		exibir_header("Funcionário " + nome_funcionario + " Excluído com Sucesso!");
		
	}
}

//Programa Principal
int main(){
	
	SetConsoleOutputCP(CP_UTF8);
	int opt, idade, id;
	double salario;
	string nome;
	
	do{
		
	exibir_header("Gerenciador de Funcionários");
	exibir_menu();
	cout << "O que deseja fazer?" << endl;
	cin >> opt;
	
	if (opt == 5){
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
			if (nmr_funcionarios_cadastrados<maxFunc){
				exibir_header("Cadastrar Funcionário");
				
				nome = pegar_string("Informe o Nome do Funcionário: ");
				idade = pegar_valor("Informe a Idade do Funcionário: ");
				salario = pegar_valor("Informe o Salário do Funcionario (R$): ");
				cadastrar_func(nome, idade, salario);
			}else{
				exibir_header("Limite de Funcionários Atingido!");
			}
			
			system("pause");
			break;
		
		case 2:
			if (nmr_funcionarios_cadastrados>0){
				exibir_header("Pesquisar Funcionário");
				id = pegar_valor("Informe o Código do Funcionário: ");
				exibir_funcionario_pesquisado(id);
			}
			else{
				exibir_header("Nenhum Funcionário Cadastrado!");
			}
			
			system("pause");
			break;
		
		case 3:
			if(nmr_funcionarios_cadastrados>0){
				exibir_header("Excluir Funcionário");
				id = pegar_valor("Informe o Código do Funcionário: ");
				excluir_funcionario(id);
			}
			else{
				exibir_header("Nenhum Funcionário Cadastrado!");
			}
			
			system("pause");
			break;
		
		case 4:
			if (nmr_funcionarios_cadastrados>0){
				
				exibir_header("Funcionários Cadastrados");
				exibir_funcionarios();
			}
			else{
				exibir_header("Nenhum Funcionário Cadastrado!");
			}
			
			system("pause");
			break;
		
		default:
			exibir_header("Opção Inválida!");
			system("pause");
			
	}
	
	
	}while(true);
	
	exibir_header("Adeus, volte logo!");
	system("pause");
	
	return 0;
}