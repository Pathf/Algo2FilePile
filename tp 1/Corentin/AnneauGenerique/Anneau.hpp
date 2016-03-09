template < typename T = char >
class Anneau{
	private:
		struct Maillon{
			T elt;
			Maillon* prec;
			Maillon* suiv;
		};
		Maillon* tete;
		int nbelt;
	public:
		Anneau();
		~Anneau();
		bool estVide();
		void ajoute(T c);
		void supprime();
		T courant();
		void avance();
		void recule();
		string compacte();
};

#include "Anneau.tpp"
