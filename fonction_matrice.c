#include <stdio.h>
#include <stdlib.h>
#include "fonction_matrice.h"

void free_matrice(float** matrice,int taille){
	if(matrice == NULL) return;
	if(taille <1){
		printf("Mauvaise taille\n");
		return;
	}
	
	for(int a=0;a<taille;a++) free(matrice[a]);
	free(matrice);
}

float** creation_matrice(int taille){

	if(taille<1){
		printf("La taille doit être >= 1\n");
		return NULL;
	}
	
	float** matrice=NULL;
	matrice=malloc(taille*sizeof(float*));
	if(matrice == NULL){
		printf("Erreur allocation mémoire\n");
		return NULL;
	}
	
	for(int k=0; k<taille; k++){
		matrice[k]=calloc(taille,sizeof(float));
		if(matrice[k]==NULL){
			printf("Erreur allocation mémoire\n");
			for (int i = 0; i < k; i++) free(matrice[i]);
            		free(matrice);
			return NULL;
		}
	}
	
	return matrice;
}

float** remplissage(float** matrice, int taille){
	for(int a=0; a<taille; a++){
		for(int b=0; b<taille; b++){
			if(scanf("%f",&matrice[a][b])!=1){
				printf("La matrice ne doit contenir que des nombres réelles\n");
				for (int i = 0; i < a; i++) free(matrice[i]);
            			free(matrice);
            			return NULL;
			}
		}
	}
	return matrice;
}

void affichage_matrice(float** matrice,int taille){

	if(matrice==NULL || taille<1){
		printf("Impossible d'afficher cette matrice\n");
		return;
	}

	for(int a=0; a<taille; a++){
		printf("| ");
		for(int b=0; b<taille; b++){
			printf("%f ",matrice[a][b]);
		}
		printf("|\n");
	}
}

float** identite(int taille, float coefficient){
	if(taille<1){
		printf("La taille doit être >= 1\n");
		return NULL;
	}
	float** mat=creation_matrice(taille);
	for(int a=0;a<taille;a++){
		for(int b=0;b<taille;b++){
			if(a==b){
				mat[a][b]=coefficient;
			}
		}
	}
	return mat;
}

