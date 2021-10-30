#include <iostream>
#include "pch.h"
#include "MATRICE.h"
using namespace algebre;
using namespace std;
algebre::Matrice::Matrice(int lg, int col)
{
    this->nbre_lgn = lg;
    this->nbre_col = col;
    for (int j = 0; j < col; j++)
    {
        this->tab[j] = new int[col];
    }

    for (int i = 0; i < lg; i++)
    {
        for (int j = 0; j < col; j++)
        {
            this->tab[i][j] = 0;
        }
    }
}

void algebre::Matrice::remplissage(int val)
{
    for (int i = 0; i < this->nbre_lgn; i++)
    {
        for (int j = 0; j < this->nbre_col; j++)
        {
            this->tab[i][j] = val;
        }
    }
}

Matrice& algebre::Matrice::operator+(const Matrice& M)
{
    Matrice* M1 = new Matrice(this->nbre_lgn, this->nbre_col);

    for (int i = 0; i < this->nbre_lgn; i++)
    {
        for (int j = 0; j < this->nbre_col; j++)
        {
            M1->tab[i][j]=this->tab[i][j] + M.tab[i][j];
        }
    }
    return *M1;
}

Matrice& algebre::Matrice::operator-(const Matrice& M)
{
    Matrice* M1 = new Matrice(this->nbre_lgn, this->nbre_col);

    for (int i = 0; i < this->nbre_lgn; i++)
    {
        for (int j = 0; j < this->nbre_col; j++)
        {
            M1->tab[i][j] = this->tab[i][j] - M.tab[i][j];
        }
    }
}

Matrice& algebre::Matrice::operator*(int d)
{
    Matrice* M1 = new Matrice(this->nbre_lgn, this->nbre_col);

    for (int i = 0; i < this->nbre_lgn; i++)
    {
        for (int j = 0; j < this->nbre_col; j++)
        {
            (M1->tab[i][j]) = this->tab[i][j] * d;
        }
    }
}

void algebre::Matrice::print() const
{
    for (int i = 0; i < this->nbre_lgn; i++)
    {
        for (int j = 0; j < this->nbre_col; j++)
        {
            cout << this->tab[i][j] ;
        }
        cout << endl;
    }
}

algebre::Matrice::~Matrice()
{
    delete(this->tab);
}
