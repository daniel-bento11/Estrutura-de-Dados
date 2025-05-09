#include <windows.h>
#include <iostream>
#include <iomanip>


using namespace std;

struct Paciente{
	int codigo;
	string nome;
	int idade;
	int qtd;
	Paciente* proximo;
};

int nmrPacientes = 0;
int nmrPacientes_n_atendidos = 0;
int nmrPacientes_atendidos = 0;
Paciente* first = nullptr;

void exibir_header(string text){
	system("cls");
	cout<< "---------------------" << endl;
	cout<< text << endl;
	cout<< "---------------------" << endl << endl;
}

void exibir_menu(){
	cout << "1. Inserir Paciente" << endl;
	cout << "2. Exibir Informações" << endl;
	cout << "3. Efetivar Consultas" << endl;
	cout << "4. Sair" << endl << endl;
}

void exibir_menu2(){
	cout << "1. Exibir Pacientes Não Atendidos" << endl;
	cout << "2. Exibir Pacientes Atendidos" << endl;
	cout << "3. Exibir Todos os Pacientes Cadastrados" << endl;
	cout << "4. Voltar ao Menu Principal" << endl<< endl;
}

double pegar_valor(string mensagem){
	double valor;
	while(true){
		cout << mensagem;
		cin >> valor;
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			cout << "Entrada inválida !!" << endl << endl;
			continue;
		}
		if (valor <= 0){
			cout << "Valor deve ser maior que 0" << endl << endl;
			continue;
		}
		return valor;
	}
}

string pegar_string(string mensagem){
	string valor;
	
	while(true){
		cin.ignore();
		cout << mensagem;
		getline(cin,valor);
		if (!valor.empty()){
			return valor;
		}else{
			cout << "Não pode ser vazio!" << endl << endl ;
		}
	}
}

bool verificar_existencia(int cod){
	if (first != nullptr){
		Paciente* atual = first;
		while (atual != nullptr){
			if(atual->codigo == cod){
				return false;
			}
			atual=atual->proximo;
		}
		return true;
	}
	return true;
}

void incrementar_consulta(int cod){
		Paciente* atual = first;
		while (atual != nullptr){
			if(atual->codigo == cod){
				if (atual->qtd == 0){
					nmrPacientes_n_atendidos--;
					nmrPacientes_atendidos++;
				}
				atual->qtd++;
				exibir_header("Consulta Efetivada!");
				cout << "Consulta para o Paciente " << atual->nome
				<< " Efetivada com Sucesso!" << endl;
				cout << "Total de Consultas: " << atual->qtd << endl; 	 
				break;
			}
			atual=atual->proximo;
		}
}

Paciente* criar_no(int cod, string nome, int idade){
	Paciente* newPaciente = new Paciente;
	newPaciente->codigo = cod;
	newPaciente->nome = nome;
	newPaciente->idade = idade;
	newPaciente->qtd = 0;
	newPaciente->proximo = nullptr;
	
	nmrPacientes++;
	nmrPacientes_n_atendidos++;
	return newPaciente;
}

void encadear_no(Paciente* newPaciente){
	Paciente* atual = first;
	if (atual != nullptr){
		while(atual->proximo != nullptr){
			atual = atual->proximo;
		}
		atual->proximo = newPaciente;
	}else{
		first = newPaciente;
	}
}

void exibir_pacientes(int filtro){
	Paciente* atual = first;
	if (filtro==1){
		exibir_header("Pacientes não Atendidos");
		cout << setw(10) << left << "Codigo" << setw(20) << left << "Nome" 
	    << setw(15) << left << "Idade" << setw(15) << left << "Qtd Consultas" << endl;
    	cout << "------------------------------------------------------------" << endl;
    	
		while(atual != nullptr){
			if(atual->qtd==0){
				cout << setw(10) << left << atual->codigo
	            << setw(20) << left << atual->nome
	            << setw(15) << left << atual->idade
	            << setw(15) << left << atual->qtd
				<< endl;
			}
			
			atual = atual->proximo;
		}
			 	
		cout << "------------------------------------------------------------" << endl << endl;
		
	}else if(filtro == 2){
		exibir_header("Pacientes Atendidos");
		cout << setw(10) << left << "Codigo" << setw(20) << left << "Nome" 
	    << setw(15) << left << "Idade" << setw(15) << left<< "Qtd Consultas" << endl;
    	cout << "------------------------------------------------------------" << endl;
    	
		while(atual != nullptr){
			if(atual->qtd>0){
		
				cout << setw(10) << left << atual->codigo
	            << setw(20) << left << atual->nome
	            << setw(15) << left << atual->idade
	            << setw(15) << left << atual->qtd
				<< endl;
			}
			atual = atual->proximo;
		}
			 	
		cout << "------------------------------------------------------------" << endl << endl;
	}else{
		exibir_header("Pacientes Cadastrados");
		cout << setw(10) << left << "Codigo" << setw(20) << left << "Nome" 
	    << setw(15) << left << "Idade" << setw(15) << left<< "Qtd Consultas" << endl;
    	cout << "------------------------------------------------------------" << endl;
    	
		while(atual != nullptr){
			cout << setw(10) << left << atual->codigo
            << setw(20) << left << atual->nome
            << setw(15) << left << atual->idade
            << setw(15) << left << atual->qtd
			<< endl;
			
			atual = atual->proximo;
		}
			 	
		cout << "------------------------------------------------------------" << endl << endl;
	}

}

