#include "test.hpp"
#include <iostream>
#include "../File/Anneau.hpp"

template class Anneau<>;

void test(){

	std::cout << "\n****************************************************" << std::endl;
	std::cout << "*                  Début du Test :                 *" << std::endl;

std::cout << "****************************************************" << std::endl;
	
/**
 * @brief Création de l'anneau
 *
 * @details Utilisation du constructeur
 *
 **/
	std::cout << "\nTest de la creation d'un anneau\n--------------------------------" << std::endl;
	Anneau<> testA;
	std::cout << "  Fait !" << std::endl;

/**
 * @brief Test de la fonction estVide()
 *
 * @details Dans notre cas la fonction estVide() doit retourner "Il n'y a pas d'élément !" 
 *
 **/
	std::cout << "\nTest de la fonction estVide() :\n--------------------------------" << std::endl;
	if(testA.estVide()){
		std::cout << "  Il n'y a pas d'élément !" << std::endl;
	} else {
		std::cout << "  Il y a plusieurs éléments !" << std::endl;
	}

/**
 * @brief Test de la fonction ajoute() puis de la fonction courant()
 *
 * @details Dans notre cas la fonction ajoute() doit ajouter à l'anneau 'c' et la fonction courant() va vérifier l'ajout en affichant 'c' 
 *
 **/
	std::cout << "\nTest de la fonction ajoute()\n--------------------------------" << std::endl;
	testA.ajoute('c');
	std::cout << "  Fait !" << std::endl;

	std::cout << "\nTest de la fonction courant() et Vérification de ajoute() :\n--------------------------------" << std::endl;
	std::cout << "  'c' devrait s'afficher : " << testA.courant() << std::endl;

/**
 * @brief On effectue quelque ajout
 *
 **/
	testA.ajoute('h');
	testA.ajoute('a');
	testA.ajoute('t');
	testA.ajoute('z');

/**
 * @brief Test de la fonction avance() et vérification avec courant()
 *
 * @details Dans notre cas la fonction avance() doit faire tourner l'anneau en avant pour aller sur 'h' et la fonction courant() va vérifier en affichant le caractère 'h' attendu 
 *
 **/
	std::cout << "\nTest de la fonction avance() :\n--------------------------------" << std::endl;
	testA.avance();

	std::cout << "  'h' devrait s'afficher : " << testA.courant() << std::endl;

/**
 * @brief Test de la fonction supprime() et vérification avec courant()
 *
 * @details Dans notre cas la fonction supprime() doit suprimer caractère 'h' et la fonction courant() va vérifier la suppression en affichant le caractère 'a' attendu 
 *
 **/
	std::cout << "\nTest de la fonction supprime :\n--------------------------------" << std::endl;
	testA.supprime();

	std::cout << "  'a' devrait s'afficher : " << testA.courant() << std::endl;

/**
 * @brief Test de la fonction recule() et vérification avec courant()
 *
 * @details Dans notre cas la fonction recule() doit faire tourner l'anneau en arrière pour aller sur 'c' et la fonction courant() va vérifier en affichant le caractère 'c' attendu 
 *
 **/
	std::cout << "\nTest de la fonction recule() :\n--------------------------------" << std::endl;
	testA.recule();

	std::cout << "  'c' devrait s'afficher : " << testA.courant() << std::endl;

/**
 * @brief Deuxème test de la fonction estVide()
 *
 * @details Dans notre cas la fonction estVide() doit retourner "Il y a plusieur éléments !"
 *
 **/
	std::cout << "\nDeuxième test de la fonction estVide :\n--------------------------------" << std::endl;
	if(testA.estVide()){
		std::cout << "  Il n'y a pas d'élément !" << std::endl;
	} else {
		std::cout << "  Il y a plusieur éléments !" << std::endl;
	}


	std::cout << "\n****************************************************" << std::endl;
	
	std::cout << "* Fin de la fonction Test() : Déroulement normal ! *" << std::endl;

	std::cout << "****************************************************" << std::endl;
}
