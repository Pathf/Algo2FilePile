//TODO redéfinir l'opérateur << pour pouvoir faire compacte d'un Anneau d'Anneau
template < typename T >
Anneau<T>::Anneau(){
	tete = NULL; 
	nbelt = 0;
}

template < typename T >
Anneau<T>::~Anneau(){
	if(!estVide()){
		for(int i =0; i<nbelt; i++){
			supprime();
		}
	}
}

template < typename T >
bool Anneau<T>::estVide(){
	return nbelt==0;
}

template < typename T >
void Anneau<T>::ajoute(T c){
	Maillon* nouveau = new Maillon;
	nouveau->elt = c;	
	if(estVide()){
		nouveau->suiv = nouveau;
		nouveau->prec = nouveau;
		tete = nouveau;
	}
	else if(nbelt == 1){
		nouveau->suiv= tete;
		nouveau->prec= tete;
		tete->suiv = nouveau;
		tete->prec = nouveau;
		tete = nouveau;
	}else{
		nouveau->suiv= tete;
		nouveau->prec = tete->prec;
		tete->prec = nouveau;
		(nouveau->prec)->suiv = nouveau;
		tete = nouveau;
	}
	++nbelt;
}

template < typename T >
void Anneau<T>::supprime(){
	Maillon* save = tete;
	tete->suiv->prec = tete->prec;
	tete->prec->suiv = tete->suiv;
	tete = tete->suiv;
	delete save;
	--nbelt;
}

template < typename T >
T Anneau<T>::courant(){
	return tete->elt;
}

template < typename T >
void Anneau<T>::avance(){
	tete = tete->suiv;
}

template < typename T >
void Anneau<T>::recule(){
	tete = tete->prec;
}

template < typename T >
string Anneau<T>::compacte(){
	stringstream result;
	for(int i=0; i<nbelt; ++i){
		result << tete->elt;
		avance();
	}
	return result.str();
}