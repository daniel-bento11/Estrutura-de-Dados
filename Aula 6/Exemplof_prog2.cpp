/* Exercício 2: Função que recebe um valor, mas não 
retorna nada void */

#include <iostream>
#include <Windows.h>

using namespace std;

// Função para imprimir um número
void imprimirNumero(int numero) {
    cout << "O número é: " << numero << endl;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int num = 42;
    imprimirNumero(num);
    return 0;
}