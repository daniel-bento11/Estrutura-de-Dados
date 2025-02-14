/*Exercício 5: Concatenação de strings*/
#include <iostream>
#include <Windows.h>

using namespace std;


int main() 
{
	SetConsoleOutputCP(CP_UTF8);
	/*Em C++, as strings são objetos da classe string, que oferece 
	diversos métodos (funções) para manipular strings.*/
    string nome;
    string sobrenome;
    cout << "Digite o nome : ";
    getline(cin, nome); 
    cout << "Digite o sobrenome : ";
    getline(cin, sobrenome); 
    string nomeCompleto = nome + " " + sobrenome;

    cout << "Nome completo: " << nomeCompleto << endl;

    // Tamanho da string
    cout << "Tamanho do nome completo: " << nomeCompleto.size() << endl;

    // Substring
    cout << "Primeiro nome: " << nomeCompleto.substr(0, nome.size()) << endl;

    // Substituir parte da string
    nomeCompleto.replace(0, 5, "Ana");
    cout << "Nome alterado: " << nomeCompleto << endl;

    return 0;
}