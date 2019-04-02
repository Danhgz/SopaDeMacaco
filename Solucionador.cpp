#include <iostream>
#include <fstream>
#include "Solucionador.h"
#include "Palabra.h"

#define CANTIDAD 100
using namespace std;

void leerPalabras(char* nombreArchivo) {
	char cantidadPalabras[] = "0000";
	char palabra[25];
	int flag = 0;
	int numPalabras = 0;
	Palabra listaDePalabras[CANTIDAD];

	ifstream archivo(nombreArchivo);
	if (archivo.is_open()) {
		archivo.getline(cantidadPalabras, 4);
		while (!archivo.eof()) {
			archivo.getline(palabra, 25);
			listaDePalabras[numPalabras++].setHilera(palabra);
		}
	}
	archivo.close();

	int cantidad = atoi(cantidadPalabras);
}