//1 - Cadastro de Conta: {Castrar uma conta com saldo inicial 0.0 e dar retorno de sucesso ao usuário / no máximo 10 contas podem existir}
//2 - Depósito: {Depositar (+) ao saldo de uma conta existente - [numero.conta] e [saldo.deposito]/ verificar existencia da conta e retorno de sucesso}
//3 - Saque: {Sacar (-) ao saldo de uma conta existente - [numero.conta] e [saldo.saque]/ verificar existencia da conta e saldo suficiente e retorno de sucesso}
//4 - Consultar Saldo: {Mostrar o salto de uma conta - [numero.conta] - ou de todas as contas [-1] }
//5 - Sair

#include <windows.h>
#include <iostream>
#include <iomanip>
#define max

using namespace std;

const int max_contas = 10;
int nro_contas = 0, menu_opt;
double saldo_contas[max_contas];
double valorDeposito, valorSaque;

void exibir_menu(){
	system("cls");
	cout << "Gerenciamento de Contas\n" << endl;
	
	cout << "Ações:" << endl;
	cout << "1. Cadastro de Conta" << endl;
	cout << "2. Depósito" << endl;
	cout << "3. Saque" << endl;
	cout << "4. Consultar Saldos" << endl;
	cout << "5. Sair" << endl;
}

void exibir_adeus(){
	system("cls");
	cout << "Adeus!\n" << endl;
	system("pause");
}

bool cadastrar_conta(){
	if (nro_contas<max_contas){
		saldo_contas[nro_contas]=0;
		nro_contas++;
		return true;
	}else{
		return false;
	}
}

void exibir_status_cadastro_conta(bool status){
	system("cls");
	if(status){
		cout << "Conta " << nro_contas << " Criada com Sucesso\n" << endl;
		system("Pause");
	}else{
		cout << "Limite de Contas (" << max_contas << ") Atingido\n" << endl;
		system("Pause");
	}
}

int main(){
	
	SetConsoleOutputCP(CP_UTF8);
	
	do{
		exibir_menu();
		cin >> menu_opt;
	
	if(cin.fail()){
		cout << "\nApenas Números (Não aceita caractere)\n!" << endl;
		cin.clear();
		cin.ignore(100,'\n');
		system("pause");
		continue;
	}
	
	if(menu_opt == 5){
		break;
	}
	
	switch(menu_opt) {
		case 1:
			exibir_status_cadastro_conta(cadastrar_conta());
			break;
		default:
	    	cout << "\nOpção Inválida (1-5)!\n" << endl;
	    	system("pause");
	}
		
	}while(true);
	
	exibir_adeus();
	return 0;
}