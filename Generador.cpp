#include "Generador.h"
#include "Palabra.h"
#include "Matriz.h"
#include<fstream>  
#include<iostream>
#define DIRX {0,1,1,1,0,-1,-1,-1}
#define DIRY {1,1,0,-1,-1,-1,0,1}


using namespace std;


Generador::Generador(Palabra * listaPalabras ,int cantidad, int filas, int columnas):sopa(filas,columnas)
{
	this->lista = new Palabra[cantidad];
	this-> filas=filas;	
	this-> columnas	= columnas;
	this-> cantidad=cantidad;

	for ( int i = 0; i < cantidad;  i++)
	{
		lista[i].setHilera(listaPalabras[i].getHilera());
		
	}

	Generar();

	
}

void Generador::Generar() {
	int pos = 0;
		Recursivo(0);
}

int Generador::Recursivo(int numPalabra) {	
	int exito = 0;
	int salir = 0;
	int *coords = new int[2];
	int loPuso = 0;
	int *posRand = new int[filas*columnas];
	int cont = 0;
	for (int i = 0; i < filas*columnas; i++)
	{
		posRand[i] = i;
	}
	Randomizar(posRand,filas*columnas);

	do {
		 coords = posicion(posRand[cont]);		 
		 loPuso = 0;	
		 
		 loPuso = PonerPalabra(lista[numPalabra], coords[0], coords[1], 0);
		 if (loPuso!=0 && (numPalabra+1) < cantidad) {
			 loPuso=Recursivo(numPalabra + 1);
		 }
		 if (loPuso == 0){
			 cont++;
		 }
		 if ( loPuso==1 ||cont >= filas * columnas /*|| numPalabra +1 == cantidad*/) {
			 salir = 1;
		 }
	} while (salir==0);

	return loPuso;

}
void Generador::Exportar(char *ruta) {
	ofstream salida(ruta);
	salida << filas << " x " << columnas << endl;
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j <columnas; j++)
		{
			salida << sopa.getValor(i, j) << " " ;

		}
		salida << endl;
	}
}
void Generador::Imprimir() {
	sopa.imprimir(cout);
}
int Generador::PonerPalabra(Palabra palabra,int x,int y,int carac){
	int exito = 0;	
	int Dx[8] = { 0,1,1,1,0,-1,-1,-1 };
	int	Dy[8] = { 1,1,0,-1,-1,-1,0,1 };
	RandomizarDos(Dx,Dy,8);
	int direccion = 0;
	
	if (valido(x, y, palabra.charAt(carac))) {
		do
		{

				if ((carac+1) < palabra.getLength()){
				exito = PonerLetra(palabra, x + Dx[direccion], y + Dy[direccion], Dx[direccion], Dy[direccion], 1);
				}
				else {
					exito = 1;
				}
			direccion++;
		} while (exito == 0 && direccion < 8);

		if (exito !=0) {
			sopa.setValor(x, y, palabra.charAt(0));
		}

	}
	return exito;
}
void Generador::Rellenar() {

}
int Generador::PonerLetra(Palabra palabra, int x, int y, int dx, int dy, int carac) {
	int exito = 0;
	if ( valido(x, y, palabra.charAt(carac))) {
		if (carac+1 < palabra.getLength()) {
			exito = PonerLetra(palabra, x + dx , y + dy, dx, dy, carac+1);

		}
		else {
			exito = 1;
			
		}
		if (exito == 1) {
			sopa.setValor(x, y, palabra.charAt(carac));
		}
	}
	return exito;
}


int Generador::valido(int x,int y,char letra){
	return (x < columnas && y < filas && (sopa.getValor(x, y) == '*' || sopa.getValor(x, y) == letra));

}
void Generador::Randomizar(int *vector, int maximo) {
	int tempA;
	int tempB;
	int posA;
	int posB;
	for (int i = 0; i < maximo; i++)
	{
		posA = rand() % maximo;
		posB = rand() % maximo;
		tempA = vector[posA];
		tempB = vector[posB];
		vector[posA] = tempB;
		vector[posB] = tempA;


	}
}void Generador::RandomizarDos(int *vector1, int *vector2, int maximo) {
	int tempA;
	int tempB;
	int posA;
	int posB;
	for (int i = 0; i < maximo; i++)
	{
		posA = rand() % maximo;
		posB = rand() % maximo;
		tempA = vector1[posA];
		tempB = vector1[posB];
		vector1[posA] = tempB;
		vector1[posB] = tempA;
		tempA = vector2[posA];
		tempB = vector2[posB];
		vector2[posA] = tempB;
		vector2[posB] = tempA;


	}
}
int *Generador::posicion(int pos ) {
	int y = pos / (columnas );
	int x = pos % (columnas);
	int *coor=new int[2];
	coor[0] = x;
	coor[1] = y;
	return coor;
}

Generador::~Generador(){
	if (lista != 0) {
		delete[] lista;
	}
}
