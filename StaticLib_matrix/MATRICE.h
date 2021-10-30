#pragma once
namespace algebre
{
	class Matrice
	{
	private:
		int nbre_lgn;
		int nbre_col;
		int** tab;

	public:
		Matrice(int lg,int col);
		void remplissage(int val);
		void remplir();
		Matrice& operator+(const Matrice& M);
		Matrice& operator-(const Matrice& M);
		Matrice& operator*(int d);
		Matrice& operator*(Matrice& M);
		void print() const;
		~Matrice();
	};
}
