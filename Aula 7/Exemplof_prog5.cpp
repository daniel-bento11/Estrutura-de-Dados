/*Exercicio5-Programa para  calcular a área de figuras 
geométricas : quadrado, círculo, triângulo ou 
trapézio.
As funções receberão os parâmetros enviados
pelo programa principal e retornarão o resultado
para serem apresentados ao usuário.

Menu de opções:

1.Área do quadrado  -> lado * lado
2.Área do círculo   -> M_PI * pow(raio,2)
#include <cmath> 
pow(raio,2)
3.Área do triângulo -> (base * altura) / 2
4.Área do trapézio  -> ((base_maior + base_menor)*altura)/2
5.Sair
*/

// Importação da bibliotecas
#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cmath>
using namespace std;

// Implementação das funções 

void menu(){
	cout << "\n==== Menu de Opções ====\n";
	cout << "\n1.Quadrado";	
	cout << "\n2.Circulo";
	cout << "\n3.Triangulo";
	cout << "\n4.Trapézio";
	cout << "\n5.Sair";	
}

double pega_double(string mensagem){
	double valor;
	while(true){
		cout << mensagem;
		cin >> valor;
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\nEntrada inválida !!\n";
			continue;
		}
		if (valor <= 0){
			cout << "\nValor não pode ser negativo\n";
			continue;
		}
		return valor;
		
	}
}

double areaquadrado(double lado){
	return lado * lado;
}

double areacirculo(double raio){
	return M_PI * pow(raio,2);
} 

double areatriangulo(double base,double altura){
	return (base*altura)/2;
}

double areatrapezio(double basemaior, double basemenor, double altura){
	return ((basemaior+basemenor)*altura)/2;
}


// Programa Princiapal

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	int op;
	double lado, raio, base, altura, basemaior,basemenor;
	while(true) // controle de execução do programa principal
	{
	  system("cls");
	  menu();
	  cout << "\nDigite a opção desejada : ";
	  cin >> op;
	  if (op == 5){
	  	system("cls");
	  	break;
	  }
	  // validação de entrada da operação
	  if (cin.fail()){
	  	cin.clear();
	  	cin.ignore(100,'\n');
	  	cout << "\nEntrada inválida\n";
	  	system("pause");
	  	continue;
	  }
	  cout << fixed << setprecision(2);
	  switch(op){
	  	case 1:
	  		lado = pega_double("Digite a medida do lado : ");
	  		cout << "A área do quadrado = " << areaquadrado(lado) << "\n";
	  		break;
	  	case 2:
	  		raio = pega_double("Digite o valor do raio : ");
	  		cout << "A área do circulo = " << areacirculo(raio) << "\n";
	  		break;	
	  	case 3:
	  		base = pega_double("Digite o valor da base : ");
	  		altura = pega_double("Digite o valor da altura : ");
	  		cout << "A área do triangulo = " << areatriangulo(base,altura) << "\n";
	  		break;
	  	case 4:
	  		basemaior = pega_double("Digite o valor da base maior : ");
	  		basemenor = pega_double("Digite o valor da base menor : ");
	  		altura = pega_double("Digite o valor da altura : ");
	  	    cout << "A área do trápezio = " << areatrapezio(basemaior,basemenor,altura) << "\n"; 
	  		break;
	  	default:
	  		cout << "\nEntrada inválida: Digite a op de 1 a 5\n";
	  }
	  system("pause");
		
	} // fim do looping do ppp
	
 return 0;	
}


