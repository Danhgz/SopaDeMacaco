#include <iostream>
#include <fstream>
#include <stdlib.h> 
using namespace std;

int main() {
	int cantidadPalabras = 0;
	char palabras[10000];
	int numCaracteres = 0;
	fstream my_stream;
	my_stream.open("ejemplo1.txt");
	if (my_stream.is_open()) {
		while (!my_stream.eof()) {
			my_stream.get(palabras[numCaracteres]);
			numCaracteres++;
		}
	}
	my_stream.close();

	for (int i = 0; i <= numCaracteres; i++) {
		if (i >= 0 && i <= 1) {
			cantidadPalabras = atoi(palabras);
			cout << "Cantidad de palabras: " << cantidadPalabras << endl;
		}
		else {
			cout << palabras[i];
		}
	}
	system("pause");
	return 0;
}