#include<stdio.h>
#define MAX_VET 100

void scambia_int(int *ptra, int *ptrb)	// var 1 --> var 2
{
	int dep;
	dep=*ptra;
	*ptra=*ptrb;
	*ptrb=dep;

}


void carica_vet(int *vet, int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("inserisci un numero \n");
		scanf("%d", &vet[i]);
	}
	
}


void stampa_vet(int *vet, int n)
{
	int i;
	
	for(i=0;i<n;i++)
	{
		printf("%d ", vet[i]);	
	}
	printf("\n");
}


void bubble_sort(int *vet, int n)	//dal più piccolo al più grande
{
	int i, j, scambio;
	i=n-1;
	scambio=1;
	
	while(scambio&&i>0)
	{
		scambio=0;
		for(j=0;j<i;j++)
		{		
			if(vet[j]>vet[j+1])
				{
					scambia_int(&vet[j], &vet[j+1]);
					scambio=1;
				}
		}
		i--;
	}

}


int main (){

	int len, numeri[MAX_VET], ord;
	printf("quanti numeri vuoi inserire \n");
	scanf("%d",&len);

	carica_vet(numeri, len);

	bubble_sort(numeri, len);
		
	stampa_vet(numeri, len);	/*stampa_vet_inversa(numeri, len);*/
	
}
