/**
 * @file Anneau.tpp
 *
 * @author Corentin CHÉDOTAL
 * @date 10 Mars 2016
 * @version 0.2
 * @copyright Tous Droits Réservés.
 * 
 * @todo Tester le fichier
 * @todo Tester la documentation Doxygen
 * @todo Proofreading
 * 
 **/

template < typename T >
/**
 * @brief Constructeur d'Anneau.
 *
 * @details Constructeur de la classe Anneau. Fait appel au constructeur de la structure de données pile (stack) employée par cette implémentation de l'Anneau.
 *
 **/
Anneau<T>::Anneau() {
	pile = std::stack<T>();
}

template < typename T >
/**
 * @brief Destructeur vide d'Anneau
 *
 * @details Destructeur laissé vide car aucune allocation n'est faite mais présent pour d'éventuelles révisions.
 *
 **/
Anneau<T>::~Anneau() {
	//Contenu ?
}

template < typename T >
/**
 * @brief Méthode vérifiant si un Anneau est vide.
 *
 * @details Méthode vérifiant si un Anneau donné est vide ou non. Fait appel à la méthode empty() déja incluse dans la structure de donnée Pile (stack).
 *
 * @return Retourne true si l'Anneau est vide, retourne false sinon.
 **/
bool Anneau<T>::estVide() {
	return(pile.empty())
}

template < typename T >
/**
 * @brief Procédure ajoutant un élément à l'Anneau.
 *
 * @details Procédure permettant d'ajouter un élément de type T dans l'Anneau à la suite de courant(). Celui-ci devient d'ailleurs le nouveau élément courant. Fait usage de la méthode push() incluse dans dans la Pile (stack).
 *
 * @param[in] nouv L'élément de type T à ajouter
 **/
void Anneau<T>::ajoute(T nouv) {
	pile.push(nouv);
}

template < typename T >
/**
 * @brief Procédure retirant un élément de l'Anneau
 *
 * @details Procédure supprimant l'élément à l'emplacement courant de l'Anneau. Emploie la procédure pop() incluse dans la structure de donnée Pile (stack).
 *
 * @warning La procédure supprime() ne retourne pas l'élément lors de sa suppression.
 **/
void Anneau<T>::supprime() {
	pile.pop();
}

template < typename T >
/**
 * @brief Retourne l'élément courant.
 *
 * @details Métode retournant l'élément courant de l'Anneau. Ici dans l'implémentation par Pile (stack) et de par les limitations de celle-ci l'élément courant sera toujours celui en haut de la Pile, l'Anneau entier "tournant" puisque le courant reste "fixe". Utilise la procédure top() incluse dans la Pile (stack).
 *
 * @return L'élément de type T courant de l'Anneau.
 **/
T Anneau<T>::courant() {
	return pile.top();
}

template < typename T >
/**
 * @brief Procédure avançant les éléments de l'Anneau
 *
 * @details Procédure faisant avancer les éléments de l'Anneau du point de vue de l'élément courant. Ici avec la Pile l'élément courant étant fixe c'est l'Anneau entier qui va être "tourné" en dépilant et réempilant en mettant de coté au moment opportun les éléments.
 *
 **/
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
/**
 * @brief Méthode reculant les éléments de l'Anneau
 *
 * @details Méthode faisant reculer les éléments de l'Anneau du point de vue de l'élément courant. Ici avec la Pile l'élément courant étant fixe c'est l'Anneau entier qui va être "tourné" en dépilant et réempilant dans un ordre spécifique en mettant de coté au moment opportun les éléments.
 *
 **/
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
