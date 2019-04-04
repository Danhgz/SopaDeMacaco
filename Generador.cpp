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
	Rellenar();

	
}
/*
*@Funci�n: llama el m�todo recursivo 
*/
void Generador::Generar() {
	int pos = 0;
		Recursivo(0);
}
/*
*@Funci�n: funci�n que se encarga de realizar llamados a otros m�todos y poner todas las palabras dentro de la sopa de letras
*@Param: el n�mero de la palabra para ir revisando cual palabra se est� poniendo en la sopa de letras
*@Return: retorna un 1(true) si logra poner todas las palabras en la sopa de letras
*/
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
/*
*@Funci�n: se encarga de exportar un archivo txt con la sopa de letras
*@Param: la ruta destino del archivo
*/
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
/*
*@Funci�n: se encarga de imprimir la sopa de letras
*/
void Generador::Imprimir() {
	sopa.imprimir(cout);
}
/*
*@Funci�n: se encarga de poner la palabra dentro de la sopa de letras siguiendo una direcci�n especifica de las 8 posibles
*@Param x: la posici�n actual en x de la matriz
*@Param y: la posici�n actual en y de la matriz
*@Param palabra: una palabra de la clase Palabra
*@Param carac: el numero de caracter por el cual va el recorrido en la hilera que corresponde a la palabra
*@Return: retorna un 1(true) si logra poner la palabra dentro de la sopa con �xito
*/
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
/*
*@Funci�n: rellena los espacios de la sopa de letra restantes que han quedado con un s�mbolo de relleno, con letras aleatorias entre a y z
*/
void Generador::Rellenar() {
	for (int i = 0; i < filas; i++)
	{
		for (int j = 0; j < columnas; j++)
		{
			if (sopa.getValor(i, j) == '*') {
				sopa.setValor(i, j, rand() % 24 + 'a');
			}
		}
		}
}
/*
*@Funci�n: m�todo recursivo que se encarga de verificar si una posici�n en la sopa es valida siguiendo cierta direcci�n para ir poniendo cada caracter de la palabra
*@Param palabra: una palabra de la clase Palabra
*@Param x: la posici�n actual en x de la matriz
*@Param y: la posici�n actual en y de la matriz
*@Param dx: suma en una direcci�n para la x actual en la matriz
*@Param dy: suma en una direcci�n para la y actual en la matriz
*@Param carac: para ir aumentando el caracter que se pone de la palabra en la sopa
*@Return: retorna un 1(true) si logra poner la letra de la palabra en la sopa de letras en la posici�n x,y
*/
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

/*
*@Funci�n: se encarga de verificar si la posici�n en la matriz es v�lida
*@Param x: la posici�n actual en x de la matriz
*@Param y: la posici�n actual en y de la matriz
*@Param letra: una letra de la palabra
*@Return:  retorna 1(true) si se cumplen las condiciones especificadas
*/
int Generador::valido(int x,int y,char letra){
	return (x < columnas && y < filas && (sopa.getValor(x, y) == '*' || sopa.getValor(x, y) == letra));

}
/*
*@Funci�n: se encarga de generar posiciones aleatorias dentro de un vector
*@Param *vector: el vector a randomizar
*@Param maximo: el tama�o del vector 
*/
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
/*
*@Funci�n: se encarga de generar posiciones aleatorias en dos vectores
*@Param *vector1: el primer vector a randomizar
*@Param *vector2: el segundo vector a randomizar
*@Param maximo: el tama�o maximo de los vectores
*/
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
/*
*@Funci�n: da las coordenadas de una posici�n
*@Param: la posici�n que se busca
*@Return: retorna las coordenadas de un punto dentro de la matriz
*/
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
