#include<stdio.h>
#define MAX_VET 100


void scambia_int(int *ptra,int *ptrb) 
{
	
	int dep;
	dep=*ptra;
	*ptra=*ptrb;
	*ptrb=dep;
}


void carica_vet(int *vet, int n)
{
	int i;
	
	for(i=0;i<n;i++) {
		printf("Inserisci un numero:\n");
		scanf("%d",&vet[i]);
	}	
}


void stampa_vet(int *vet,int n)
{
	int i;
	
	for(i=0;i<n;i++) {
		
		printf("\n%d",vet[i]);
	}
}


void bubble_sort (int *vet,int n) {
	
	int i,j,scambio;
	i=(n-1);
	scambio=1;
	
	while(i>0)        //optimized
	{
		scambio=0;
		for(j=0;j<i;j++) 
		{
			if(vet[j]>vet[j+1])
			{
			 	scambia_int(&vet[j],&vet[j+1]);
				scambio=1;	
			}
		}
		i--;
		
		if (scambio == 0) 
        	break; 
	}
}


int cerca(int *vet,int n,int el)     //ricerca dicotomica
{
	int i,j,med,trovato;
	
	i=0;
	j=n-1;     
	trovato=0;
	
	while(!trovato&&i<=j)
	{
		med=(i+j)/2;
		if(vet[med]==el)
			trovato=1;
		else
			if(vet[med]>el)    //elemento sta a sinistra
				j=med-1;	
			else
				i=med+1;
	}
	if(trovato)
		return med;
	else
		return -1;
}

	
int main () {
	int vet[MAX_VET],n,el,ris;
	printf("Inserire dimensione vettore:\n");
	scanf("%d",&n);
	
	carica_vet(vet,n);
	bubble_sort(vet,n);
	stampa_vet(vet,n);
	
	printf("Quale elemento vuoi cercare:\n");
	canf("%d",&el);
	ris=cerca(vet,n,el);
		
	if(ris!=-1)
		printf("Elemento trovato in posizione %d\n",ris);
	else
		printf("Elemento non trovato\n");

}
