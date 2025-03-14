/* Exercício 3: Função que não recebe nenhum valor, mas 
retorna um valor */

#include <iostream>
#include <Windows.h>

using namespace std;

// Função para gerar um número aleatório
int gerarNumeroAleatorio() {
    // Supondo que tenhamos uma função rand() para gerar 
	// números aleatórios
    return rand();
}

int main() 
{
	SetConsoleOutputCP(CP_UTF8);
    int numeroAleatorio = gerarNumeroAleatorio();
    cout << "Número aleatório: " << numeroAleatorio << endl;
    return 0;
}
