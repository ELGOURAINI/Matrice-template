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
		Matrice(const Matrice&) = delete;
		void remplissage(int val);
		Matrice& operator=(const Matrice& M)=delete;
		Matrice& operator+(const Matrice& M);
		Matrice& operator-(const Matrice& M);
		Matrice& operator*(int d);
		void print() const;
		~Matrice();
	};
}
