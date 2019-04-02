#include "Matriz.h"
#include<iostream>
using namespace std;
// basada en la vista en clase.

void Matriz::_init(int filas,int columnas, char relleno){
   this->filas = 0;
   this->columnas = 0;
   this->m = 0; // apunta a nulo
   if(filas>0 && columnas>0){
      cout << "Inicializar "<< filas << " x "<< columnas << endl;	   
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
void Matriz::_liberar(){ 
   if(m){
	  cout << "Liberar "<< filas << " x "<< columnas << endl; 
	  for(int f=filas-1; f >=0; --f){
		  delete [] m[f];
	  }   
	  delete [] m; 
   }
}
Matriz::Matriz(){ 
  cout << "Constructor por omision"<< endl;
  _init(0,0,RELLENO);
}
Matriz::Matriz(int filas, int columnas){ 
  cout << "Constructor "<< filas << " "<< columnas << endl;
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
  cout << "Destructor matriz "<< filas << " x "<< columnas << endl;
  _liberar();
}
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
void Matriz::imprimir( ostream & salida){
   salida << filas << " " << columnas << endl;
   for(int f=0; f< filas; ++f){
	 for(int c=0; c<columnas; ++c){
	   salida << " "<<m[f][c];
	 }		
	 salida << endl;
   }	      
}
