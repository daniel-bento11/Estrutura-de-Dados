/* Exercício 3: Função que não recebe nenhum valor, mas 
retorna um valor */

#include <iostream>
#include <Windows.h>
#include <ctime>   // Para time()

using namespace std;

// Função que calcula e retorna 5 + 3
int calcularSoma() {
    return 5 + 3;
}

int main() 
{
	SetConsoleOutputCP(CP_UTF8);
	// Chama a função e guarda o resultado
    int soma = calcularSoma(); 
    // Imprime o resultado
    cout << "O resultado da soma é: " << soma << endl; 
    return 0;
}
