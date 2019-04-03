#ifndef MATRIZ_G02
#define MATRIZ_G02
#define RELLENO '*'
#include<iostream>
using namespace std;
class Matriz {
   private:
      int filas;
	  int columnas;
	  char **m;
	  
	  void _init(int,int,char);
	  void _liberar();
   public:
      Matriz(); // Constructor por omision
	  Matriz(int,int); // Constructor con parametros
	  Matriz(const Matriz &); // Constructor de copia
	  ~Matriz();
	  void asignar(const Matriz &);
	  int esPosicionValida(int,int);
      void setValor(int,int,char);
	  char getValor(int,int);
	  void imprimir( ostream & );
};
#endif