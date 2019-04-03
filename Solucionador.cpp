#include <iostream>
#include <fstream>
#include "Solucionador.h"

#define CANTIDAD 100
using namespace std;

Solucionador::Solucionador() { 
}
Solucionador::~Solucionador() {
}

void Solucionador::leerPalabras(char* nombreArchivo) {
	char inputPalabras[] = "0000";
	char palabra[25];
	int numPalabras = 0;
	this->listaDePalabras = new Palabra[CANTIDAD];
	ifstream archivo(nombreArchivo);
	if (archivo.is_open()) {
		archivo.getline(inputPalabras, 5);
		cout << "Cantidad de palabras: "<<inputPalabras<< endl;
		while (!archivo.eof()) {
			archivo.getline(palabra, 26);
			listaDePalabras[numPalabras++].setHilera(palabra);
		}

	}
	archivo.close();
	cantidadPalabras = atoi(inputPalabras);
}

void Solucionador::leerSopa(char* nombreArchivo) {
	char inputFilas[] = "00";
	char inputColumnas[] = "00";

	ifstream archivo(nombreArchivo);
	if (archivo.is_open()) {

		archivo.getline(inputFilas, 3,' ');
		archivo.getline(inputColumnas, 3, '\n');
		filasSopa = atoi(inputFilas);
		colSopa = atoi(inputColumnas);
		sopa = new Matriz(filasSopa, colSopa);
		int i = 0; 
		int j = 0;
		char aux;
		while (!archivo.eof()){
			aux = archivo.get();
			if (aux != ' '&& aux != '\n') {
				sopa->setValor(i, j++, aux);
			}
			else
				if (j==colSopa){
					j = 0;
					++i;
				}			
		}
	}
	archivo.close();
}

void Solucionador::solucionar(char* solucionario) {
	int numPalabra = 0;
	int contadorDir = 0;
	int lengthPalabra = 0;
	for (int f = 0; f < filasSopa; ++f ) {
		lengthPalabra = listaDePalabras[numPalabra].getLength();
		for (int c = 0; c < colSopa; ++c) {
			if (listaDePalabras[numPalabra].charAt(0) == sopa->getValor(f,c)) { 
				if (ochoDirecciones(f, c, listaDePalabras[numPalabra], 0, contadorDir)) {
					if (solucionario != 0) {
						ofstream salida(solucionario);
						salida << listaDePalabras[numPalabra].getHilera() << " en fila: " << f << ", columna: " << c << " " << dirNombre[contadorDir] << endl;
					}
					else {
						cout << listaDePalabras[numPalabra].getHilera() << " en fila: " << f << ", columna: " << c << " " << dirNombre[contadorDir] << endl;
					}
					if (numPalabra <= cantidadPalabras) {
						++numPalabra;
					}
				}		
			}
		}
	}
}

int Solucionador::ochoDirecciones(int f, int c, Palabra palabra, int posPalabra, int& contadorDir)
{
	int sePudo = 0; 
	for (int i = 0; i<8 && !sePudo; ++i)
	{
		sePudo=palabraRecursiva(f, c, palabra, 0, i);
		if (sePudo) {
			contadorDir = i;
		}
	}
	return sePudo;
}

int Solucionador::palabraRecursiva(int f, int c, Palabra palabra, int posPalabra, int& contadorDir) {
	int sePudo = 0;
	int palabraLength = palabra.getLength();
	
	if (sopa->esPosicionValida(f,c)) {
		if (sopa->getValor(f,c) == palabra.charAt(palabraLength)){
			sePudo = 1;
		}
		else{
			if(posPalabra < palabraLength && sopa->getValor(f,c) == palabra.charAt(posPalabra)) {
				sePudo = palabraRecursiva(f + dirF[contadorDir], c + dirC[contadorDir], palabra, posPalabra + 1, contadorDir);
			}
		}
	}
	return sePudo;
}
