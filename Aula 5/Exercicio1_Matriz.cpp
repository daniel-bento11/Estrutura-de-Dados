/*Exercício1: Manipulação de Matriz

-Declare uma matriz 3x3 de inteiros.
-Solicite ao usuário que digite os valores para cada elemento da matriz.
-Exiba os elementos da matriz no formato de matriz (linhas e colunas).
-Calcule a soma de todos os elementos da matriz.
-Encontre o maior e o menor elemento da matriz.
-Solicite ao usuário que digite um elemento para contar suas ocorrências 
 na matriz.
-Conte o número de ocorrências do elemento fornecido na matriz.
-Exiba a soma, o maior, o menor elemento e o número de ocorrências do 
 elemento fornecido.*/

#include <iostream>
#include <Windows.h>

using namespace std;

int main() 
{
	SetConsoleOutputCP(CP_UTF8);
	
    int matriz[3][3];
    int soma = 0;
    int maior, menor;
    int elementoContagem, ocorrencias = 0;

    // Entrada dos elementos da matriz
    cout << "Digite os elementos da matriz 3x3:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Elemento [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // Exibi os elementos da matriz
    cout << "\nMatriz digitada:" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matriz[i][j] << " ";
        }
        cout << endl;
    }

    // Calculo da soma dos elementos da matriz
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            soma += matriz[i][j];
        }
    }

    // Pesquisa pelo maior e menor elemento da matriz
    maior = matriz[0][0];
    menor = matriz[0][0];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] > maior) {
                maior = matriz[i][j];
            }
            if (matriz[i][j] < menor) {
                menor = matriz[i][j];
            }
        }
    }

    // Pesquisa o numero de ocorrência de um determinado elemento 
	//da matriz
    cout << "\nDigite o elemento a ser contado na matriz: ";
    cin >> elementoContagem;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] == elementoContagem) {
                ocorrencias++;
            }
        }
    }

    // Apresenta os resultados
    cout << "\nA soma dos elementos da matriz é: " << soma << endl;
    cout << "O maior elemento da matriz é: " << maior << endl;
    cout << "O menor elemento da matriz é: " << menor << endl;
    cout << "O número de ocorrências de " << elementoContagem << " na matriz é: " << ocorrencias << endl;

    return 0;
}