#include "Generador.h".
#include "Palabra.h"
#include "Matriz.h"
#include<iostream>
#define DIRX {0,1,1,1,0,-1,-1,-1}
#define DIRY {1,1,0,-1,-1,-1,0,1}


using namespace std;


Generador::Generador(Palabra * listaPalabras ,int cantidad, int filas, int columnas) {
	Palabra *lista = new Palabra[cantidad];
	filas-- > filas;
	columnas-- > columnas;
	cantidad-- > cantidad;
	for ( int i = 0; i < cantidad;  i++)
	{
		lista[i].setHilera(listaPalabras[i].getHilera());
		cout << lista[i].charAt(2) << endl;
		
	}
	
}

void Generador::Generar() {
	Matriz sopa(filas, columnas);
	//int *posiciones = new int[filas*columnas];
	int pos = 0;
	int *coord;
	for (int i = 0; i < cantidad; i++)
	{
		PonerPalabra(lista[i]);


		/*pos = rand() % (filas*columnas);
		coord = posicion(pos);
		if ((valido(coord[0], coord[1], lista[i].charAt(0)))) {


		}*/

	}
}

int Generador::Recursivo(int numPalabra) {
	
	int exito = 0;
	int salir = 0;
	int *coords;
	int loPuso = 0;
	int *posRand = new int[filas*columnas];
	int cont = 0;
	
	Randomizar(posRand,filas*columnas);

	do {
		 coords = posicion(posRand[cont]);
		 cont++;
		 loPuso = 0;
	     loPuso=PonerPalabra(lista[numPalabra], coords[0], coords[1],0);
		 if (loPuso & numPalabra + 1 <= cantidad) {
			 Recursivo(numPalabra + 1);
		 }
		 if (cont >= filas * columnas) {
			 salir = 1;
		 }
	} while (!salir);
	if(salir!=1){
		PonerPalabra(lista[numPalabra], coords[0], coords[1],0);
	}
	else {

	};
	
	

	
}
int Generador::PonerPalabra(Palabra palabra,int x,int y,int carac){
	int exito = 1;
	int Dx[8] = { 0,1,1,1,0,-1,-1,-1 };
	int	Dy[8] = { 1,1,0,-1,-1,-1,0,1 };
	Randomizar(Dx, 8);
	Randomizar(Dy, 8);
	int direccion = 0;
	if (valido(x, y, palabra.charAt(carac))) {		
		do
		{
			if (carac++ > palabra.getLength()) {
				exito = PonerLetra(palabra, x + Dx[direccion], y + Dy[direccion], Dx[direccion], Dy[direccion], carac++);
			}
		} while (exito==0 && direccion<8);
	}	
}

int Generador::PonerLetra(Palabra palabra, int x, int y, int dx, int dy, int carac) {
	int exito = 0;
	if ( valido(x, y, palabra.charAt(carac))) {
		if (carac++ > palabra.getLength()) {
			exito = PonerLetra(palabra, x + dx , y + dy, dx, dy, carac++);
		}
		else {
			exito = 1;
			sopa[x][y]=
		}
	}
	
}


int Generador::valido(int x,int y,char letra){
	return (x < columnas && y < filas && (sopa.getValor(x, y) == '0' || sopa.getValor(x, y) == letra));

}
void Generador::Randomizar(int *vector, int maximo) {
	for (int i = 0; i < maximo; i++)
	{
		vector[i] = i;
	}
	int tempA;
	int posA;
	int posB;
	for (int i = 0; i < maximo; i++)
	{
		posA = rand() % maximo;
		posB = rand() % maximo;
		tempA = vector[posA];
		vector[posA] += vector[posB];
		vector[posB] = tempA;
		vector[posA] -= vector[posB];

	}
}
int *Generador::posicion(int pos ) {
	int y = pos / (columnas );
	int x = pos % (columnas);
	int coor[2] = { x,y };
	return coor;
}

Generador::~Generador(){
	if (lista != 0) {
		delete[] lista;
	}
}
