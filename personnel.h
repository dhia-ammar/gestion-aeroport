#pragma once
#include <iostream>
using namespace std;
#include "personne.cpp"
#include <vector>
class Personnel : public Personne
{
protected:
    int matricule;
    float salaire;
    float nbre_heures_travail;
    Date date_embauche = Date(1, 1, 1);
    static vector<Personnel *> tab_personnel;

public:
    Personnel();
    Personnel(int, float, float, Date, string, string, string, int, Date, string);
    void afficher();
    friend ostream &operator<<(ostream &, Personnel &);
    friend istream &operator>>(istream &, Personnel &);
};