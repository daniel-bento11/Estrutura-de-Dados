#include <windows.h>
#include <iostream>
#include <iomanip>

#define TAM 5

using namespace std;

int main (){
	
	SetConsoleOutputCP(CP_UTF8);
	float notas[TAM];
	float media, soma_notas=0;
	

	
	cout << fixed << setprecision(2);
	
	for (int i = 0; i<TAM; i++){
		cout << "Nota " << i + 1 << ": ";
		cin >> notas[i];
	}
	
	cout << "\nNotas: " << endl;
	
	for (int i=0; i<TAM;i++){
		cout << notas[i] << endl;
		soma_notas = soma_notas+notas[i];
	}
	
	media = soma_notas/TAM;
	cout << "\nMédia: " << media << endl;
	
	if (media >=6){
		cout << "Aprovado!" << endl;
	}else {
		cout << "Reprovado!" << endl;
	}

	return 0;
}