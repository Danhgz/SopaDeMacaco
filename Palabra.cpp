#include "Palabra.h"

Palabra::Palabra() {
	length = 0;
	palabra = new char[length + 1];
	palabra[0] = '\0';
}
void Palabra::toLower(char * hilera) {
	if (hilera != 0) {
		int cantidadDeLetras = 0;
		while (hilera[cantidadDeLetras++] != '\0') {
		}
		palabra = new char[cantidadDeLetras];
		length = cantidadDeLetras - 1;
		for (int i = 0; i < cantidadDeLetras; ++i) {
			if (hilera[i] >= 'A' && hilera[i] <= 'Z') {
				palabra[i] = hilera[i] - 'A' + 'a';

			}
			else if (hilera[i] == 'Ü')
			{
				palabra[i] = 'u';
			}
			else if (hilera[i] == 'Ú')
			{
				palabra[i] = 'u';
			}
			else if (hilera[i] == 'Ó')
			{
				palabra[i] = 'o';
			}
			else if (hilera[i] == 'Í')
			{
				palabra[i] = 'i';
			}
			else if (hilera[i] == 'É')
			{
				palabra[i] = 'e';
			}
			else if (hilera[i] == 'Á')
			{
				palabra[i] = 'a';
			}
			else if (hilera[i] == 'Ñ')
			{
				palabra[i] = 'ñ';
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
Palabra::Palabra(char * hilera) {
	toLower(hilera);
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
		this->palabra = temporal.palabra;
		temporal.palabra = 0;
		//Para que el delete no me mate lo que me robe
		this->length = temporal.length;
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
