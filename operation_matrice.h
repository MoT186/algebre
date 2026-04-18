#ifndef OPERATION_MATRICE_H
#define	OPERATION_MATRICE_H
	
float* colonne(float** matrice, int numero, int taille);
float produit_lig_col(float* ligne, float* colonne, int taille);
float** produit_matrice(float** A, float** B, int taille);
	
#endif
