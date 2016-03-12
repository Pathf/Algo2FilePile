/**
 * @file mainF.cpp
 *
 * @author Valentin Hénique
 * @date 10 Mars 2016
 * @version 0.8
 * @copyright Tous Droits Réservés.
 * 
 * @todo Tester la documentation Doxygen
 * @todo Proofreading

 * 
 **/

#include <iostream>		// cout, endl
#include "Test/test.hpp"	// Permet de verifier si les 
#include "File/Anneau.hpp"

template class Anneau<>;

Anneau<> dedoublonne(Anneau<> A){
	Anneau<> Asans;
	int cpt = 0;

//Permet de compter le nombre d'élément dans l'Anneau:
	while(!A.estVide()){
		Asans.ajoute(A.courant());
		A.supprime();
		cpt++;
	}
	
	for(int i = 0; i < cpt; i++){
		A.ajoute(Asans.courant());
		Asans.avance();
	}

//Fait le tri :
	T elt;
	int cptB = 0;
	for(int i = 0; ; i++){
		elt = Asans.courant();
		while(cpt - 1 > cptB){
			Asans.avance();
			if(elt == Asans.courant()){
				Asans.supprime();
				cpt--;
			} else {
				cptB++;
			}
		}
		cptB = 0;
	}
	
	return Asans;
}

int main (){
	
	// Permet de tester pour pile ou file en fonction de l'implementation
	//test();	

	return 0;
}

