#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(){
	int numero, potencia, potencia2 = 0, resultado;
	printf("Digite o numero: ");
	scanf("%i",&numero);
	printf("Digite a potencia: ");
	scanf("%i",&potencia);
	do{
		resultado = pow(numero,potencia2);
		printf("%i\n",resultado);
		potencia2++;
	}while(potencia2 <= potencia);
	system("pause");
	
}
