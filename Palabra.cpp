// clase creada por el profesor en clases
#include "Palabra.h"

Palabra::Palabra() {
	length = 0;
	palabra = new char[length + 1];
	palabra[0] = '\0';
}
/**
*@FunciÛn: recibe hilera de caracteres y genera una palabra  nueva, adem·s se encarga de convertir caracteres especiales como ‹⁄”Õ…¡— a minusculas y las que poseen una tilde, esta es removida
*@Param hilera: puntero que apunta a una hilera de caracteres para crear una nueva palabra
*/
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
			else if (hilera[i] == '‹')
			{
				palabra[i] = 'u';
			}
			else if (hilera[i] == '⁄')
			{
				palabra[i] = 'u';
			}
			else if (hilera[i] == '”')
			{
				palabra[i] = 'o';
			}
			else if (hilera[i] == 'Õ')
			{
				palabra[i] = 'i';
			}
			else if (hilera[i] == '…')
			{
				palabra[i] = 'e';
			}
			else if (hilera[i] == '¡')
			{
				palabra[i] = 'a';
			}
			else if (hilera[i] == '—')
			{
				palabra[i] = 'Ò';
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
	/*
	*@FunciÛn: determina si una palabra es igual a otra, la cual se recibe como parametro
	*@Param: se recibe una palabra del tipo Palabra
	*@Return: retorna 1 si son iguales o 0 si son diferentes, lo cual significa verdadero o falso respectivamente
	*/
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
	/*
	*@FunciÛn: encuentra un caracter en una posiciÛn especificada como par·metro 
	*@Param: se recibe un int que indica la posiciÛn en la cual se desea buscar el caracter en la hilera 
	*@Return: retorna el char encontrado en la posiciÛn indicada
	*/
	char Palabra::charAt(int pos) {
		char letra = '\0';
		if (pos >= 0 && pos < length) {
			letra = palabra[pos];
		}
		return letra;
	}
