#include<stdio.h>
#include<string.h>
#define MAX_VET 100
#define MAX_STR 100


char str[MAX_VET][MAX_STR];
char el[MAX_STR];


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
	
	printf("\n Inserisci una frase:\n\n");
	
	for(i=0;i<n;i++) {
		scanf("%s", str[i]);
	}	
}


int cerca(char str[MAX_VET][MAX_STR],int n, char *el)    //ricerca dicotomica
{
	int i,j,med,trovato;
	
	i=0;
	j=n-1;     
	trovato=0;
	
	while(!trovato&&i<=j)
	{
		med=(i+j)/2;
		if(strcmp(str[med],el)==0)
			trovato=1;
		else
			if(strcmp(str[med],el)>0)    //elemento sta a sinistra
				j=med-1;	
			else
				i=med+1;
	}
	if(trovato)
		return med;
	else
		return -1;
}


void bubble_sort(char str[MAX_VET][MAX_STR],int n) 
{	
	int i,j,scambio;
	
	i=n-1;
	scambio=1;
	
while(i>0)        //optimized
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
		
		if (scambio == 0) 
        break; 
	}
}


void stampa_str(char str[MAX_VET][MAX_STR],int n)
{
	int i;
	
	for(i=0;i<n;i++) {
		
		printf("\n%s",str[i]);
	}
}


void cancella(char str[MAX_VET][MAX_STR],int pos, int *n)
{
	int i;
	
	for(i=pos;i<*n-1;i++)
		strcpy(str[i],str[i+1]);
		
	*n--;
}


void inserisci(char str[MAX_VET][MAX_STR],char el[MAX_STR], int *n)
{
	if(*n>=MAX_VET)
	{
		printf(" Il vettore ha raggiunto la dimensione massima");
		return;
	}
	
	int i,trovato;
	trovato=0;
	i=0;
	
	while(i<*n&&!trovato)
		{
			if
			
		}
	
}

int main () {
	int n,ris;
	
	printf(" Quante parole vuoi inserire?\n");
	scanf("%d",&n);
		
	carica_str(str,n);
	bubble_sort(str,n);	
	stampa_str(str,n);
	
	printf("\n\n Quale parola vuoi cercare:");
	printf("\n\n");
	scanf("%s",el);
	
	ris=(cerca(str,n,el)+1);
		
	if(ris!=0)
	{
		printf("POSIZIONE %d\n",ris);
		cancella(str,ris,&n);
	}
	else
		printf("Elemento non trovato\n");
	
	stampa_str(str,n);
	

	printf("\n Quale parola vuoi inserire:");
	printf("\n\n");
	scanf("%s",el);
	inserisci(str,el,&n);
	stampa_str(str,n);
	
}
