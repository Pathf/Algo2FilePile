//Constructeur :
template < typename T>
Anneau<T>::Anneau(){
	file = std::queue<T>();
}

/********************************************************************/
//Destructeur :
template < typename T>
Anneau<T>::~Anneau(){}

/********************************************************************/
//Return un booleen pour savoir si l'anneau est vide :
template < typename T>
bool Anneau<T>::estVide(){
	return file.empty();
}

/********************************************************************/
//Ajoute un maillon à l'anneau après le maillon courant :
template < typename T>
void Anneau<T>::ajoute(T nouv){
	file.push(nouv);
}

/********************************************************************/
//Supprime le maillon courant :
template < typename T>
void Anneau<T>::supprime(){
	file.pop();
}

/********************************************************************/
//Return le caractère compris dans le maillon courant :
template < typename T>
T Anneau<T>::courant(){
	return file.front();
}

/********************************************************************/
//Change le maillon courant pour le suivant :
template < typename T>
void Anneau<T>::avance(){
	T tmp = courant();
	supprime();
	ajoute(tmp);
}

/********************************************************************/
//Change le maillon courant pour le précédant :
template < typename T>
void Anneau<T>::recule(){
	for(int i(0); i < file.size() -1; ++i){
		avance();
	}
}