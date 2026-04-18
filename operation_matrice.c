#include <stdio.h>
#include <stdlib.h>
#include "fonction_matrice.h"
#include "operation_matrice.h"

float* colonne(float** matrice, int numero, int taille){
	
	if(matrice==NULL) return NULL;
	
	float* col=malloc(taille*sizeof(float));
	if(col==NULL){
		printf("Erreur d'allocation mémoire\n");
		exit(1);
	}	
	
	for(int lig=0;lig<taille;lig++) col[lig]=matrice[lig][numero];
	return col;
}

float produit_lig_col(float* ligne, float* colonne, int taille){
	float somme=0;
	for(int a=0; a<taille; a++){
		somme+= ligne[a]*colonne[a];
	}
	return somme;
}



float** produit_matrice(float** A, float** B, int taille){

	float** result=creation_matrice(taille);
	float* ligne=malloc(taille*sizeof(float));
	float* col=NULL;
	if(ligne == NULL){
		printf("Erreur allocation mémoire\n");
		return NULL;
	}
	for(int lig=0;lig<taille;lig++){
	
		ligne=A[lig];
		for(int l=0;l<taille;l++){
			col=colonne(B,l,taille);
			result[lig][l]=produit_lig_col(ligne,col,taille);
			free(col);
		}

	}
	
	return result;
}
