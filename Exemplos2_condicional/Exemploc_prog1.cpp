/* Exercício 1: Verificando se um número é par ou ímpar */

#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main() 
{
    SetConsoleOutputCP(CP_UTF8);
	
    int numero;

    cout << "Digite um número : ";
    cin >> numero;
    
    cout << fixed << setprecision;
    // Verifica se o resto da divisão de numero por 2 é igual a 0. 
	// Se for, o número é par, senão é impar.
    if (numero % 2 == 0) {
        cout << numero << " é um número par." << endl;
    } else {
        cout << numero << " é um número ímpar." << endl;
    }

    return 0;
}
