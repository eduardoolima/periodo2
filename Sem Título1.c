#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main()
{

	setlocale(LC_ALL, "Portuguese");
	char sn;
	float c, l, area, area_total=0;
	printf("Calculando a area da casa\n");
	printf("deseja continuar?\n");
	printf("Digite s para sim e n para nao.\n");
	scanf("%c",&sn);	
	while(sn!='n')
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
				printf(" metros ?\n");
			break;	
			default:
				printf("inválido.");
			break;	
		}
		
	}	
	system("pause");
}
