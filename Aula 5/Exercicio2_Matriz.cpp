/*
Exercício2: Controle de Estoque de uma Loja

Uma loja vende 4 produtos diferentes (A, B, C, D) e possui 
3 filiais. O gerente da loja deseja controlar o estoque 
de cada produto em cada filial. Para isso, ele utiliza uma 
matriz 3x4, onde as linhas representam as filiais e as colunas 
representam os produtos.

O programa deverá realizar as seguintes funcionalidades:

-Declarar uma matriz 3x4 de inteiros para representar o estoque da loja.
-Solicitar ao usuário que digite a quantidade de cada produto em cada filial.
-Exibir o estoque da loja no formato de matriz, mostrando a quantidade de 
 cada produto em cada filial.
-Calcular e exibir o total de cada produto em todas as filiais.
-Calcular e exibir o total de produtos em cada filial.

#Em C++, quando você escreve 'A', o compilador entende que você está se 
 referindo ao valor ASCII do caractere 'A', que é 65.
 'A' + j:

Essa expressão soma o valor de j ao valor ASCII de 'A'.
Para cada valor de j:

for 0: 65 + 0 = 65 (que é 'A')
for 1: 65 + 1 = 66 (que é 'B')
for 2: 65 + 2 = 67 (que é 'C')
for 3: 65 + 3 = 68 (que é 'D')

O (char) é um "cast", ou seja, uma conversão de tipo. Ele pega o resultado 
da soma (que é um número inteiro) e o converte de volta para um caractere.
*/

#include <iostream>
#include <Windows.h>
#include <iomanip>
#define filiais 3
#define produtos 4

using namespace std;

void exibir_cabecalho(){
	system("cls");
	cout << "Controle de Estoque de uma Loja" << endl << endl;
}

int main() 
{
	int matriz[filiais][produtos];
	
	exibir_cabecalho();
	
	for(int i=0; i<filiais; i++){
		cout << "Filial " << i+1 << endl;
		for (int j=0; j<produtos;j++){
			cout << "Quantidade Produto " << (char)('A'+j) << ": ";
            cin >> matriz[i][j];
		}
		exibir_cabecalho();
	}
	
    cout << setw(8) << "Produto"; 
    for (char c = 'A'; c < 'A' + produtos; c++) {
        cout << setw(6) << c << " ";  
    }
    cout << endl;

    
    for (int i = 0; i < filiais; i++) {
        cout << setw(8) << "Filial " << i + 1; 
        for (int j = 0; j < produtos; j++) {
            cout << setw(6) << matriz[i][j] << " "; 
        }
        cout << endl;
    }
    
    cout << endl;
    
    for (int i = 0; i < filiais; i++) {
    	int somaFilial = 0;
        for (int j = 0; j < produtos; j++) {
            somaFilial += matriz[i][j];
        }
        cout << "Total de Produtos Filial " << i+1 << " : " << somaFilial << endl;
    }
    
    cout << endl;
    
    for (int i = 0; i < produtos; i++) {
    	int somaProdutos =0;
        for (int j = 0; j < filiais; j++) {
            somaProdutos += matriz[j][i];
        }
        cout << "Total de Produtos " << (char)('A'+i) << " : " << somaProdutos << endl;
    }
    
	
	SetConsoleOutputCP(CP_UTF8);

	return 0;	
}




