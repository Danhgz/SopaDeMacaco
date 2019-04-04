#pragma once
#ifndef _SOLUCIONADOR
#define _SOLUCIONADOR
#include "Palabra.h"
#include "Matriz.h"

class Solucionador {
private:
	int dirF[8] = {0,1,1, 1, 0,-1,-1,-1 };
	int dirC[8] = {1,1,0,-1,-1,-1, 0, 1 };
	char* dirNombre[8] = {(char*)"ESTE",(char*)"SURESTE",(char*)"SUR",(char*)"SUROESTE",(char*)"OESTE",(char*)"NOROESTE",(char*)"NORTE",(char*)"NORESTE"};
	int cantidadPalabras;
	Palabra* listaDePalabras;
	Matriz* sopa;
	int filasSopa;
	int colSopa;
	char* direccionResultado;

public:
	Solucionador();
	~Solucionador();
	void leerPalabras(char*);
	void leerSopa(char*);
	void solucionar(char*);
	int ochoDirecciones(int, int, Palabra, int&);
	int palabraRecursiva(int,int,Palabra, int, int);
};
#endif