#include <iostream>
#pragma once
using namespace std;
#include <string>
#include "Date.cpp"
#include <vector>
class Personne
{
protected:
    string nom;
    string prenom;
    string CIN;
    int num_tel;
    Date date_naiss = Date(1, 1, 1);
    string adresse;

public:
    static vector<Personne> tab;
    Personne();
    Personne(string, string, string, int, Date, string);
    static int rechercheCIN(string);
    /*virtual void afficher() = 0;
    virtual void modifier() = 0;
    virtual void ajouter() = 0;
    virtual void supprimer() = 0;*/
    bool controleCIN(string);
};
vector<Personne> Personne::tab;