#include <iostream> // utile pour les entrées/sorties
#include <string>

using namespace std;

#include "AnneauCar.hpp" // pour utiliser le type Point

template class AnneauCar<>;
template class AnneauCar<int>;

// fonction principale
int main()
{
	AnneauCar<> prem;
	
	if(prem.estVide()){
		cout << "Il n'y a pas d'élément !" << endl;
	} else {
		cout << "Il y a plusieur éléments !" << endl;
	}

	prem.ajoute('c');
	
	prem.ajoute('h');
	prem.ajoute('a');
	prem.ajoute('t');
	prem.ajoute('z');

	prem.supprime();

	prem.avance();
	cout << prem.compacte() << endl;	

	prem.recule();
	cout << prem.compacte() << endl;

	return 0;
}
