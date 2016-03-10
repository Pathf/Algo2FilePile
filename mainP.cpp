/**
 * @file mainP.cpp
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
//#include "File/Anneau.hpp" 	// Pour les files
#include "Pile/Anneau.hpp"	//Pour les Piles

template class Anneau<>;

void test(){

	std::cout << "\n*************************************\nDébut du Test :" << std::endl;
	
	// Creation de l'anneau : (utilisation du constructeur))
	Anneau<> testA;
	
	// Test de la fonction estVide()
	if(testA.estVide()){
		std::cout << "Il n'y a pas d'élément !" << std::endl;
	} else {
		std::cout << "Il y a plusieur éléments !" << std::endl;
	}

	//Test de la fonction ajoute() puis de la fonction courant()
	testA.ajoute('c');
	std::cout << "'c' devrait s'afficher : " << testA.courant() << std::endl;
	
	// Quelque ajout
	testA.ajoute('h');
	testA.ajoute('a');
	testA.ajoute('t');
	testA.ajoute('z');
	
	// Test de la fonction avance() et vérification avec courant()
	testA.avance();

	std::cout << "'h' devrait s'afficher : " << testA.courant() << std::endl;

	// Test de la fonction supprime() et vérification avec courant()
	testA.supprime();

	std::cout << "'a' devrait s'afficher : " << testA.courant() << std::endl;

	// Test de la fonction recule() et vérification avec courant()
	testA.recule();
	std::cout << "'c' devrait s'afficher : " << testA.courant() << std::endl;
}

int main (){
	
	// A décomenter pour faire le test sur File
	test();	

	return 0;
}

