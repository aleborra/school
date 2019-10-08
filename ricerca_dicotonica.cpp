#include<stdio.h>
#define MAX_VET 100


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

/*
void cerca(int *vet,int n, int el)			//ricerca dicotonica si sua con un solo valore e vettore ordinato
{
	int i, j, med, trovato;
	i=0;									//i inizio
	j=n-1;									//j fine
	trovato= 1;
	
	while(!trovato&&i<=j)
	{
		med=(i+j)/2;
		if(vet[med==el])
			
			trovato=1;
		
		else
			
			if(vet[med]>el)					//se > uso j se < uso i
			{
				j=med-1;
			}
			else
			{
				i=med+1;
			}
	}

	if(trovato)
	{
		printf("posizione %d\n", med);
	}
	else
	{
		printf("elemento non trovato");
	}
}
*/

void cerca(int *vet,int n, int el)		
{
	int i, j, med, trovato;
	i=0;									
	j=n-1;									
	trovato= 1;
	
	while(!trovato&&i<=j)
	{
		med=(i+j)/2;
		if(vet[med==el])
			
			trovato=1;
		
		else
			
			if(vet[med]>el)				
			{
				j=med-1;
			}
			else
			{
				i=med+1;
			}
	}

	if(trovato)
	{
		return med;
	}
	else
	{
		return -1;
	}
}

int main(){
	
	int len, numeri[MAX_VET], ord;
	
	printf("quanti numeri vuoi inserire \n");
	scanf("%d",&len);

	carica_vet(numeri, len);
	stampa_vet(numeri, len);
	ris=cerca(numeri, len);
	
	if(ris!=-1)
	{
		printf("posizione %d\n", ris);
	}
	else
	{
		printf("elemento non trovato");
	}
	
	
}
