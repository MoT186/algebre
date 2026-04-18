#include <stdio.h>
#include <stdlib.h>


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
	printf("Remplissage:\n");
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
		printf("|");
		for(int b=0; b<taille; b++){
			printf("%f ",matrice[a][b]);
		}
		printf("|\n");
	}
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
	float* colonne=malloc(taille*sizeof(float));
	if(ligne == NULL || colonne == NULL){
		printf("Erreur allocation mémoire\n");
		return NULL;
	}
	for(int a=0;a<taille;a++){
		ligne=A[a];
		for(int k=0;k<taille;k++){
			colonne[k]=B[k][a];
		}
		result[a][b]
	}
	return result;
}

int main(){

	int taille;
	float** matrice=NULL;
	
	printf("Quelle est la taille de votre matrice ?\n");
	if(scanf("%d",&taille)!=1 || taille<1){
		printf("Ceci n'est pas un nombre entier strictement positif\n");
		exit(1);
	}
	
	
	matrice=creation_matrice(taille);
	affichage_matrice(matrice, taille);
	matrice=remplissage(matrice,taille);
	affichage_matrice(matrice, taille);
	free_matrice(matrice,taille);
	
	return 0;
}
