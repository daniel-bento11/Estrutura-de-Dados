#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main(){
	SetConsoleOutputCP(CP_UTF8);
	float real,dolar, euro;
	cout << "Informe o valor em reais (R$): ";
	cin >> real;
	dolar = real * 5;
	euro = real * 6;
	
	cout << fixed << setprecision(2);		
	
	cout << "\nReais: R$ " << real << endl;
	cout << "Dólar: US$ " << dolar << endl;
	cout << "Euro: € " << euro << endl << endl;
	system("Pause");
	return 0;
	
}
