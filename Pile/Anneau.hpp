/**
 * @file Anneau.hpp
 *
 * @author Corentin CHÉDOTAL
 * @date 4 Mars 2016
 * @version 0.1
 * @copyright Tous Droits Réservés.
 *
 * @todo Vérifier la documentation générée par Doxygen
 **/

#include <stack>

template < typename T = char >

/**
 * @class Anneau
 *
 * @brief Implémentation de l'Anneau par pile
 *
 * @details Structure de données stockant celles-ci dans un Anneau. C'est à dire dans une structure sans tête ni queue puisque tous les éléments se suivent. L'accès aux données se fait par le biais de courant() qui accède à un élément de l'Anneau. Les méthodes avance() et recule() font tourner l'Anneau pour accéder aux diférentes données. Ici elle est implémentée par pile (stack).
 *
 **/
class Anneau{
private:
	std::stack<T> pile;
	std::stack<T> pileTemp;

public:
	Anneau();
	~Anneau();

	bool estVide();
	void ajoute(T nouv);
	void supprime();
	T courant();
	void avance();
	void recule();
};

#include "Anneau.tpp"
