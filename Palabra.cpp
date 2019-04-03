#include "Palabra.h"

Palabra::Palabra() {
	length = 0;
	palabra = new char[length + 1];
	palabra[0] = '\0';
}

Palabra::Palabra(char * hilera) {
	if (hilera != 0) {
		int cantidadDeLetras = 0;
		while (hilera[cantidadDeLetras++] != '\0') {
		}
		palabra = new char[cantidadDeLetras];
		length = cantidadDeLetras - 1;
		for (int i = 0; i < cantidadDeLetras; ++i) {
			if (hilera[i] >= 'A' && hilera[i] <= 'Z') {
				palabra[i] = hilera[i] - 'A' + 'a';

			}else if (hilera[i] == 'Ü')
			{
				palabra[i] = hilera[i] - 25;
			}
			else if (hilera[i] == 'Ú')
			{
				palabra[i] = hilera[i] - 70;
			}
			else if (hilera[i] == 'Ó')
			{
				palabra[i] = hilera[i] - 62;
			}
			else if (hilera[i] == 'Í')
			{
				palabra[i] = hilera[i] - 63;
			}
			else if (hilera[i] == 'É')
			{
				palabra[i] = hilera[i] - 14;
			}
			else if (hilera[i] == 'Á')
			{
				palabra[i] = hilera[i] - 21;
			}
			else if (hilera[i] == 'Ñ')
			{
				palabra[i] = 'n';
			}
			else {
				palabra[i] = hilera[i];
			}
		}
	}
	else {
		length = 0;
		palabra = new char[length + 1];
		palabra[0] = '\0';
	}
	}

	Palabra::~Palabra() {
		if (palabra != 0) {
			delete[] palabra;
		}
	}

	int Palabra::equals(Palabra& otra) {
		int iguales = 0;
		if (length == otra.length) {
			iguales = 1;
			for (int i = 0; iguales && i < length; ++i) {
				iguales = palabra[i] == otra.palabra[i];
			}
		}
		return iguales;
	} // retorna 0 si son diferentes

	char * Palabra::getHilera() {
		return palabra;
	}

	void Palabra::setHilera(char * hilera) {
		Palabra temporal(hilera);
		palabra = temporal.palabra;
		temporal.palabra = 0;
		//Para que el delete no me mate lo que me robe
		length = temporal.length;
	}

	int Palabra::getLength() {
		return length;
	}

	char Palabra::charAt(int pos) {
		char letra = '\0';
		if (pos >= 0 && pos < length) {
			letra = palabra[pos];
		}
		return letra;
	}
