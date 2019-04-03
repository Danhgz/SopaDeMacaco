#include<iostream>
#include<cstring>
#include"Palabra.h"
#include "Solucionador.h"

using namespace std;

int main(int argc, char * * argv) 
{
	if(3==argc || 4==argc)
	{ 		
		int err = 0;
		string arg1 = argv[1];
		string arg2 = argv[2];
		if ((strlen(argv[1]) - arg1.rfind(".txt")) != 4 || (strlen(argv[2]) - arg2.rfind(".txt")) != 4){
			err++;
		}
		if (4 == argc){
			string arg3 = argv[3];
			if ((strlen(argv[3])-arg3.rfind(".txt")) != 4) {
				err++;
			}
		}	
		if (!err) {
			//El codiguito va aki c:
			Solucionador sergei;
			sergei.leerPalabras(argv[1]);
			//sergei.leerSopa(argv[2]);
			//sergei.solucionar(argv[3]);
		}
	}
	return 0;
}