#include <iostream>
#include <iomanip>
#include <windows.h>
#define maxCont 10

using namespace std;

struct ContaBancaria{
	int nmrConta;
	string nomeCliente;
	double saldo;
};

ContaBancaria contas[maxCont];
int nmr_contas_cadastrados = 0;
int id_cadastrados = 0;

void exibir_header(string texto){
	system("cls");
	cout << texto << endl;
	cout << "-------------------------" << endl << endl;
}

void exibir_menu(){
	cout << "1. Cadastrar Conta" << endl;
	cout << "2. Excluir Conta" << endl;
	cout << "3. Consultar Conta" << endl;
	cout << "4. Visualizar todas as Contas" << endl;
	cout << "5. Realizar Saque" << endl;
	cout << "6. Realizar Depósito" << endl;
	cout << "7. Sair" << endl << endl;
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

void cadastrar_cont(string nomeCliente, double saldo){
	int id = id_cadastrados+1;
	contas[nmr_contas_cadastrados].nmrConta = id;
	contas[nmr_contas_cadastrados].nomeCliente = nomeCliente;
	contas[nmr_contas_cadastrados].saldo = saldo;
	
	id_cadastrados++;
	nmr_contas_cadastrados++;

	exibir_header("Conta Cadastrada com Sucesso!");
}

void exibir_contas(){
	
		cout << setw(10) << left << "Número" << setw(20) << left << "Cliente" 
	    << setw(15) << left << "Saldo (R$)" << endl;
    	cout << "------------------------------------------------------------" << endl;
    			
		for(int i=0; i<nmr_contas_cadastrados; i++){
			cout << setw(10) << left << contas[i].nmrConta
            << setw(20) << left << contas[i].nomeCliente
            << setw(15) << left << fixed << setprecision(2) 
			<< contas[i].saldo << endl;
		}
			 	
		cout << "------------------------------------------------------------" << endl << endl;
}

int pesquisar_conta(int id){
		for (int i =0; i<nmr_contas_cadastrados;i++){
		if(contas[i].nmrConta == id){
			return i;
		}
	}
	exibir_header("Nenhuma Conta Encontrada com o Número " + to_string(id) + "!");
	return maxCont;
}

void exibir_conta_pesquisada(int id){
		int conta = pesquisar_conta(id);
		
		if (conta != maxCont){
			exibir_header("Conta Encontrada!");
	
			cout << setw(10) << left << "Número" << setw(20) << left << "Cliente" 
		    << setw(15) << left << "Saldo (R$)" << endl;
	    	cout << "------------------------------------------------------------" << endl;
	    			
				cout << setw(10) << left << contas[conta].nmrConta
	            << setw(20) << left << contas[conta].nomeCliente
	            << setw(15) << left << fixed << setprecision(2) 
				<< contas[conta].saldo << endl;
				 	
			cout << "------------------------------------------------------------" << endl << endl;
		}
}

void realizar_deposito(int id){
	int conta = pesquisar_conta(id);
	double saldo;
	
	if (conta != maxCont){
		saldo = pegar_valor("Saldo Depositado (R$): ");
		
		contas[conta].saldo = contas[conta].saldo+saldo;
		
		exibir_header("Depósito Realizado com Sucesso!");
	}
}

void realizar_saque(int id){
	int conta = pesquisar_conta(id);
	double saldo;
	
	if (conta != maxCont){
		saldo = pegar_valor("Saldo Sacado (R$): ");
		
		if (contas[conta].saldo>=saldo){
			contas[conta].saldo = contas[conta].saldo-saldo;
			exibir_header("Saque Realizado com Sucesso!");
		}
		else{
			exibir_header("Saldo Insuficiente!");
		}		
	}
}

void excluir_conta(int id){
	int conta = pesquisar_conta(id);
	
	if(conta != maxCont){
		string nomeCliente = contas[conta].nomeCliente;
		for(int i = conta; i<nmr_contas_cadastrados; i++){
			contas[i]=contas[i+1];
		}              
		
		nmr_contas_cadastrados--;
		contas[nmr_contas_cadastrados] = {};
		exibir_header("Conta de " + nomeCliente + " Excluída com Sucesso!");
		
	}
}



int main(){
	
	SetConsoleOutputCP(CP_UTF8);
	int opt, id;
	string nomeCliente;
	double saldo;
	
	
	
	do{
		exibir_header("Gerenciador de Contas");
		exibir_menu();
		cout << "O que deseja fazer?" << endl;
		cin >> opt;
		
		if (opt == 7){
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
			if (nmr_contas_cadastrados<maxCont){
				exibir_header("Cadastrar Conta");
				
				nomeCliente = pegar_string("Informe o Nome do Cliente: ");
				saldo = pegar_valor("Informe o Saldo Inicial da Conta (R$): ");
				cadastrar_cont(nomeCliente, saldo);
			}else{
				exibir_header("Limite de Contas Atingido!");
			}
			
			system("pause");
			break;
		
		case 2:
			if(nmr_contas_cadastrados>0){
				exibir_header("Excluir Conta");
				id = pegar_valor("Informe o Número da Conta: ");
				excluir_conta(id);
			}
			else{
				exibir_header("Nenhuma Conta Cadastrada!");
			}
			
			system("pause");
			break;
		
		case 3:
			if (nmr_contas_cadastrados>0){
				exibir_header("Pesquisar Conta");
				id = pegar_valor("Informe o Número da Conta: ");
				exibir_conta_pesquisada(id);
			}
			else{
				exibir_header("Nenhuma Conta Cadastrada!");
			}
			
			system("pause");
			break;
		
		case 4:
			if (nmr_contas_cadastrados>0){
				
				exibir_header("Contas Cadastradas");
				exibir_contas();
			}
			else{
				exibir_header("Nenhuma Conta Cadastrada!");
			}
			
			system("pause");
			break;
		
		case 5:
			if(nmr_contas_cadastrados>0){
				exibir_header("Efetuar Saque");
				id = pegar_valor("Informe o Número da Conta: ");
				realizar_saque(id);	
			}else{
				exibir_header("Nehuma Conta Cadastrada!");
			}
			
			system("pause");
			break;
		
		case 6:
			if(nmr_contas_cadastrados>0){
				exibir_header("Efetuar Depósito");
				id = pegar_valor("Informe o Número da Conta: ");
				realizar_deposito(id);	
			}else{
				exibir_header("Nehuma Conta Cadastrada!");
			}
			
			system("pause");
			break;
		default:
			exibir_header("Opção Inválida!");
			system("pause");
		
	}
		
		
		
	}while (true);
	
	exibir_header("Adeus, volte logo!");
	system("pause");
	
	return 0;
}
