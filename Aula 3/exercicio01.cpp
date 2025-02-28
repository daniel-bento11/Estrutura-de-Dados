#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

void exibir_menu(){
	system("cls");
	cout << "Calculadora" << endl << endl;
	cout << "1. Somar\n2. Subtrair\n3. Multiplicar\n4. Dividir\n5. Sair" << endl;
}

float somar(float n1, float n2){
	return n1+n2;
}

float subtrair(float n1, float n2){
	return n1-n2;
}

float multiplicar(float n1, float n2){
	return n1*n2;
}

float dividir(float n1, float n2){
	return n1/n2;
}

int main(){
	
	SetConsoleOutputCP(CP_UTF8);
	
	int resp;
	float n1, n2, resultado;
	
	do{
		exibir_menu();
		cin >> resp;
		
		system("cls");
	
		if (resp == 5){
			cout << "Adeus!!" << endl;
			break;
		}
		
		if(resp<1 or resp>4){
			cout << "Opção Inválida" << endl;
			cin.clear();
			cin.get();
			system("PAUSE");
			continue;
		}
		
		cout << "Qual o primeiro valor: ";
		cin >> n1;
		
		cout << "Qual o segundo valor: ";
		cin >> n2;
		
		switch(resp){
			case 1:
				resultado = somar(n1,n2);
				break;
			case 2:
				resultado = subtrair(n1,n2);
				break;
			case 3:
				resultado = multiplicar(n1,n2);
				break;
			case 4:
				
				if (n2 == 0){
					cout << "Impossível dividir por 0" << endl;
					system("PAUSE");
					continue;
					break;
				}
				
				resultado = dividir(n1,n2);
				break;
		}
		
		cout << "\nResposta: " << resultado << endl << endl;
		system("PAUSE");
		
	}while(true);
	
	system("PAUSE");
	return 0;
}