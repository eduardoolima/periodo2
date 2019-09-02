#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
	char sn;
	float c, l, area, area_total=0;
	printf("Calculando a area da casa\n");
	do
	{
		
		switch(sn)
		{
			case 's':
				printf("Digite o comprimento: ");
				scanf("%f",&c);
				printf("Digite a largura: ");
				scanf("%f",&l);
				area=c*l;
				area_total=area_total+area;
			break;	
			case 'n':
				printf("Area total da casa: %.2f",area_total);
				printf(" metros ²\n");
			break;	
			defalut:
				printf("inválido.");
			break;	
		}
		printf("deseja continuar?\n");
		printf("Digite s para sim e n para não.\n");
		scanf("%c",&sn);
	}
	while(sn!='n');	
	system("pause");
}
