#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

#include "Anneau.hpp"
template class Anneau<>;
template class Anneau<int>;

int main(){
	string entree;
	cout<<"Entrez votre mot:";
	cin >> entree;
	cout<<endl<<"resultats obtenus :"<<endl;
	Anneau<>* cercle = new Anneau<>();
	for(int i=0; i<entree.size(); ++i){
		cercle->ajoute(entree[entree.size()-i-1]);
	}
	for(int i=0; i<entree.size(); ++i){
		cout<<cercle->compacte()<<endl;
		cercle->avance();
	}
	delete cercle;

	cout<<"Entrez votre entier:";
	cin >> entree;
	int nombre = atoi(entree.c_str());
	cout<<endl<<"resultats obtenus :"<<endl;
	Anneau<int>* cercle2 = new Anneau<int>();
	for(int i=0; i<entree.size(); ++i){
		cercle2->ajoute(nombre%10);
		nombre /= 10;
	}
	for(int i=0; i<entree.size(); ++i){
		cout<<cercle2->compacte()<<endl;
		cercle2->avance();
	}
	delete cercle2;

	cout<<"création Anneau de double"<<endl;
	double v[5] = {1.2, 2.3, 3.5, 42, 9.3};
	Anneau<double>* cercle3 = new Anneau<double>();
	for(int i=0; i<5; ++i){
		cercle3->ajoute(v[i]);
	}
	for(int i=0; i<5; ++i){
		cout<<cercle3->compacte()<<endl;
		cercle3->avance();
	}
	delete cercle3;

	
	return 0;
}