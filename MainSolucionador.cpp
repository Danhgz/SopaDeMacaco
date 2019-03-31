#include "Matriz.h"
#include<iostream>
using namespace std;
int main() {
	Matriz matriz(3, 3);
	Matriz matriz2;

	matriz.setValor(1, 1, 'X');
	matriz.imprimir(cout);

	// matriz2 = matriz; // Copia a nivel de miembro
	matriz2.asignar(matriz);


	matriz2.setValor(0, 0, 'A');

	Matriz * ptr = new Matriz(10, 10);



	cout << "*ptr" << endl;
	ptr->imprimir(cout);

	ptr->asignar(matriz2);

	ptr->setValor(0, 1, 'Z');
	cout << "*ptr" << endl;
	ptr->imprimir(cout);
	cout << "Matriz 1" << endl;
	matriz.imprimir(cout);

	cout << "Matriz 2" << endl;
	matriz2.imprimir(cout);
	cout << "ALTO" << endl;

	delete ptr;
	cin.get();
	return 0;
}