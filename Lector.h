#ifndef _LECTOR
#define _LECTOR
#include "Palabra.h"
class Lector {
private:
	char * palabra;
	int length;

public:
	Palabra();
	Palabra(char *);
	~Palabra();
	int equals(Palabra&); // retorna 0 si son diferentes
	char * getHilera();
	void setHilera(char *);
	int getLength();
	char charAt(int);
};
#endif