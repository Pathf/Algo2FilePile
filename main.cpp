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

template < typename T>

Anneau<T> dedoublonne(Anneau<T> A){
	Anneau<T> Asans;
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
	int cptB;

	for(int i = 0; i < cpt; i++){
		cptB = 0;
		elt = Asans.courant();
		Asans.avance();
		while(cpt - 1 > cptB){
			if(elt == Asans.courant()){
				Asans.supprime();
				cpt--;
			} else {
				Asans.avance();
				cptB++;
			}
		}
		Asans.avance();
		Asans.avance();
		cpt--;
	}

	// Juste pour garder sons ordre de départ
	Asans.avance();	

	return Asans;
}

// fonction test de void dedoublonne(Anneau<> A);
void testDedoublonne(){
	Anneau<> A;
	A.ajoute('a');
	A.ajoute('b');
	A.ajoute('c');
	A.ajoute('a');
	A.ajoute('c');
	A.ajoute('d');
	A.ajoute('a');

	Anneau<> B = dedoublonne(A);

	std::cout << "Anneau A (";
	while(!A.estVide()){
		std::cout << A.courant() << ",";
		A.supprime();
	}
	std::cout << "FIN)" << std::endl;

	std::cout << "Anneau B (";
	while(!B.estVide()){
		std::cout << B.courant() << ",";
		B.supprime();
	}
	std::cout << "FIN)" << std::endl;
}

int main (){
	
	// Permet de tester pour pile ou file en fonction de l'implementation
	//test();	
	testDedoublonne();

	return 0;
}

