#include <iostream>
#include <Windows.h>

using namespace std;

struct No{
	int valor;
	No* proximo;
};

No* first = nullptr;

No* criar_no(int valor){
	No* newNo = new No;
	newNo->valor = valor;
	newNo->proximo = nullptr;
	
	return newNo;
}

void encadear_no(No* newNo){
	if (first!=nullptr){
		No* atual = first;
	    No* anterior = nullptr;
	    while(atual != nullptr){
	    	if (atual->valor>newNo->valor){
	    		newNo->proximo = atual;
	    		if(atual!=first){
	 				anterior -> proximo = newNo;
				}
				else{
					first = newNo;
				}
	    		break;
			}
			
			anterior = atual;
			atual = atual->proximo;
			if (atual == nullptr){
				anterior -> proximo = newNo;
			}
		}
	}else{
		first = newNo;
	}
}

void exibir_nos(){
	No* atual = first;
    
    cout << "\n=== Lista encadeada ===\n";
    while (atual != nullptr) 
	{
    	cout << "- "<< atual->valor << endl;
    	atual = atual->proximo;
	}   
    cout << endl;
}

int main(){
	
	SetConsoleOutputCP(CP_UTF8);
	encadear_no(criar_no(35));
	encadear_no(criar_no(5));
	encadear_no(criar_no(15));
	
	exibir_nos();
	
	system("pause");
	return 0;
}