void limpar_memoria(){
	Paciente* atual = first;
	
	if(atual != nullptr){
		Paciente* proximo = nullptr;
		while (atual != nullptr){
			proximo = atual->proximo;
			delete atual;
			atual = proximo;
		}
	}
	first = nullptr;
	nmrPacientes = 0;
	nmrPacientes_n_atendidos = 0;
	nmrPacientes_atendidos = 0;
}

int main(){
	
	SetConsoleOutputCP(CP_UTF8);
	
	int opt, opt2, cod, idade;
	string nome;
	
	do{
		exibir_header("Clínica Medix - Controle de Pacientes");
		exibir_menu();
		
		cout << "O que deseja fazer?" << endl;
		cin >> opt;
		
		if (opt == 4){
			break;
		}
		
		if (cin.fail()){
			cin.clear();
			cin.ignore(100,'\n');
			exibir_header("Entrada Inválida");
			system("pause");
			continue;
		}
		switch(opt){
			case 1:
				do{
					exibir_header("Inserir Novo Paciente");
					cod = pegar_valor("Insira o Código do Paciente: ");
					if (verificar_existencia(cod)){
						break;	
					}else{	
						exibir_header("Erro: Código de Paciente já cadastrado!");
						system("pause");
					}
				}while(true);
				
				nome = pegar_string("Insira o Nome do Paciente: ");
				idade = pegar_valor("Insira a Idade do Paciente: ");
				encadear_no(criar_no(cod, nome, idade));
				exibir_header("Paciente criado com sucesso!");	
				
				system("pause");
				break;
			
			case 2:
				if (nmrPacientes > 0){
					do{
						exibir_header("Exibir Informações");
						exibir_menu2();
						
						cout << "O que deseja fazer?" << endl;
						cin >> opt2;
						
						if (opt2 == 4){
							break;
						}
						
						if (cin.fail()){
							cin.clear();
							cin.ignore(100,'\n');
							exibir_header("Entrada Inválida");
							system("pause");
							continue;
						}
						
						switch(opt2){
							case 1:
								if(nmrPacientes_n_atendidos > 0){
									exibir_pacientes(1);
								}else{
									exibir_header("Nenhum Paciente não Atendido Encontrado!");
								}
								system("pause");
								break;
							case 2:
								if(nmrPacientes_atendidos > 0){
									exibir_pacientes(2);
								}else{
									exibir_header("Nenhum Paciente Atendido Encontrado!");
								}
								system("pause");
								break;
								
							case 3:
								exibir_pacientes(3);
								system("pause");
								break;
							default:
								exibir_header("Opção Inválida!");
								system("pause");
						}
					}while(true);
				}else{
					exibir_header("Nenhum Paciente Cadastrado!");
					system("pause");
				}
				break;
				
			case 3:
				if (nmrPacientes>0){
					exibir_header("Efetivar Consulta");
					cod = pegar_valor("Informe o Código do Paciente: ");
					if (!verificar_existencia(cod)){
						incrementar_consulta(cod);
					}else{
						exibir_header("Paciente não Encontrado!");
					}
				}else{
					exibir_header("Nenhum Paciente Cadastrado!");
				}
				system("pause");
				break;
			default: 
				exibir_header("Opção Inválida!");
				system("pause");
		}
		
	}while(true);
	
	limpar_memoria();
	exibir_header("Encerrando o programa. Memória liberada!");
	system("pause");
	return 0;
}