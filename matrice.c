#include <stdio.h>
#include <stdlib.h>
#include "fonction_matrice.h"
#include "operation_matrice.h"

int main(){

	int taille;
	float** A=NULL;
	float** B=NULL;
	float** C=NULL;
	
	printf("Quelle est la taille de votre matrice ?\n");
	if(scanf("%d",&taille)!=1 || taille<1){
		printf("Ceci n'est pas un nombre entier strictement positif\n");
		exit(1);
	}
	
	
	A=creation_matrice(taille);
	B=identite(taille,3);
	
	printf("Remplissage de A:\n");
	A=remplissage(A,taille);

	/*printf("Remplissage de B:\n");
	B=remplissage(B,taille);*/
	
	C=produit_matrice(A,B,taille);

	printf("A:\n");affichage_matrice(A, taille);
	printf("\nB:\n");affichage_matrice(B, taille);
	printf("\nC:\n");affichage_matrice(C, taille);
	
	
	
	free_matrice(A,taille);
	free_matrice(B,taille);
	free_matrice(C,taille);
	
	return 0;
}
