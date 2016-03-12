/**
 * @file Anneau.tpp
 *
 * @author Valentin Hénique
 * @date 4 Mars 2016
 * @version 0.8
 * @copyright Tous Droits Réservés.
 * 
 * @todo Tester la documentation Doxygen
 * @todo Proofreading
 * 
 **/


template < typename T>
/**
 * @brief Constructeur d'Anneau.
 *
 * @details Constructeur de la classe Anneau. Fait appel au constructeur de la structure de données file (queue) employée par cette implémentation de l'Anneau.
 *
 **/
Anneau<T>::Anneau(){
	file = std::queue<T>();
}


/********************************************************************/
template < typename T>
/**
 * @brief Destructeur vide d'Anneau
 *
 * @details Destructeur laissé vide car aucune allocation n'est faite mais présent pour d'éventuelles révisions.
 *
 **/
Anneau<T>::~Anneau(){}


/********************************************************************/
template < typename T>
/**
 * @brief Méthode vérifiant si un Anneau est vide.
 *
 * @details Méthode vérifiant si un Anneau donné est vide ou non. Fait appel à la méthode empty() déja incluse dans la structure de donnée File (queue).
 *
 * @return Retourne true si l'Anneau est vide, retourne false sinon.
 **/

bool Anneau<T>::estVide(){
	return file.empty();
}


/********************************************************************/
template < typename T>
/**
 * @brief Procédure ajoutant un élément à l'Anneau.
 *
 * @details Procédure permettant d'ajouter un élément de type T dans l'Anneau à la suite de courant(). Fait usage de la méthode push() incluse dans dans la File (queue).
 *
 * @param[in] nouv L'élément de type T à ajouter
 **/
void Anneau<T>::ajoute(T nouv){
	file.push(nouv);
}


/********************************************************************/
template < typename T>
/**
 * @brief Procédure retirant un élément de l'Anneau
 *
 * @details Procédure supprimant l'élément à l'emplacement courant de l'Anneau. Emploie la procédure pop() incluse dans la structure de donnée File (queue).
 *
 * @warning La procédure supprime() ne retourne pas l'élément lors de sa suppression.
 **/
void Anneau<T>::supprime(){
	file.pop();
}


/********************************************************************/
template < typename T>
/**
 * @brief Retourne l'élément courant.
 *
 * @details Métode retournant l'élément courant de l'Anneau. Ici dans l'implémentation par File (queue) l'élément courant sera toujours celui qui sera le prochain à sortir de la File. Utilise la procédure front() incluse dans la File (queue).
 *
 * @return L'élément de type T courant de l'Anneau.
 **/
T Anneau<T>::courant(){
	return file.front();
}


/********************************************************************/
template < typename T>
/**
 * @brief Procédure avançant les éléments de l'Anneau
 *
 * @details Procédure faisant avancer les éléments de l'Anneau du point de vue de l'élément courant. Ici avec la File l'élément courant étant fixe c'est l'Anneau entier qui va être "tourné" en défilant et enfilant l'élément courant de la file.
 *
 **/
void Anneau<T>::avance(){
	T tmp = courant();
	supprime();
	ajoute(tmp);
}


/********************************************************************/
template < typename T>
/**
 * @brief Méthode reculant les éléments de l'Anneau
 *
 * @details Méthode faisant reculer les éléments de l'Anneau du point de vue de l'élément courant. Ici avec la File l'élément courant étant fixe c'est l'Anneau entier qui va être "tourné" en défilant et enfilant les éléments jusqu'à le nombre d'élément - 1 (Pour le code cela revient à utiliser la fonction avance()).
 *
 **/
void Anneau<T>::recule(){
	for(int i(0); i < file.size() -1; ++i){
		avance();
	}
}
