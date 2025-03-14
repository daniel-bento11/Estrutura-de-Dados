/* Exercício 1: Função que não recebe nem retorna 
nada (void) */

#include <iostream>
#include <Windows.h>

using namespace std;

// Função para imprimir uma mensagem
void imprimirMensagem() {
    cout << "Olá, mundo!" << endl;
}

int main() {
	SetConsoleOutputCP(CP_UTF8);
    imprimirMensagem();
    return 0;
}
