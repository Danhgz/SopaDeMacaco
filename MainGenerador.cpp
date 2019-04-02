#include<iostream>
#include<cstring>
#include <stdlib.h> 
#include <fstream> 
#include "Palabra.h"
#include "Generador.h"
#include "Matriz.h"
using namespace std;
#define CANTIDAD 100
int main(int argc, char * * argv) {

	if (4 == argc || 5 == argc)
	{
		int err = 0;
		string ruta= "Ej1.txt";
		int colum = atoi(argv[2]);
		int filas = atoi(argv[3]);
		string salida = "sopadeletras.txt";
		if ((strlen(argv[1]) - ruta.rfind(".txt")) != 4 || colum==0 || filas==0) {
			err++;
		}
		if (5 == argc) {
			salida = argv[4];
		}
		if (!err) {


			char cantidadPalabras[] = "0000";
			char palabra[25];
			int flag = 0;
			int numPalabras = 0;
			Palabra listaDePalabras[CANTIDAD];
			ifstream archivo(ruta);
			if (archivo.is_open()) {
				while (!archivo.eof()) {
					if (flag == 0)
					{
						archivo.getline(cantidadPalabras, 4);
						flag = 1;
					}
					else {
						archivo.getline(palabra, 25);
						listaDePalabras[numPalabras].setHilera(palabra);
						numPalabras++;
					}
				}
			}

			archivo.close();
			int cantidad = atoi(cantidadPalabras);
			Generador gen(listaDePalabras, cantidad);
			/*ofstream sal(salida);
			
			for (int i = 0; i < cantidad; i++)
			{

				sal << listaDePalabras[i].getHilera();
			}*/

		}
		else
		{
			cout << "Algun error hubo" << endl;
		}

	}
	return 0;
}