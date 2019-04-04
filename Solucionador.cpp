#include <iostream>
#include <fstream>
#include "Solucionador.h"

#define CANTIDAD 100
using namespace std;

Solucionador::Solucionador() { 
}
Solucionador::~Solucionador() {
}
/*
*@Función: se encarga de leer el archivo .txt con la lista de palabras y guardarlas en un array de tipo Palabra
*@Param: recibe el archivo .txt
*/
void Solucionador::leerPalabras(char* nombreArchivo) {
	char inputPalabras[] = "000";
	char palabra[25];
	int numPalabras = 0;
	this->listaDePalabras = new Palabra[CANTIDAD];
	ifstream archivo(nombreArchivo);
	if (archivo.is_open()) {
		archivo.getline(inputPalabras, 4);
		while (!archivo.eof()) {
			archivo.getline(palabra, 26);
			listaDePalabras[numPalabras++].setHilera(palabra);
			cout << listaDePalabras[numPalabras-1].getHilera() << endl;
		}
	}
	archivo.close();
	cantidadPalabras = atoi(inputPalabras);
}
/*
*@Función: se encarga de leer el archivo .txt que contiene la sopa de letras
*@Param: recibe el archivo .txt con la sopa de letras
*/
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
	sopa->imprimir(cout);
}
/*
*@Función: se encarga de dar las soluciones cuando encuentra cada una de las palabras dentro de la sopa
*@Param: corresponde al nombre del archivo de respuestas
*/
void Solucionador::solucionar(char* solucionario) {
	int numPalabra = 0;
	int contadorDir = 0;
	int lengthPalabra = listaDePalabras[numPalabra].getLength();

	for (int f = 0; f < filasSopa && numPalabra<cantidadPalabras; ++f ) {	
		for (int c = 0; c < colSopa && numPalabra < cantidadPalabras; ++c)	{
			if (listaDePalabras[numPalabra].charAt(0) == sopa->getValor(f,c)) 
			{ 
				if (ochoDirecciones(f, c, listaDePalabras[numPalabra], contadorDir)) 
				{
					cout << "><";// pa ver que pasa
					if (solucionario != 0) {
						ofstream(salida);
						salida <<"-->"<< listaDePalabras[numPalabra].getHilera() << " en fila: " << f << ", columna: " << c << " direccion " << dirNombre[contadorDir] << endl;
					}else {
						cout <<"-->"<< listaDePalabras[numPalabra].getHilera() << " en fila: " << f << ", columna: " << c << " direccion "<< dirNombre[contadorDir] << endl;
					}
					if (numPalabra < cantidadPalabras) 
					{
						cout << numPalabra + 1 <<" de: "<<cantidadPalabras<<endl;//Para ver si lee las palabras
						++numPalabra;
						f = 0;
						c = 0;
						lengthPalabra = listaDePalabras[numPalabra].getLength();
					}
				}		
			}
		}
	}
	if (solucionario != 0) {
		cout <<endl<< "El archivo " << solucionario << " fue escrito exitosamente";
	}
}
/*
*@Función: se encarga de buscar la palabra en las 8 direcciones posibles dentro de la sopa
*@Param f: la fila de la matriz a partir de la cual se comienza a buscar
*@Param c: la columna de la matriz a partir de la cual se comienza a buscar
*@Param palabra: palabra de tipo Palabra 
*@Param contadorDir: dato de tipo int por referencia que corresponde al numero de dirección entre 0 a 8 que se está siguiendo
*@Return: retorna 1(true) si se pudo encontrar la palabra en la dirección que se esté siguiendo 
*/
int Solucionador::ochoDirecciones(int f, int c, Palabra palabra, int& contadorDir){
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
/*
*@Función: se encarga de determinar si la palabra que entra como parámetro es igual a la palabra que se encuentra en la sopa, esto lo hace comparando cada char. Se hace recursivamente
*@Param f: la fila de la matriz a partir de la cual se comienza a buscar
*@Param c: la columna de la matriz a partir de la cual se comienza a buscar
*@Param palabra: palabra de tipo Palabra 
*@Param posPalabra: parámetro de tipo int que indica un carácter especifico de toda la palabra en esa posición 
*@Param dir: la dirección especifica de todas las 8 existentes en la cual se está buscando la palabra 
*@Return:
*/
int Solucionador::palabraRecursiva(int f, int c, Palabra palabra, int posPalabra, int dir) {
	int sePudo = 0;
	int palabraLength = palabra.getLength();

	if (sopa->esPosicionValida(f,c)) {
		if (sopa->getValor(f,c) == palabra.charAt(palabraLength-1)){
			sePudo = 1;
		}
		else{
			if(posPalabra < palabraLength && sopa->getValor(f,c) == palabra.charAt(posPalabra)) {
				sePudo = palabraRecursiva(f + dirF[dir], c + dirC[dir], palabra, (posPalabra + 1), dir);
			}
		}
	}
	return sePudo;
}
