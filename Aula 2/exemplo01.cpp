#include <windows.h>
#include <iostream>

using namespace std;

    string multiplicar_str(string s, int count) {
            string retval;
            for (int i=0; i<count; i++) {
                    retval += s;
            }
            return retval;
}

int main(){

int x = 1;

while (x<=10){
	cout << x << endl;
	x++;
}

cout << multiplicar_str("-",30) << endl;

for (x=10; x>0;x--){
	cout << x << endl;
}

cout << multiplicar_str("-",30) << endl;

do{
	cout << x << endl;
	x++;
}while(x<=0);

return 0;
}