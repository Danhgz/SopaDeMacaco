#include "Palabra.h"
#include <iostream>
using namespace std;

int main(){
	char pene[] = "caca";
	Palabra x;
	x.setHilera(pene);
	cout << x.getHilera()[2] << endl;
	return 0;
}