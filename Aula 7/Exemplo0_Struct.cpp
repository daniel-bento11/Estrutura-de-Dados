/*Uma struct (estrutura) é um tipo de dado composto que 
permite agrupar variáveis de diferentes tipos sob um único 
nome. 

Principais características:
==========================

Agrupamento de dados: Permite combinar variáveis de tipos 
diferentes (int, float, char, etc.) em uma única unidade.

Membros: As variáveis dentro de uma struct são chamadas de 
"membros".

Acesso aos membros: Os membros são acessados usando o operador 
ponto (.).

As structs são muito semelhantes a classes, com a principal 
diferença sendo que os membros de uma struct são públicos por 
padrão, enquanto os membros de uma classe são privados por 
padrão.
*/


#include <iostream>
#include <Windows.h>

using namespace std;

struct Pessoa 
{
    string nome;
    int idade;
    double altura;
};

int main() 
{
	SetConsoleOutputCP(CP_UTF8);
	
	// declara as variaveis pessoa1 e pessoa2 do tipo Pessoa
    Pessoa pessoa1, pessoa2;
    
    // Atribui valores aos membros da struct - pessoa1
    pessoa1.nome = "João de Oliveira"; 
    pessoa1.idade = 30;
    pessoa1.altura = 1.75;

    cout << "Nome  : " << pessoa1.nome << endl;
    cout << "Idade : " << pessoa1.idade << endl;
    cout << "Altura: " << pessoa1.altura << endl << endl;
    
    // Atribui valores aos membros da struct - pessoa2
    pessoa2.nome = "Maria de Oliveira"; 
    pessoa2.idade = 35;
    pessoa2.altura = 1.65;

    cout << "Nome  : " << pessoa2.nome << endl;
    cout << "Idade : " << pessoa2.idade << endl;
    cout << "Altura: " << pessoa2.altura << endl;
    
    return 0;
}
