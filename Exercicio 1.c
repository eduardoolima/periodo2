#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int numero, numerosoma;
	
	numero=1;
	numerosoma=0;
	printf("programa");
	while(numero <= 200){
		if (numero % 2 == 0){
		numerosoma = numerosoma + numero;
		numero++;
		}
	}
	printf("%i",numerosoma);
	system("pasuse");
}
