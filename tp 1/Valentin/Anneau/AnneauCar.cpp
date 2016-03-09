//Constructeur :
AnneauCar::AnneauCar(){
	pos = NULL;
	nbM = 0;
}

/********************************************************************/
//Destructeur :
AnneauCar::~AnneauCar(){
	if(nbM > 0){
		for(int i(0); i > nbM; ++i){
			supprime();
		}
		nbM = 0;
	}
}

/********************************************************************/
//Return un booleen pour savoir si l'anneau est vide :
bool AnneauCar::estVide(){
	return nbM == 0;
}

/********************************************************************/
//Ajoute un maillon à l'anneau après le maillon courant :
void AnneauCar::ajoute(char c){
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
void AnneauCar::supprime(){
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
char AnneauCar::courant(){
	return pos->elt;
}

/********************************************************************/
//Change le maillon courant pour le suivant :
void AnneauCar::avance(){
	pos = pos->suiv;
}

/********************************************************************/
//Change le maillon courant pour le précédant :
void AnneauCar::recule(){
	pos = pos->pred;
}

/********************************************************************/
//Concatène les caractère du maillon courant jusqu'au dernier maillon :
string AnneauCar::compacte(){
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
