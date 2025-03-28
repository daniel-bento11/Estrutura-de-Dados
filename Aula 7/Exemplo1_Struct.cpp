#include <iostream>
#include <iomanip>
#include <Windows.h>

using namespace std;

struct registro
{
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
  
  registro func;
  cout << "\n<<< Digite as informações do funcionário >>>\n\n";
  
  while(true) // validação do nome 
  {
  	
  	cout << "\nDigite o nome    -> ";
    // Usando getline para ler nomes com espaços
  	getline(cin,func.nome);
  	if (!func.nome.empty()){
  		break;
    }
    else{
    	cout << "\nNome não pode ser vazio";
	}
	}
  
  func.codigo = pega_valor("Digite o código -> "); 

  func.idade = pega_valor("Digite a idade   -> ");
  
  func.salario = pega_valor("Digite o salário -> ");
  
  cout << "\n\n>> Dados do Funcionário << \n\n";
 
  cout << "Nome:    " << func.nome << "\n";
  cout << "Código:  " << func.codigo << "\n";
  cout << "Idade:   " << func.idade << "\n";
  cout << "Salário: R$ " << fixed << setprecision(2) << func.salario << "\n\n";

  return 0;   
}
