#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	
	int numero, divisor, i, j=0,aux=0;
	int vetor[50];
	
	printf("Digite um numero: ");
	scanf("%d",&numero);
	printf("\n");
	for(i=1; i<=numero; i++)
	{
		if(numero % i == 0)
		{
			vetor[j]=i;
			j++;
		}
	}
	printf("divisores de %d",numero);
	printf(": ");
	for(i=0; i<j; i++)
	{
		printf("%d ",vetor[i]);
    }
    printf("\n");
    for(i=0; i<j-1; i++)
    {
    	aux=aux+vetor[i];
	}
	if(aux==numero)
	{
		printf("\n");
		printf("%d",aux);
		printf(" é perfeito, pois ");
		for(i=0; i<j-1; i++)
		{
			printf("%d ",vetor[i]);
		}	
		printf("somados = %d",aux);
	}
	else
	{
		printf("%d",numero);
		printf(" não é perfeito");
	}
		printf("\n");
	system("pause");
}
