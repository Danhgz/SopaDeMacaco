#ifndef _GENERADOR
#define _GENERADOR
#include<iostream>
#include "Matriz.h"
#include "Palabra.h"
using namespace std;
class Generador {
private:
	Matriz sopa;
	int filas;
	int columnas;
	Palabra *lista;
	int cantidad;
	int *posiciones;


public:
	Generador(Palabra*,int, int, int);
	void Generar();
	void Rellenar();
	void Randomizar(int*,int);
	void RandomizarDos(int*,int*,int);
	int PonerPalabra(Palabra,int,int,int);
	void Exportar(char *);
	void Imprimir();
	int PonerLetra(Palabra, int, int, int, int,int);
	int Recursivo(int);
	int valido(int, int,char);
	int *posicion(int);
	~Generador();
};
#endif
