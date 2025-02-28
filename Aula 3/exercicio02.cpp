#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

float calcular_media(int valores[], int clientes){
	double soma = 0;
	double resultado;
	for(int i=0;i<clientes;i++){
		soma = soma + valores[i];
	}
	resultado = soma/clientes;
	return resultado;
}

int main(){
	
	SetConsoleOutputCP(CP_UTF8);
	
	do{
		int n_clientes;
		
		system("cls");
		cout << "Pesquisa de Satisfação" << endl << endl;
		
		cout << "Informe o número de clientes (1-10): ";
		cin >> n_clientes; 
		
		if(n_clientes<1 or n_clientes>10){
			system("cls");
			cout << "Opção Inválida!" << endl;
			cin.clear();
			cin.get();
			system("pause");
			continue;
		}
		
		int qld_comida[n_clientes];
		int qld_atendimento[n_clientes];
		int qld_ambiente[n_clientes];
		
		for(int i=0; i<n_clientes; i++){
			system("cls");
			cout << "Cliente " << i+1 << endl;
			while(true){
				cout << "Qualidade da Comida (1-5): ";
				cin >> qld_comida[i];
				if (qld_comida[i]<1 or qld_comida[i]>5){
					cout << "Opção Inválida!" << endl;
					cin.clear();
					cin.get();
					system("pause");
					system("cls");
					continue;
				}
				break;
			}
			while(true){
				cout << "Qualidade do Atendimento (1-5): ";
				cin >> qld_atendimento[i];
				if (qld_atendimento[i]<1 or qld_atendimento[i]>5){
					cout << "Opção Inválida!" << endl;
					cin.clear();
					cin.get();
					system("pause");
					system("cls");
					continue;
				}
				break;
			}
			while(true){
				cout << "Qualidade do Ambiente (1-5): ";
				cin >> qld_ambiente[i];
				if (qld_ambiente[i]<1 or qld_ambiente[i]>5){
					cout << "Opção Inválida!" << endl;
					cin.clear();
					cin.get();
					system("pause");
					system("cls");
					continue;
				}
				break;
			}			
		}
		
		cout << fixed << setprecision(2);
		
		system("cls");
		cout << "Média Comida: " << calcular_media(qld_comida, n_clientes) << endl;
		cout << "Média Atendimento: " << calcular_media(qld_atendimento, n_clientes) << endl;
		cout << "Média Ambiente: " << calcular_media(qld_ambiente, n_clientes) << endl;
		system("pause");
		cout << "\nMédia Geral: " << (calcular_media(qld_comida, n_clientes)+calcular_media(qld_atendimento, n_clientes)+calcular_media(qld_ambiente, n_clientes))/3 << endl;
		system("pause");
		
		string resp;
		
		while(true){
			system("cls");
			cout << "Deseja realizar outra pesquisa? (s/n)" << endl;
			cin >> resp;
			if (resp == "s"){
				break;
			}
			else if(resp == "n"){
				system("cls");
				cout << "Adeus!" << endl;
				system("pause");
				return 0; 
			}else{
				system("cls");
				cout << "Opção Inválida!" << endl;
				system("pause");
				continue;
			}
		}
		
	}while (true);

}