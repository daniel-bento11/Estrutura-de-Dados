/* Exercício 3: Cálculo de Desconto do produto */

#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main() 
{
	SetConsoleOutputCP(CP_UTF8);
    float preco, desconto, precoFinal;
    int percentualDesconto;

    cout << "Digite o preço do produto: R$ ";
    cin >> preco;

    cout << "Digite o percentual de desconto (%): ";
    cin >> percentualDesconto;

    desconto = preco * (percentualDesconto / 100.0);
    precoFinal = preco - desconto;

	cout << fixed << setprecision(2);
	
    cout << "O valor do desconto é: R$ " << desconto << endl;
    cout << "O preço final é: R$ " << precoFinal << endl;

    return 0;
}