// clase creada por el profesor en clases
#include "Matriz.h"
#include<iostream>
using namespace std;
/*
*@Función: inicializa el tamaño de las filas y columnas de la matriz, además asigna un caracter de relleno a cada posición 
*@Param filas: parámetro de tipo int que indica la cantidad de filas que posee la matriz
*@Param columnas: parámetro de tipo int que indica la cantidad de columnas que posee la matriz
*@Param relleno: parámetro de tipo char que indica el relleno que se asignará en cada posición de la matriz de f x c
*/
void Matriz::_init(int filas,int columnas, char relleno){
   this->filas = 0;
   this->columnas = 0;
   this->m = 0; // apunta a nulo
   if(filas>0 && columnas>0){   
	  this->filas = filas;
      this->columnas = columnas;	  
	  m = new char * [filas];
      for(int f=0; f< filas; ++f){
		m[f] = new char [columnas];
        for(int c=0; c<columnas; ++c){
			m[f][c] = relleno;
		}		
	  }	  
   }   
}
/*
*@Función: se encarga de eliminar las filas y las columnas de la matriz creada, esto para el destructor
*/
void Matriz::_liberar(){ 
   if(m){ 
	  for(int f=filas-1; f >=0; --f){
		  delete [] m[f];
	  }   
	  delete [] m; 
   }
}
Matriz::Matriz(){ 
  _init(0,0,RELLENO);
}
Matriz::Matriz(int filas, int columnas){ 
  _init(filas,columnas,RELLENO);
}

/**
int c =0;
while( c < columnas){
	m[f][c]= otra.m[f][c];
	++c;
}
**/

Matriz::Matriz(const Matriz & otra){
   _init(otra.filas,otra.columnas,RELLENO);
   for(int f=0; f< filas; ++f){
	   for(int c=0; c<columnas; ++c){
			m[f][c] = otra.m[f][c];
      }		
   }	  
}
/*
*@Función: se encarga de obtener los valores de filas y columnas de una matriz que entra como parámetro 
*@Param: recibe como parámetro otra matriz por referencia de tipo Matriz 
*/
void Matriz::asignar(const Matriz & otra){
	if(m){
		_liberar();
	}	
	Matriz victima(otra);
	this->filas = victima.filas;
	this->columnas = victima.columnas;
	this->m= victima.m;
	victima.m = 0;
		
}


Matriz::~Matriz(){ 
  _liberar();
}
/*
*@Función: verifica si la posición de la matriz en la fila y columna especificadas es válida
*@Param fia:  parámetro de tipo int que indica la fila actual
*@Param columna: parámetro de tipo int que indica la columna actual
*@Return: retorna 1 (true) si la posición es válida, si no retorna un 0(false)
*/
int Matriz::esPosicionValida(int fila,int columna){
   return fila >=0 && fila < filas && columna >=0 && columna < columnas;	
}
void Matriz::setValor(int fila,int columna,char valor){
   if(esPosicionValida(fila,columna)){
	   m[fila][columna]=valor;
   }	
}
char Matriz::getValor(int fila,int columna){
   char valor = '\0';
   if(esPosicionValida(fila,columna)){
	   valor = m[fila][columna];
   }
   return valor;   
}
/*
*@Función: imprime la matriz
*@Param: salida de datos estándar
*/
void Matriz::imprimir( ostream & salida){
   for(int f=0; f< filas; ++f){
	 for(int c=0; c<columnas; ++c){
	   salida << " "<<m[f][c];
	 }		
	 salida << endl;
   }	      
}

