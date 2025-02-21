#include <windows.h>
#include <iostream>
#include <iomanip>

#define tam 7

using namespace std;



string produtos[tam];
int qtd_produtos[tam];  
int i=0;

void exibir_cabecalho(){
	cout << "Gerenciamento de Vendas" << endl;
}

int calcular_total(){
	int total = 0;
	
	for(int t=0; t<tam; t++){
		total=total+qtd_produtos[t];
	}
	return total;
}

float calcular_media(){
	float media = calcular_total()/tam;
	return media;
}

string achar_produto_mais_vendido(){
	int mais_vendido = qtd_produtos[0];
	string produto = produtos[0];
	for (i=1; i<tam; i++){
		if (qtd_produtos[i]>mais_vendido){
			mais_vendido = qtd_produtos[i];
			produto = produtos[i];
		}
	}
	
	return produto;
}

string achar_produto_menos_vendido(){
	int menos_vendido = qtd_produtos[0];
	string produto = produtos[0];
	for (i=1; i<tam; i++){
		if (qtd_produtos[i]<menos_vendido){
			menos_vendido = qtd_produtos[i];
			produto = produtos[i];
		}
	}
	
	return produto;
}

bool achar_produtos_abaixo_media(int produto, float media){
	if (qtd_produtos[produto]<media){
		return true;
	}
	return false;
}


int main(){
	
	SetConsoleOutputCP(CP_UTF8);
	
	exibir_cabecalho();
	
	for (i=0; i<tam;i++){
		cout << "\nNome do produto " << i+1 << ": ";
		cin >> produtos[i];
		cout << "Quantidade Vendida: ";
		cin >> qtd_produtos[i];
	}
	
	cout << "\nTotal Vendido: " << calcular_total() << endl;
	cout << fixed << setprecision(2);
	cout << "Média de Vendas: " << calcular_media() << endl;
	cout << "Produto Mais Vendido: " << achar_produto_mais_vendido() << endl;
	cout << "Produto Menos Vendido: " << achar_produto_menos_vendido() << endl;
	cout << "\nProdutos Abaixo da Média: " << endl;
	
	for (i=0; i<tam; i++){
		if(achar_produtos_abaixo_media(i, calcular_media())){
			cout << "- " << produtos[i] << endl;
		}
	}
	
	return 0;
}