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
#include <cstdlib>		// srand() et rand()
#include <time.h>		// pour le temps
#include <fstream>		// Pour l'ecriture dans un fichier
#include "Test/test.hpp"	// Permet de verifier si les File Pile fonctionnent 
#include "File/Anneau.hpp"
//#include "Pile/Anneau.hpp"


int nbrValeurStockee = 1000;
std::string const nomfichier("resultatF.txt");
/**
 * @var chrono
 * @brief chronomètre du programme
**/

clock_t chrono;

/**
 * @def START
 * @brief démarre le chronomètre
**/
#define START chrono=clock();

/**
 * @def STOP
 * @brief arrête le chronomètre
**/
#define STOP chrono=clock()-chrono;

/**
 * @def TEMPS
 * @brief donne le temps du chronomètre (après arrêt)
**/
#define TEMPS double(chrono)/(CLOCKS_PER_SEC*0.001)

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

// Supprime les doublons :
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

	return Asans;
}

/**
 * @brief fonction test de void dedoublonne(Anneau<> A);
 *
 * @details Test la fonction dedoublonne() pour voir si son fonctionnement est correcte
 *
 **/
void testDedoublonne(){
	std::cout << "\n****************************************************" << std::endl;
	std::cout << "*                  Début du Test :                 *" << std::endl;

	std::cout << "****************************************************" << std::endl;

// Creation de l'anneau pour voir si les paramètres sont correcte
	Anneau<> A;
	A.ajoute('a');
	A.ajoute('b');
	A.ajoute('c');
	A.ajoute('a');
	A.ajoute('c');
	A.ajoute('a');
	A.ajoute('a');

// Test de la fonction dedoublonne()
	Anneau<> B = dedoublonne(A);

// Verification
	std::cout << "\nPour l'anneau de depart A :" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "  Anneau A (";
	while(!A.estVide()){
		std::cout << A.courant() << ",";
		A.supprime();
	}
	std::cout << "FIN)\n" << std::endl;

	std::cout << "Pour l'anneau sans doublons :" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "  Pour B on devrait avoir B(a,b,c,d,FIN) : Anneau B (";
	while(!B.estVide()){
		std::cout << B.courant() << ",";
		B.supprime();
	}
	std::cout << "FIN)" << std::endl;

	std::cout << "\n****************************************************" << std::endl;
	
	std::cout << "*      Fin de la fonction TestDedoublonne() !      *" << std::endl;

	std::cout << "****************************************************\n" << std::endl;
}

int main (){
	
	srand((unsigned int)time(0));
	// Permet de tester pour pile ou file en fonction de l'implementation
	//test();	
	//testDedoublonne();

	std::ofstream flux(nomfichier.c_str(),std::ios::app);

	int valea;
	double tmp = 0.0;
	Anneau<> A;

	for(int i = 0; i < 10; i++){
		for(int j = 0; j < nbrValeurStockee; j++){
			valea = rand() % 10 + 1;		
			A.ajoute(valea);
		}
		START;
		dedoublonne(A);
		STOP;
		std::cout << "Chrono " << i+1 << " : (nombre d elements = " << nbrValeurStockee << ")\n" << TEMPS - tmp << " millisecondes\n" << std::endl;
		flux << TEMPS - tmp << " " << nbrValeurStockee << std::endl;
	tmp = TEMPS;
	}

	
	
	return 0;
}

