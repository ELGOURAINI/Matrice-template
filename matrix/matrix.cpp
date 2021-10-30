#include <iostream>
#include "MATRICE.h"
using namespace algebre;
using namespace std;

int main()
{
    //Declaration des matrices
    Matrice* M= new Matrice(2,2);
    Matrice* M1 = new Matrice(2, 2);

    //Remplissages de matrices
    M->remplissage(1);
    M1->remplissage(2);
    //M->rempir();

    //affichage des matrices
    M->print();
    M1->print();

    //Somme de deux matrices
    Matrice M2=*M+*M1;
    M2.print();

    //Soustraction de deux matrices
    Matrice M3 = M2 - *M1;
    M3.print();

    //multiplication d'une matrice avect un entier
    Matrice M4 = M2*2;
    M4.print();

    //multiplication de deux matrices
    Matrice M5 = (*M) * (*M);
    M5.print();

}
