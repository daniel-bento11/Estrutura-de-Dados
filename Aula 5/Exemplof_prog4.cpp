/* Exercício 4: Função que recebe e retorna um valor */

#include <iostream>
#include <Windows.h>

using namespace std;

// Função para dobrar um número
int dobrarNumero(int numero) {
    return numero * 2;
}

int main() {
	SetConsoleOutputCP(CP_UTF8);
    int num = 5;
    int resultado = dobrarNumero(num);
    cout << "O dobro de " << num << " é: " << resultado << endl;
    return 0;
}
