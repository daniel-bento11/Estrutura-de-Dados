/*Exercício 1: Cálculo de Área de um Retângulo*/

/*Biblioteca padrão de entrada e saída. 
ler dados do teclado (cin) e imprimir dados na tela (cout).*/
#include <iostream>

/*Biblioteca específica do Windows.
Fornece acesso a diversas funções do sistema, incluindo funções para 
manipular a saída para o console.*/
#include <Windows.h>

/*
Defini o número de casas decimais, alinhamento, preenchimento e outros 
aspectos da apresentação dos dados.
Exemplo: formatar a saída da média com duas casas decimais, utilizando 
fixed e setprecision. 
*/
#include <iomanip>

/*Permite utilizar os elementos do namespace std 
(como cout e cin) sem precisar digitar "std::" antes deles, tornando 
o código mais conciso.*/
using namespace std;

//Função principal onde o programa inicia a execução
int main() 
{
	/* Configura a saída do console para utilizar a codificação UTF-8. 
     CP_UTF8 é uma constante que representa a codificação UTF-8.*/
	SetConsoleOutputCP(CP_UTF8);
	
    // Declaração de variáveis do tipo float 
    float base, altura, area;

    //Lê os valores da base e altura do usuário
    cout << "Digite a base do retângulo: ";
    cin >> base;

    cout << "Digite a altura do retângulo: ";
    cin >> altura;

    //Calcula a área do retângulo
    area = base * altura;

	// Formatando a saída com duas casas decimais
    cout << fixed << setprecision(2);
    
    //Imprime o resultado
    cout << "A área do retângulo é: " << area << endl;

    //system("pause");
    system("PAUSE>>null");
    
	//Indica que o programa foi executado com sucesso, sem erros. 
	//É o valor convencionalmente utilizado para indicar um término bem-sucedido
    return 0;
}