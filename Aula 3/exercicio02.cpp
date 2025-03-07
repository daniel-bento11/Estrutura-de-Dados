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
		
		if (n_clientes==-1){
			break;
		}
		
		if(cin.fail()){
			system("cls");
			cout << "Apenas Números (Não aceita caractere)!" << endl;
			cin.clear();
			cin.ignore(100,'\n');
			system("pause");
			continue;
		}
		
		if(n_clientes<1 or n_clientes>10){
			system("cls");
			cout << "Opção Inválida (1-10)!" << endl;
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
				
				if (cin.fail()){
					cout << "Apenas Números (Não aceita caractere)!" << endl;
					cin.clear();
					cin.ignore(100,'\n');
					system("pause");
					system("cls");
					continue;
				}
				
				if (qld_comida[i]<1 or qld_comida[i]>5){
					cout << "Opção Inválida (1-5)!" << endl;
					system("pause");
					system("cls");
					continue;
				}
				break;
			}
			while(true){
				cout << "Qualidade do Atendimento (1-5): ";
				cin >> qld_atendimento[i];
				
				if (cin.fail()){
					cout << "Apenas Números (Não aceita caractere)!" << endl;
					cin.clear();
					cin.ignore(100,'\n');
					system("pause");
					system("cls");
					continue;
				}				
				
				if (qld_atendimento[i]<1 or qld_atendimento[i]>5){
					cout << "Opção Inválida!" << endl;
					system("pause");
					system("cls");
					continue;
				}
				break;
			}
			while(true){
				cout << "Qualidade do Ambiente (1-5): ";
				cin >> qld_ambiente[i];
				
				if (cin.fail()){
					cout << "Apenas Números (Não aceita caractere)!" << endl;
					cin.clear();
					cin.ignore(100,'\n');
					system("pause");
					system("cls");
					continue;
				}
				
				if (qld_ambiente[i]<1 or qld_ambiente[i]>5){
					cout << "Opção Inválida!" << endl;
					system("pause");
					system("cls");
					continue;
				}
				break;
			}			
		}
		
		cout << fixed << setprecision(2);
		
		double mediaComida = calcular_media(qld_comida, n_clientes);
		double mediaAtendimento = calcular_media(qld_atendimento, n_clientes);
		double mediaAmbiente = calcular_media(qld_ambiente, n_clientes);
		double mediaGeral = (mediaComida+mediaAtendimento+mediaAmbiente)/3;
		 
		system("cls");
		cout << "Média Comida: " << mediaComida << endl;
		cout << "Média Atendimento: " << mediaAtendimento << endl;
		cout << "Média Ambiente: " << mediaAmbiente << endl;
		system("pause");
		cout << "\nMédia Geral: " << mediaGeral << endl;
		system("pause");
		
		char resp;
		
		while(true){
			system("cls");
			cout << "Deseja realizar outra pesquisa? (s/n)" << endl;
			cin >> resp;
			if (tolower(resp) == 's' or tolower(resp) == 'n'){
				break;
			}else{
				system("cls");
				cout << "Opção Inválida!" << endl;
				system("pause");
				continue;
			}
		}
		
		if (tolower(resp)=='n'){
			break;
		}
		
	}while (true);
	
	system("cls");
	cout << "Adeus!" << endl;
	system("pause");
	return 0; 
}