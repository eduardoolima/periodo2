#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<locale.h>

int main()
{
	setlocale(LC_ALL, "Portuguese");
		
	int vetor[50];
	int i, j=0, n=1000;
	
	while(n<2000)
	{
		if(n%11==5)
		{
			vetor[j]=n;
			j++;
		}
		n++;
	}
	for(i=0;i<=j;i++)
	{
		printf("%d ",vetor[i]);
	}
	system("pause");
}
