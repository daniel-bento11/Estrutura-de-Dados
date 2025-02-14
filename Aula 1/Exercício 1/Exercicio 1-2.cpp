#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main(){
	SetConsoleOutputCP(CP_UTF8);
	
	const float taxaDolar = 5.0;
	const float taxaEuro = 6.0;
	
	float real, dolar, euro;
	
	cout << "Digite o valor em reais (R$): ";
	cin >> real;
	
	dolar = real/taxaDolar;
	euro = real/taxaEuro;
	
	cout << fixed << setprecision(2);
	
	cout << "\nReais: R$ " << real << endl;
	cout << "Dólar: U$ " << dolar << endl;
	cout << "Euro: € " << euro << endl << endl;
	
	system("Pause");
}