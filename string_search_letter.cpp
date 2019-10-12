#include<stdio.h>
#include<string.h>
#define MAX_VET 100
#define MAX_STR 100


char str[MAX_VET][MAX_STR];
char el[MAX_VET][MAX_STR];


void carica_str(char str[MAX_VET][MAX_STR],int n)
{
	int i;
	
	printf("\n Inserisci le parole di seguito\n\n");
	
	for(i=0;i<n;i++) {
		scanf("%s", str[i]);
	}	
}


int cerca(char str[MAX_VET][MAX_STR],int n, char *el)    //ricerca dicotomica
{
	int i,trovato;
	trovato=0;
	
	for(i=0;i<n;i++)
	{
		if(strstr(str[i],el)==0)
			trovato++;
	}
	
	return trovato;
}

	
int main () {
	int n,trovato;
	char el[MAX_STR];
	
	printf(" Quante parole vuoi inserire?\n");
	scanf("%d",&n);
		
	carica_str(str,n);
		
	printf("\n Quale parola vuoi cercare:");
	printf("\n\n");
	scanf("%s",el);
	
	trovato=(cerca(str,n,el)/n);

	
	if(trovato==0)
		printf("Presente");
	else
		printf("Elemento non trovato\n");
	
}
