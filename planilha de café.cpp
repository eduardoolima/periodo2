#include <iostream>
#include "Listasstr.h"
#include <locale.h>

typedef struct
{
	char status;
	char variedade[30];
	int quantidade;
} registro;
int total= 0;

void cadastrar(FILE *);
void consultar(FILE *);
int tamarq(FILE *);
void relatorio(FILE *);
void relatorio_ordenado(FILE *);
void excluir(FILE *);

int main(void)
{
	setlocale(LC_ALL,"Portuguese");
	FILE *arq;
	arq=fopen("dados.dat","rb+");
	if (!arq)
	{   
		arq=fopen("dados.dat","wb+");
	}
	
	int OP;
	do
	{
		system("CLS");
		printf("=====================================\n");
		printf("1. Cadastrar variedade e quantidade\n");
		printf("2. Consultar variedade e quantidade\n");
		printf("3. Relatorio\n");
		printf("4. Relatorio Ordenado\n");
		printf("5. Excluir registro\n");
		printf("6. Sair\n");	
		printf("=====================================\n");
		printf("Sua opcao:");
		scanf("%d",&OP);
		fflush(stdin);
		switch (OP)
		{
			case 1:
				cadastrar(arq);
				break;
			case 2:
				consultar(arq);
				break;
			case 3:
				relatorio(arq);
				break;
			case 4:
				relatorio_ordenado(arq);
				break;
			case 5:
				excluir(arq);
		}
	} while (OP!=6);
	fclose(arq);
}

void cadastrar(FILE *arq)
{
	printf("Registro No:%d\n",tamarq(arq)+1);
	registro reg;
	printf("Variedade de café   : ");
	gets(reg.variedade);
	printf("Quantidade de sacas : ");
	scanf(" %d",reg.quantidade);
	total=total+reg.quantidade;
	reg.status=' ';
	fseek(arq,0,SEEK_END);
	fwrite(&reg,sizeof(registro),1,arq);
	
	system("pause");
}

void consultar(FILE *arq)
{
	int nr;
	printf("Numero do registro:");
	scanf("%d",&nr);
	fflush(stdin);
	registro reg;
	fseek(arq,(nr-1)*sizeof(registro),SEEK_SET);
	fread(&reg,sizeof(registro),1,arq);
	printf("Variedade de café   :%s\n",reg.variedade);
	printf("Quantidade de sacas :%s\n",reg.quantidade);
	if (reg.status=='*')
		printf("\nREGISTRO EXCLUIDO!!!\n");
	
	system("pause");
}

void excluir(FILE *arq)
{
	int nr;
	printf("Numero do registro:");
	scanf("%d",&nr);
	fflush(stdin);
	registro reg;
	fseek(arq,(nr-1)*sizeof(registro),SEEK_SET);
	fread(&reg,sizeof(registro),1,arq);
	printf("Variedade de café   :%s\n",reg.variedade);
	printf("Quantidade de sacas :%s\n",reg.quantidade);
	char conf;
	printf("Confirma exclusao <S/N>:");
	scanf("%c",&conf);
	fflush(stdin);
	if (toupper(conf)=='S')
	{
		reg.status='*';
		fseek(arq,(nr-1)*sizeof(registro),SEEK_SET);
		fwrite(&reg,sizeof(registro),1,arq);
	}
	
	
	system("pause");
}


void relatorio(FILE *arq)
{
	FILE *arqtxt=fopen("Relatorio.txt","w");
	int nr;
	fprintf(arqtxt,"variedade      | N° de sacas | total\n");
	fprintf(arqtxt,"=================================================\n");
	registro reg;
	
	for (nr=0;nr<tamarq(arq);nr++)
	{
		fseek(arq,nr*sizeof(registro),SEEK_SET);
		fread(&reg,sizeof(registro),1,arq);
		if (reg.status!='*')
		   fprintf(arqtxt,"%-15s| %-7d| %-7 d\n",reg.variedade,reg.quantidade,total);
	}
	fprintf(arqtxt,"=================================================\n");
	fclose(arqtxt);
	printf("Relatorio gerado com sucesso!!!\n");
	system("pause");
	
}

void relatorio_ordenado(FILE *arq)
{
	Lista L;
	Linit(&L);
	registro reg;
	int nr;
	Elem X;
	for (nr=0;nr<tamarq(arq);nr++)
	{
		fseek(arq,nr*sizeof(registro),SEEK_SET);
		fread(&reg,sizeof(registro),1,arq);
		strcpy(X.nome,reg.variedade);
		X.nr=nr;
		Lins(&L,X);
	}
	
	FILE *arqtxt=fopen("Relatorio Ordenado.txt","w");

	fprintf(arqtxt,"variedade      | N° de sacas | total\n");
	fprintf(arqtxt,"=================================================\n");

	for (int i=0;i<L.Fim;i++)
	{
		fseek(arq,L.M[i].nr*sizeof(registro),SEEK_SET);
		fread(&reg,sizeof(registro),1,arq);
		fprintf(arqtxt,"%-15s| %-7d| %-7 d\n",reg.variedade,reg.quantidade,total);
	}
	fprintf(arqtxt,"=================================================\n");
	fclose(arqtxt);
	printf("Relatorio gerado com sucesso!!!\n");
	system("pause");
	
}

int tamarq(FILE *arq)
{
	fseek(arq,0,SEEK_END);
	return ftell(arq)/sizeof(registro);
}

