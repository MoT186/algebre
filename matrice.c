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
	B=creation_matrice(taille);
	
	printf("Remplissage de A:\n");
	A=remplissage(A,taille);

	printf("Remplissage de B:\n");
	B=remplissage(B,taille);
	
	C=produit_matrice(A,B,taille);

	printf("A:\n");affichage_matrice(A, taille);
	printf("\nB:\n");affichage_matrice(B, taille);
	printf("\nC:\n");affichage_matrice(C, taille);
	
	
	
	free_matrice(A,taille);
	free_matrice(B,taille);
	free_matrice(C,taille);
	
	return 0;
}
