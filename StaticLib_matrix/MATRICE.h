#pragma once
#include "pch.h"
#include "MATRICE.h"
#include <iostream>
#include "assert.h"
using namespace std;
namespace algebre
{
	template <class M>
	class Matrice
	{
	private:
		int nbre_lgn;
		int nbre_col;
		M** tab;

	public:
		Matrice(int lg, int col);
		void remplissage(M val);
		void remplir();
		Matrice<M>& operator+(const Matrice<M>& M);
		Matrice<M>& operator-(const Matrice<M>& M);
		Matrice<M>& operator*(int d);
		Matrice<M>& operator*(Matrice<M>& M);
		void print() const;
		~Matrice();
	};
	template<class M>
	Matrice<M>::Matrice(int lg, int col)
	{
		this->nbre_lgn = lg;
		this->nbre_col = col;
		tab = new M* [lg];
		for (int j = 0; j < col; j++)
		{
			tab[j] = new int[col];
		}

		for (int i = 0; i < lg; i++)
		{
			for (int j = 0; j < col; j++)
			{
				this->tab[i][j] = 0;
			}
		}
	}
	template<class M>
	void Matrice<M>::remplissage(M val)
	{
		for (int i = 0; i < this->nbre_lgn; i++)
		{
			for (int j = 0; j < this->nbre_col; j++)
			{
			   this->tab[i][j] = val;
			}
		}
	}
	template<class M>
	void Matrice<M>::remplir()
	{
		for (int i = 0; i < this->nbre_lgn; i++)
		{
			cout << "ligne " << i + 1 << endl;
			for (int j = 0; j < this->nbre_col; j++)
			{
				cout << "Matrice[" << i << "][" << j << "] = ";
				cin >> this->tab[i][j];
			}
		}
		cout << endl;
	}
	template<class M>
	Matrice<M>& Matrice<M>::operator+(const Matrice<M>& M2)
	{
		Matrice<M>* M1 = new Matrice(this->nbre_lgn, this->nbre_col);
		assert(M2.nbre_lgn == this->nbre_lgn && M2.nbre_col == this->nbre_col);
		for (int i = 0; i < this->nbre_lgn; i++)
		{
			for (int j = 0; j < this->nbre_col; j++)
			{
				//cout << M.tab[i][j] << endl;
				M1->tab[i][j] = this->tab[i][j] + M2.tab[i][j];
				//cout << M1->tab[i][j] << endl;
			}
		}
		return *M1;
	}
	template<class M>
	Matrice<M>& Matrice<M>::operator-(const Matrice<M>& M2)
	{
		// TODO: insérer une instruction return ici
		Matrice<M>* M1 = new Matrice(this->nbre_lgn, this->nbre_col);
		assert(M2.nbre_lgn == this->nbre_lgn && M2.nbre_col == this->nbre_col);
		for (int i = 0; i < this->nbre_lgn; i++)
		{
			for (int j = 0; j < this->nbre_col; j++)
			{
				//cout << M.tab[i][j] << endl;
				M1->tab[i][j] = this->tab[i][j] - M2.tab[i][j];
				//cout << M1->tab[i][j] << endl;
			}
		}
		return *M1;
	}
	template<class M>
	Matrice<M>& Matrice<M>::operator*(int d)
	{
		Matrice<M>* M1 = new Matrice(this->nbre_lgn, this->nbre_col);

		for (int i = 0; i < this->nbre_lgn; i++)
		{
			for (int j = 0; j < this->nbre_col; j++)
			{
				(M1->tab[i][j]) = this->tab[i][j] * d;
			}
		}
		return *M1;
	}
	template<class M>
	Matrice<M>& Matrice<M>::operator*(Matrice<M>& M2)
	{
		Matrice<M>* M1 = new Matrice(this->nbre_lgn, this->nbre_col);
		int res;
		assert(M2.nbre_lgn == this->nbre_lgn && M2.nbre_col == this->nbre_col);
		for (int i = 0; i < this->nbre_lgn; i++)
			for (int j = 0; j < this->nbre_col; j++)
			{
				res = 0;
				for (int k = 0; k < this->nbre_col; k++)
					res += this->tab[i][k] * M2.tab[k][j];
				M1->tab[i][j] = res;
			}
		return *M1;
	}
	template<class M>
	void Matrice<M>::print() const
	{
		cout << "la matrice est : " << endl;
		for (int i = 0; i < this->nbre_lgn; i++)
		{
			for (int j = 0; j < this->nbre_col; j++)
			{
				cout << " " << this->tab[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
	template<class M>
	Matrice<M>::~Matrice()
	{
		for (int j = 0; j < this->nbre_col; j++)
		{
			delete(tab[j]);
			this->tab[j] = 0;
		}
		delete(tab);
		tab = 0;
	}
}
