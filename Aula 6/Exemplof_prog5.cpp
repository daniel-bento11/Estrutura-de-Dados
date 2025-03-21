/*Exercicio5-Programa para  calcular a área de figuras 
geométricas : quadrado, círculo, triângulo ou 
trapézio.
As funções receberão os parâmetros enviados
pelo programa principal e retornarão o resultado
para serem apresentados ao usuário.

Menu de opções:

1.Área do quadrado  -> lado * lado
2.Área do círculo   -> M_PI * pow(raio,2)
3.Área do triângulo -> (base * altura) / 2
4.Área do trapézio  -> ((base_maior + base_menor)*altura)/2
5.Sair
*/

#include <Windows.h>
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

void exibir_cabecalho(){
	system("cls");
	cout << "Cálculo de Área" << endl << endl;
}

void exibir_menu(){
	exibir_cabecalho();
	cout << "1. Área do Quadrado" << endl 
		<< "2. Área do Círculo" << endl
		<< "3. Área do Triângulo" << endl
		<< "4. Área do Trapézio" << endl
		<< "5. Sair" << endl << endl;
}

float solicitar_e_verificar_valor_float(string texto){
	float valor;
	do{
		exibir_cabecalho();
		cout << texto;
		cin >> valor;
		
		if(cin.fail()){
			cout << "Valor Incorreto!" << endl;
			cin.clear();
			cin.ignore(100,'\n');
			system("pause");
			continue;
		}
		
		if(valor <=0){
			cout << "Medida deve ser maior que 0!" << endl;
			system("pause");
			continue;
		}
		
		return valor;
	}while(true);
}

float calcular_area_quadrado(float lado){
	return pow(lado,2);
}

float calcular_area_circulo(float raio){
	return 	M_PI * pow(raio,2);
}

float calcular_area_triangulo(float base, float altura){
	return 	(base*altura)/2;
}

float calcular_area_trapezio(float base_maior, float base_menor, float altura){
	return 	((base_maior + base_menor)*altura)/2;
}


int main(){
	SetConsoleOutputCP(CP_UTF8);
	
	int menu_opt;
	float lado, raio, base, altura, base_menor, base_maior;
	do{
		exibir_menu();
		cin >> menu_opt;
		
		if (menu_opt == 5){
			exibir_cabecalho();
			cout << "Adeus!" << endl;
			break;
		}
		
		if(cin.fail()){
			cout << "Valor Incorreto!" << endl;
			cin.clear();
			cin.ignore(100,'\n');
			system("pause");
			continue;
		}
		
		cout << fixed << setprecision(2);
		
		switch(menu_opt){
			case 1:
				lado = solicitar_e_verificar_valor_float("Informe o valor do Lado do Quadrado (cm): ");
				
				exibir_cabecalho();
				cout << "Área do Quadrado (cm²): " <<  calcular_area_quadrado(lado) << endl;
				break;
			case 2:
				raio = solicitar_e_verificar_valor_float("Informe o valor do Raio do Círculo (cm): ");
				
				exibir_cabecalho();
				cout << "Área do Círculo (cm²): " <<  calcular_area_circulo(raio) << endl;
				break;
			case 3:
				base = solicitar_e_verificar_valor_float("Informe o valor da Base do Triângulo (cm): ");
				altura = solicitar_e_verificar_valor_float("Informe o valor da Altura do Triângulo (cm): ");
				
				exibir_cabecalho();
				cout << "Área do Triângulo (cm²): " <<  calcular_area_triangulo(base, altura) << endl;
				break;
			case 4:
				base_maior = solicitar_e_verificar_valor_float("Informe o valor da Base Maior do Trapézio (cm): ");
				base_menor = solicitar_e_verificar_valor_float("Informe o valor da Base Menor do Trapézio (cm): ");
				altura = solicitar_e_verificar_valor_float("Informe o valor da Altura do Trapézio (cm): ");
				
				exibir_cabecalho();
				cout << "Área do Trapézio (cm²): " <<  calcular_area_trapezio(base_maior,base_menor, altura) << endl;
				break;
			default:
				exibir_cabecalho();
				cout << "Opção Inválida" << endl;
				system("pause");
				cin.clear();
				cin.ignore(100,'\n');
				continue;
		}
		system("pause");
	}while(true);
	
	system("pause");
	return 0;
}