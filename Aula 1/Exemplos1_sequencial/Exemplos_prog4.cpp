/*Exercício 4: Dados Pessoais*/

#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main() 
{
	SetConsoleOutputCP(CP_UTF8);
    string nome;
    int idade;
    float altura;

    cout << "Digite seu nome: ";
	
    getline(cin, nome); // Lê uma linha completa, incluindo espaços

    cout << "Digite sua idade: ";
    cin >> idade;

    cout << "Digite sua altura (em metros): ";
    cin >> altura;
    
     cout << fixed << setprecision(2);

    // saída com concatenação de strings para formar a mensagem final
    cout << "\nOlá, " << nome << "! Você tem " << idade << " anos e " << altura << " metros de altura." << endl;

    return 0;
}
