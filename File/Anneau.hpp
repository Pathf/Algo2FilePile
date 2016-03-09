#include <queue>

template < typename T = char >
class Anneau{
private:
	std::queue<T> file;

public :
	Anneau();
	~Anneau();

	bool estVide();
	void ajoute(T nouv);
	void supprime();
	T courant(); // l'élément courant est la tête soit l'élement qui peut sortire
	void avance();
	void recule();
};

#include "Anneau.tpp"
