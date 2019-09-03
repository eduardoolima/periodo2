#include<stdlib.h>
#include<stdio.h>

int main()
{
	float notas[5], media, aux=0;
	int i;
	
	for(i=0;i<5;i++)
	{
		printf("Digite uma nota: ");
		scanf("%f",&notas[i]);
	}
	for(i=0;i<5;i++)
	{
		aux=aux+notas[i];
	}
	media=aux/5;
	for(i=0;i<5;i++)
	{
		if(notas[i]>media)
		{
			printf("%.2f\n",notas[i]);
			
		}
	}	
	system("pause");
	
}
