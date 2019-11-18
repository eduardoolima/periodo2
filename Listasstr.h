#define TAM 30
#include "string.h"
typedef struct
{
	char nome[30];
	int nr;
 } Elem;
typedef struct Lista
{
	Elem M[TAM];
	int Fim;
};

void Linit(Lista *L)
{
	L->Fim=0;
}
void Lins(Lista *L, Elem X)
{
	if (L->Fim<TAM)
	{
		int I=L->Fim;
		while ((I>0) && (strcmp(X.nome,L->M[I-1].nome)<0))
		{
			strcpy(L->M[I].nome,L->M[I-1].nome);
			L->M[I].nr=L->M[I-1].nr;
			I--;
		}
		strcpy(L->M[I].nome,X.nome);
		L->M[I].nr=X.nr;
		L->Fim++;
	}
}








