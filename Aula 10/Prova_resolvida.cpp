//====== Biliotecas ====== //
#include <iostream>
#include <Windows.h>
#include <iomanip>

using namespace std;

//====== Estrutura do Nó ====== //
struct No
{
	int codigo;
	string nome;
	int idade;
	int quantc;
	No* proximo;
};

//====== Implementação das funções =======//

// Função para mostrar o menu //
void menu()
{
	cout << "\n\n====== Menu de Opções ======\n\n";
	cout << "1. Inserir paciente\n";
    cout << "2. Listar pacientes\n";
    cout << "3. Efetivar consulta\n";
    cout << "4. Sair\n\n";
}

// Função para criar um novo nó //
No* criarNo(int codigo, string nome, int idade, int quantc)
{
	No* novoNo = new No;
	novoNo->codigo = codigo ;
	novoNo->nome = nome;
	novoNo->idade = idade;
	novoNo->quantc = quantc ;
	novoNo->proximo = nullptr;
	return novoNo;
}

// Função para exibir a lista de pacientes //
void listar_pacientes(No* cabeca, int atendido) {
    //cout << "\n======= Lista de pacientes " << (atendido == 1 ? "atendidos" : "não atendidos") << " ========\n";
    if (atendido == 1) {
    	cout << "\n======= Lista de pacientes atendidos ========\n";
    } else {
    	cout << "\n======= Lista de pacientes não atendidos ====\n";
    }
    cout << setw(10) << left << "Código" << setw(20) << left << "Nome" << setw(10) << left << "Idade" << setw(10) << left << "Quant.Cons." << endl;
    No* atual = cabeca;
    while (atual != nullptr) {
        if ((atendido == 1 && atual->quantc > 0) || (atendido == 0 && atual->quantc == 0)) {
            cout << setw(10) << left << atual->codigo << setw(20) << left << atual->nome << setw(10) << left << atual->idade << setw(10) << left << atual->quantc << endl;
        }
        atual = atual->proximo;
    }
}


// Função que lê e valida um valor //
int le_valida_valor(string mensagem)
{
	int valor;
	while(true){
		cout << mensagem;
		cin >> valor;
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\nEntrada inválida: não aceita caracter !!\n";
			continue;
		}
		if (valor < 0){
			cout << "\nEntrada inválida: valor não pode ser negativo\n";
			continue;
		}
		return valor;		
	}
}

// Função que lê e valida uma string //
string le_valida_string(string mensagem)
{
	string campo;
	while(true){			
		cout << mensagem;
        cin.ignore();
        getline(cin,campo);
    	if (!campo.empty()){
  			return campo;
    	}
    	else{
    		cout << "\nString não pode ser vazia";
		}
	}
}

// Função valida a opção digitada //
int le_valida_opcao(int menor,int maior)
{
	int op;
	while(true){
		cout << "\nDigite a opção desejada : ";
		cin >> op;
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "\nEntrada inválida: não aceita caracter !!\n";
			continue;
		}
		if (op >= menor and op <= maior){
			return op; // retorna a opção válida
		}
		else{
			cout << "\nEntrada inválida: Digite um nro entre " 
			     << menor << " e " << maior << "\n";	
		}
	}
}

// Função que verifica se o codigo já existe : senão cadastra //
void verifica_codigo_cadastrar(No* cabeca, int codigo)
{
	int idade, quantc;
	string nome;
	No* atual = cabeca; 
	if (atual->codigo == codigo){
		cout << "Codigo já cadastrado \n";
		return;	
	}
	// procura se existe o codigo na lista
	while (atual->proximo != nullptr){
		if (atual->proximo->codigo == codigo){
			cout << "Codigo já cadastrado \n";
			return;
		}
		atual = atual->proximo;
	}
	nome   = le_valida_string("Digite o nome  : ");
	idade  = le_valida_valor("Digite a Idade  : ");
	quantc = 0;
	atual->proximo = criarNo(codigo, nome, idade, quantc);
	cout << "\nPaciente com codigo " << codigo << " inserido com sucesso!!";
	return;
}

// Função para efetivar a consulta //
void efetiva_consulta(No* cabeca,int codigo){
	No* atual = cabeca; 
	if (atual->codigo == codigo){
		atual->quantc += 1;
		cout << "Consulta do paciente " << codigo << " efetivada com sucesso\n";
		return;	
	}
	while (atual->proximo != nullptr){
		if (atual->proximo->codigo == codigo){
			atual->proximo->quantc += 1;
			cout << "Consulta do paciente " << codigo << " efetivada com sucesso\n";
			return;
		}
		atual = atual->proximo;
	}
	if (atual->proximo == nullptr){
		cout << "Paciente não encontrado com o codigo " << codigo << "\n";
	}
}

/*======= Programa Principal =====*/

int main()
{
 	SetConsoleOutputCP(CP_UTF8);
 	int opcao,idade,codigo,quantc,atendido;
 	string nome;
 	No* cabeca = nullptr; 
 	while(true)
 	{
 		menu();
 		opcao = le_valida_opcao(1,4);
 		if (opcao == 4)
		{
 			system("cls");
 			break;
		}
 		switch (opcao)
		{
			case 1: // Inserir na sequência
				codigo = le_valida_valor("Digite o Código : ");
				if (cabeca == nullptr){
					nome   = le_valida_string("Digite o nome  : ");
					idade  = le_valida_valor("Digite a Idade  : ");
					quantc = 0;
					cabeca = criarNo(codigo, nome, idade, quantc);
				}
				else{
					verifica_codigo_cadastrar(cabeca, codigo);
				}
				break;
			case 2: 
				if (cabeca != nullptr){
					while(true){	
						atendido = le_valida_valor("Atendidos (1) - Não atendidos (0) ? ");
						if (atendido != 1 && atendido != 0){
							continue;
						}
						break;					
				    }	
					listar_pacientes(cabeca, atendido);
		     	}   
				else{
					cout << "Lista de pacientes vazia !!";
				}	
				break; 
			case 3: 
				if (cabeca != nullptr){
					codigo = le_valida_valor("Digite o Código : ");
					efetiva_consulta(cabeca,codigo);					
				}	
				else{
					cout << "Lista de pacientes vazia !!";
				}		
				break;
     	} 
     	cout << "\n";
     	system("pause");
     	system("cls");
	}
	if (cabeca != nullptr){
		// Limpeza da memória 
		cout << "deletando todos os nós da lista de pacientes\n";
    	while (cabeca != nullptr) {
        	No* temp = cabeca;
        	cabeca = cabeca->proximo;
        	delete temp;
    	}
	}	
	return 0;	
}
