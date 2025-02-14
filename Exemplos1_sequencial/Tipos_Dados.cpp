/* ===== Tipos Fundamentais ====== */

/*Biblioteca padrão de entrada e saída. 
ler dados do teclado (cin) e imprimir dados na tela (cout).*/
#include <iostream>

/*Biblioteca específica do Windows.
Fornece acesso a diversas funções do sistema, incluindo funções 
para manipular a saída para o console.*/
#include <Windows.h>

/*Permite utilizar os elementos do namespace std 
(como cout e cin) sem precisar digitar "std::" antes deles, 
tornando o código mais conciso.*/
using namespace std; 

int main() 
{
  SetConsoleOutputCP(CP_UTF8);
  
  /* ===== Tipos Fundamentais ====== */

  // Inteiros
  int idade = 30; // armazenar números inteiros positivos e negativos (4 bytes)
  unsigned int quantidade = 100; // armazena apenas números inteiros positivos ou zero
  long int distancia = 150000;//  precisa de um intervalo maior de valores inteiros 

  // Ponto Flutuante

  float peso = 75.5; // precisão simples (7 dígitos significativos)
  double pi = 3.141592653589793; // precisão dupla (15 dígitos significativos)

  // Caracteres
  char letra = 'J';// um único caractere (1 byte)
  string nome = "Wdson de Oliveira"; // uma sequência de caracteres (*)

  // Booleano
  bool aprovado = true;// true é implicitamente convertido para o valor inteiro 1
  bool reprovado = false;// false é implicitamente convertido para o valor inteiro 0.
  
  // Saída de dados

  cout << "==== Tipos Fundamentais ====" << endl<< endl;
  
  cout << "Idade........: " << idade << endl;
  cout << "Quantidade...: " << quantidade << endl;
  cout << "Distância....: " << distancia << endl;
  cout << "Peso.........: " << peso << endl;
  cout << "Pi...........: " << pi << endl;
  
  cout << "Letra........: " << letra << endl;
  cout << "Nome.........: " << nome << endl << endl;
  
  cout << "Aprovado.....: " << aprovado << endl;
  cout << "Reprovado....: " << reprovado << endl;

  return 0;
}