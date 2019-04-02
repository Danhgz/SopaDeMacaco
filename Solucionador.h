#pragma once
#ifndef _PALABROTA
#define _PALABROTA
#include "Palabra.h"

class Palabra {
private:
	int cantidadDePalabras;
	Palabra* listaDePalabras;
	char** sopa;
	int tamanoSopa;
	char* direccionResultado;

public:
	void leerPalabras(char*);
	void leerSopa(char*);

	
};
#endif