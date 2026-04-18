#ifndef FONCTION_MATRICE_H
#define	FONCTION_MATRICE_H

	void free_matrice(float** matrice,int taille);
	float** creation_matrice(int taille);
	float** remplissage(float** matrice, int taille);
	void affichage_matrice(float** matrice,int taille);
	float** identite(int taille, float coefficient);

#endif
