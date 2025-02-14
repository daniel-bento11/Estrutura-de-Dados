#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main()

{
    SetConsoleOutputCP(CP_UTF8);
    int opcao;
	float num1, num2;

    cout << "=== Calculadora Simples ===" << endl;
    cout << "1. Soma" << endl;
    cout << "2. Subtração" << endl;
    cout << "3. Multiplicação" << endl;
    cout << "4. Divisão" << endl;
    cout << "Digite a opção desejada: ";
    cin >> opcao;

    cout << "Digite o primeiro número: ";
    cin >> num1;
    cout << "Digite o segundo número: ";
    cin >> num2;

    cout << fixed << setprecision(2);
    
    switch (opcao) {
        case 1:
            cout << "Resultado: " << num1 + num2 << endl;
            break;
        case 2:
            cout << "Resultado: " << num1 - num2 << endl;
            break;
        case 3:
            cout << "Resultado: " << num1 * num2 << endl;
            break;
        case 4:
            if (num2 == 0) {
                cout << "Erro: Divisão por zero!" << endl;
            } else {
                cout << "Resultado: " << num1 / num2 << endl;
            }
            break;
        default:
            cout << "Opção inválida." << endl;
    }

    return 0;
}
