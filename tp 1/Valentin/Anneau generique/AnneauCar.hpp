template <typename T = char > 
class AnneauCar{
private:
	struct Maillon{
		Maillon * suiv;		//ptr vers le maillon suivant
		Maillon * pred;		//ptr vers le maillon precedent
		T elt;
	};	
	int nbM;		//nombre de maillon
	Maillon * pos;		//pointeur vers la position actuelle

public:
//Constructeur :
	AnneauCar();
//Destructeur :
	~AnneauCar();
//Return un booleen pour savoir si l'anneau est vide :	
	bool estVide();
//Ajoute un maillon à l'anneau après le maillon courant :
	void ajoute(T c);	
//Supprime le maillon courant :
	void supprime();	
//Return le caractère compris dans le maillon courant :
	T courant();		
//Change le maillon courant pour le suivant :
	void avance();		 
//Change le maillon courant pour le précédant :
	void recule();		
//Concatène les caractère du maillon courant jusqu'au dernier maillon	:
	string compacte();	
};

#include "AnneauCar.tpp"
