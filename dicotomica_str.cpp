#include<stdio.h>
#include<string.h>
#define MAX_VET 100
#define MAX_STR 100


char str[MAX_VET][MAX_STR];
char el[MAX_VET][MAX_STR];


void scambia_str(char *str1,char *str2) 
{
	
	char dep[MAX_STR];
	
	strcpy(dep,str1);
	strcpy(str1,str2);
	strcpy(str2,dep);
}


void carica_str(char str[MAX_VET][MAX_STR],int n)
{
	int i;
	
	for(i=0;i<n;i++) {
		printf("Inserisci una parola:\n");
		scanf("%s", str[i]);
	}	
}


void stampa_str(char str[MAX_VET][MAX_STR],int n)
{
	int i;
	
	for(i=0;i<n;i++) {
		
		printf("\n%s",str[i]);
	}
}


void bubble_sort (char str[MAX_VET][MAX_STR],int n) {
	
	int i,j,scambio;
	
	i=n-1;
	scambio=1;
	
	while(scambio==1&&i>0)        //va anche solo (scambio&&i>0)
	{
		scambio=0;
		for(j=0;j<i;j++) 
		{
			if(strcmp(str[j],str[j+1])>0)
			{
				scambia_str(str[j],str[j+1]);
				scambio=1;	
			}
		}
		i--;
	}
}


int cerca(char str[MAX_VET][MAX_STR],int n,char el[MAX_VET][MAX_STR])    //ricerca dicotomica
{
	int i,j,med,trovato;
	
	i=0;
	j=n-1;     
	trovato=0;
	
	while(!trovato&&i<=j)
	{
		med=(i+j)/2;
		if(strcmp(str[med],el[1])==0)
			trovato=1;
		else
			if(strcmp(str[med],el[1])>0)    //elemento sta a sinistra
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
	int n,ris;
	printf("Quante parole vuoi inserire?\n");
	scanf("%d",&n);
		
	carica_str(str,n);
	bubble_sort(str,n);
	stampa_str(str,n);
		
	printf("\n Quale lettera vuoi cercare:\n");
	scanf("%s",el[1]);
	ris=cerca(str,n,el);
		
	if(ris!=-1)
		printf("Elemento trovato in posizione %d\n",ris);
	else
		printf("Elemento non trovato\n");
	
	}

