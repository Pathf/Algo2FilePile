//Constructeur :
template < typename T>
AnneauCar< T >::AnneauCar(){
	pos = NULL;
	nbM = 0;
}

/********************************************************************/
//Destructeur :
template < typename T>
AnneauCar< T >::~AnneauCar(){
	if(nbM > 0){
		for(int i(0); i > nbM; ++i){
			supprime();
		}
		nbM = 0;
	}
}

/********************************************************************/
//Return un booleen pour savoir si l'anneau est vide :
template < typename T>
bool AnneauCar< T >::estVide(){
	return nbM == 0;
}

/********************************************************************/
//Ajoute un maillon à l'anneau après le maillon courant :
template < typename T>
void AnneauCar< T >::ajoute(T c){
	Maillon * nouv = new Maillon();
	nouv->elt = c;
	
	if(estVide()){
		nouv->suiv = nouv;
		nouv->pred = nouv;		
	} else {		
		nouv->suiv =  pos->suiv;
		nouv->pred = pos;
		
		nouv->suiv->pred = nouv;
		pos->suiv = nouv;
	}
	pos = nouv;
	nbM++;
	cout << nbM << endl;
}

/********************************************************************/
//Supprime le maillon courant :
template < typename T>
void AnneauCar< T >::supprime(){
	if(nbM > 0){
		if(estVide()){
			delete pos;
		} else {
			pos->suiv->pred = pos->pred;
			pos->pred->suiv = pos->suiv;
			Maillon * tmp = pos->suiv;		
			delete pos;
			pos = tmp;
		}
		nbM--;
	} else {
		cout << "Erreur il n'y a pas de symbole dans l'anneau" << endl;
	}	
}

/********************************************************************/
//Return le caractère compris dans le maillon courant :
template < typename T>
T AnneauCar< T >::courant(){
	return pos->elt;
}

/********************************************************************/
//Change le maillon courant pour le suivant :
template < typename T>
void AnneauCar<T>::avance(){
	pos = pos->suiv;
}

/********************************************************************/
//Change le maillon courant pour le précédant :
template < typename T>
void AnneauCar<T>::recule(){
	pos = pos->pred;
}

/********************************************************************/
//Concatène les caractère du maillon courant jusqu'au dernier maillon :
template < typename T>
string AnneauCar<T>::compacte(){
	string comp = "";	

	if(nbM > 0){
		for(int i(0); i < nbM; ++i){
			comp += courant();
			avance();
		}
	} else {
		cout << "ERREUR : pas de maillon dans l'annneau" << endl;
	}

	return comp;
}
