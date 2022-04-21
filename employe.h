#pragma once
#include <iostream>
using namespace std;
#include "personnel.cpp"
#include <vector>
#include <fstream>

class Employe : public Personnel
{
    string departement;
    string poste;

public:
    static vector<Employe> tab;
    Employe();
    Employe(bool a) : Personnel(a){};
    Employe(string, string, int, float, float, Date, string, string, string, int, Date, string);
    static int rechercheCIN(string);
    void ajouterClient();
    void ajouterEmploye();
    void ajouterHotesse();
    void ajouterPilote();
    void modifierClient();
    void modifierEmploye();
    void modifierHotesse();
    void modifierPilote();
    void supprimerClient();
    void supprimerEmploye();
    void supprimerHotesse();
    void supprimerPilote();
    template <class T>
    void sauvegarder(T);
    template <class T>
    void charger();
    template <class T>
    void enregistrer_vector(vector<T>);
    friend ostream &operator<<(ostream &, Employe &);
    friend istream &operator>>(istream &, Employe &);
    friend ostream &operator<<(ostream &, Employe *);
    friend istream &operator>>(istream &, Employe *);
    void afficher_tab_Employe();
};
vector<Employe> Employe::tab;