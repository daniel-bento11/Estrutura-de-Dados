#include <windows.h>
#include <iostream>

#define TAM 5 

using namespace std;

int main (){
	
	SetConsoleOutputCP(CP_UTF8);
	
	int vetor [TAM];
	int maior,menor;
	
	for (int i = 0; i<TAM;i++){
		cout << "Número " << i + 1 << ": ";
		cin >> vetor[i];
	}
	
	maior = vetor[0];
	menor = vetor[0];
	
	for (int i=0; i<TAM;i++){
		if (vetor[i]>maior){
			maior = vetor[i];
		}
	}
	
	for (int i = 0; i<TAM;i++){
		if(vetor[i]<menor){
			menor = vetor[i];
		}
	}
	
	cout << "Maior Número: " << maior << endl;
	cout << "Menor Número: " << menor << endl;
	
	return 0;
}