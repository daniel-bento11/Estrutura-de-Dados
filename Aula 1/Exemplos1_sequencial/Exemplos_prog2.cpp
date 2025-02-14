/* Exercício 2: Conversão de Temperatura celsius em fahrenheit */

#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main() 
{
	SetConsoleOutputCP(CP_UTF8);
    float celsius, fahrenheit;

    cout << "Digite a temperatura em Celsius: ";
    cin >> celsius;

    fahrenheit = (celsius * 9/5) + 32;
	cout << fixed << setprecision(2);
	
    cout << celsius << " graus Celsius equivalem a " << fahrenheit << " graus Fahrenheit." << endl;

    return 0;
}
