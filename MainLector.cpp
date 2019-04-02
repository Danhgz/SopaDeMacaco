#include <iostream>
#include <fstream>
#include <stdlib.h> 
#include "Palabra.h"

using namespace std;
#define CANTIDAD 100

int main() {
	char cantidadPalabras[] ="0000";
	char palabra[25];
	int flag = 0;
	int numPalabras = 0;
	Palabra listaDePalabras[CANTIDAD];
	/*for (int i = 0; i < CANTIDAD; i++)
	{
		listaDePalabras[i].setHilera();
	}*/

	ifstream archivo("Ej1.txt");
	if (archivo.is_open()) {
		while (!archivo.eof()) {
			if (flag==0)
			{
				archivo.getline(cantidadPalabras, 4);
				flag = 1;
			}
			else {
				archivo.getline(palabra, 25);
				listaDePalabras[numPalabras].setHilera(palabra);
				numPalabras++;
			}					
			//cout << "paso" << endl;
		}
	}

	archivo.close();
	int cantidad = atoi(cantidadPalabras);
	for (int i = 0; i < cantidad; i++)
	{
		cout << listaDePalabras[i].getHilera() << endl;
		//listaDePalabras[i].setHilera('\0');
	}

	/*int cantidad = atoi(cantidadPalabras);
	
	


	ifstream archivo("Ej1.txt");
	archivo.getline(cantidadPalabras, 4);
	flag = 1;
	if (archivo.is_open()) {
		while (!archivo.eof()) {
			i
		}
	}
	archivo.close();*/
	
	//cout << cantidad << endl;
	/*for (int i = 0; i <= numCaracteres; i++) {
		if (i >= 0 && i <= 0) {
			cantidadPalabras = atoi(palabras);
			cout << "Cantidad de palabras: " << cantidadPalabras << endl;
		}
		else {
			cout << palabras[i];
		}
	}*/



	system("pause");
	return 0;
}