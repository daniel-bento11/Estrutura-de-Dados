/* Exercício 2: Calculando a média e verificando se o aluno foi aprovado */

#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

int main() 
{
    SetConsoleOutputCP(CP_UTF8);

    string nomeAluno;
    float nota1, nota2, media;

    cout << "Digite o nome do aluno: ";
    getline(cin, nomeAluno);

    cout << "Digite a primeira nota: ";
    cin >> nota1;

    cout << "Digite a segunda nota: ";
    cin >> nota2;

    media = (nota1 + nota2) / 2;

    // Formatando a saída com duas casas decimais
    cout << fixed << setprecision(2);

    cout << "\nResultado Final:" << endl;
    cout << "Aluno: " << nomeAluno << endl;
    cout << "Média: " << media << endl;

    if (media >= 6) {
        cout << "Aprovado!" << endl;
    } else {
        cout << "Reprovado!" << endl;
    }

    return 0;
}