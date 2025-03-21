/* Exercício 4: Função que recebe e retorna um valor */

#include <iostream>
#include <Windows.h>

using namespace std;

// Função para concatenar strings
string fnome(string nome,string sobrenome) {
    return nome+" "+sobrenome;
}

int main() 
{
	SetConsoleOutputCP(CP_UTF8);
    string nome="Wdson",sobrenome="Oliveira"; 
	   
    string nome_completo = fnome(nome,sobrenome);    
    cout << "O nome completo é: " << nome_completo << endl;
    
    return 0;
}
