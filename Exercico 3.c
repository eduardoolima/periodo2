#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	int cont = 1;
	float altura, maior_altura = 0;
	while(cont <= 10){
		printf("Digite a altura da %i",cont);
		printf("° Pessoa: ");
		scanf("%i",&altura);
		if (altura > maior_altura){
			maior_altura = altura;
		}
		cont++;
	}
	printf("Maior altura: %i",maior_altura);
	system("pause");
}
