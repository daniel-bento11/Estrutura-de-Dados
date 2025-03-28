#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

struct registro {
    string nome;
    int codigo;
    int idade;
    float salario;
};

double pega_valor(string mensagem){
	double valor;
	while(true){
		cout << mensagem;
		cin >> valor;
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\nEntrada inválida !!\n";
			continue;
		}
		if (valor <= 0){
			cout << "\nValor não pode ser negativo\n";
			continue;
		}
		return valor;
		
	}
}



int main() 
{
	SetConsoleOutputCP(CP_UTF8);
	
    const int maxFuncionarios = 10; // Tamanho máximo do array
    registro funcionarios[maxFuncionarios]; // Array estático de structs
    int numFuncionarios;
    
    while (true)
	{
    	cout << "\nDigite o número de funcionários (máximo " << maxFuncionarios << "): ";
    	cin >> numFuncionarios;
    	if (numFuncionarios > maxFuncionarios) {
        	cout << "\nNúmero de funcionários excede o limite máximo.\n";
        	continue;
        }
        if (cin.fail())
		{        		
        	cin.clear();
        	cin.ignore(100,'\n');
			cout << "\nEntrada inválida\n";	
	    } 
	    else{
	    	break;
		}
    } 
    
    // Entrada de dados para cada funcionário
    for (int i = 0; i < numFuncionarios; i++) 
	{
        cout << "\nDigite os dados do funcionário " << i + 1 << ":\n";
        
        while(true) // validação do nome 
  		{   
  			cout << "\nDigite o nome    -> ";
  			// Limpa o buffer do teclado
    		cin.ignore(); 
    		// Usando getline para ler nomes com espaços
  			getline(cin,funcionarios[i].nome);
  			if (!funcionarios[i].nome.empty()){
  				break;
    		}
    		else{
    		cout << "\nNome não pode ser vazio";
			}
  		} 
 
        funcionarios[i].codigo = pega_valor("Digite o código    -> "); 
        funcionarios[i].idade  = pega_valor("Digite a idade     -> ");
        funcionarios[i].salario = pega_valor("Digite o salário: -> ");       
    }
    // Exibição dos dados de cada funcionário
    cout << "\n\nDados dos Funcionários:\n";
	cout << setw(20) << left << "Nome" << setw(10) << left << "Código" 
	     << setw(10) << left << "Idade" << setw(15) << left << "Salário (R$)" << endl;
    cout << "------------------------------------------------------------\n";

    for (int i = 0; i < numFuncionarios; i++) 
	{
        cout << setw(20) << left << funcionarios[i].nome
             << setw(10) << left << funcionarios[i].codigo
             << setw(10) << left << funcionarios[i].idade
             << setw(15) << left << fixed << setprecision(2) 
			 << funcionarios[i].salario << endl;
    }
	
    return 0;
}