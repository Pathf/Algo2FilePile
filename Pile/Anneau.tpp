/**
 * @file Anneau.tpp
 *
 * @author Corentin CHÉDOTAL
 * @date 4 Mars 2016
 * @version 0.1
 * @copyright Tous Droits Réservés.
 * 
 **/

template < typename T >
/**
 * @fn Anneau<T>::Anneau()
 * @brief Constructeur
 *
 * @details Constructeur de la classe Anneau. Fait appel au constructeur de la structure de données pile (stack) employée par cette implémentation de l'Anneau.
 *
 **/
Anneau<T>::Anneau() {
	pile = std::stack<T>();
}

template < typename T >
/*!
 * \brief [brief description]
 *
 * [detailed description]
 *
 * \param[in] [name of input parameter] [its description]
 * \param[out] [name of output parameter] [its description]
 * \return [information about return value]
 * \sa [see also section]
 * \note [any note about the function you might have]
 * \warning [any warning if necessary]
 */
Anneau<T>::~Anneau() {
	//Contenu ?
}

template < typename T >
bool Anneau<T>::estVide() {
	return(pile.empty())
}

template < typename T >
void Anneau<T>::ajoute(T nouv) {
	pile.push(nouv);
}

template < typename T >
void Anneau<T>::supprime() {
	pile.pop();
}

template < typename T >
T Anneau<T>::courant() {
	pile.top();
}

template < typename T >
void Anneau<T>::avance() {
	T sauvegarde;
	stack<T> tmp;

	sauvegarde = pile.courant;
	pile.supprime();
	
	for (int i = 0; i < pile.size; i++) {
		tmp.ajoute(pile.courant());
		pile.supprime();
	}
	
	pile.ajoute(sauvegarde);
	
	for (int i = 0; i < tmp.size; i++) {
		pile.ajoute(tmp.courant());
		tmp.supprime();
	}
}

template < typename T >
void Anneau<T>::recule() {
	T sauvegarde;
	stack<T> tmp;

	for (int i = 0; i < pile.size() - 1; i++) {
		tmp.ajoute(pile.courant());
		pile.supprime();
	}
	
	sauvegarde = pile.courant;
	pile.supprime();

	for (int i = 0; i < tmp.size(); i++) {
		pile.ajoute(tmp.courant());
		tmp.supprime();
	}

	pile.ajoute(sauvegarde);
}
