#pragma once
#include <iostream>
using namespace std;
#include "personnel.cpp"
#include <vector>
#include <fstream>
#include "client.h"

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
    void ajouterVol();
    void modifierClient();
    void modifierEmploye();
    void modifierHotesse();
    void modifierPilote();
    void supprimerClient();
    void supprimerEmploye();
    void supprimerHotesse();
    void supprimerPilote();
    template <class T>
    static void sauvegarder(T entite)
    {
        string classe = typeid(entite).name();
        string nom_fichier = classe + ".txt";
        fstream f(nom_fichier, ios::out | ios::app);
        f << &entite;
        charger<T>();
    }
    template <class T>
    static void sauvegarder_autre(T entite)
    {
        string classe = typeid(entite).name();
        string nom_fichier = classe + ".txt";
        fstream f(nom_fichier, ios::out | ios::app);
        f << &entite;

        charger_autres<T>();
    }
    template <class T>
    static void charger()
    {
        T::tab.clear();
        string classe = typeid(T).name();
        string nom_fichier = classe + ".txt";
        fstream f(nom_fichier, ios::in);
        f.seekg(0);
        while (1)
        {
            T entite = T(false);
            if (f.eof())
                break;
            f >> &entite;
            T::tab.push_back(entite);

            Personne p = static_cast<Personne>(entite);
            Personne::tab.push_back(p);
        }
        T::tab.pop_back();
        Personne::tab.pop_back();
    }
    template <class T>
    static void charger_autres()
    {
        T::tab.clear();
        string classe = typeid(T).name();
        string nom_fichier = classe + ".txt";
        fstream f(nom_fichier, ios::in);
        f.seekg(0);
        while (1)
        {

            T entite = T(false);
            if (f.eof())
                break;
            f >> &entite;
            T::tab.push_back(entite);
        }
        T::tab.pop_back();
    }
    template <class T>
    static void enregistrer_vector(vector<T> vect)
    {
        string classe = typeid(T).name();
        string nom_fichier = classe + ".txt";
        fstream f(nom_fichier, ios::out | ios::trunc);
        for (int i = 0; i < vect.size(); i++)
        {
            sauvegarder<T>(vect[i]);
        }
    }
    template <class T>
    static void enregistrer_vector_autre(vector<T> vect)
    {

        string classe = typeid(T).name();
        string nom_fichier = classe + ".txt";
        fstream f(nom_fichier, ios::out | ios::trunc);
        for (int i = 0; i < vect.size(); i++)
        {
            sauvegarder_autre<T>(vect[i]);
        }
    }
    template <class T>
    static void afficher_tous()
    {
        for (int i = 0; i < T::tab.size(); i++)
        {
            cout << T::tab[i] << endl;
        }
    }
    friend ostream &operator<<(ostream &, Employe &);
    friend istream &operator>>(istream &, Employe &);
    friend ostream &operator<<(ostream &, Employe *);
    friend istream &operator>>(istream &, Employe *);
    void afficher_tab_Employe();
};
vector<Employe> Employe::tab;
