#pragma once
#include <iostream>
using namespace std;
#include "hotesse.h"
#include <vector>
#include <fstream>

Hotesse::Hotesse(string langue, string niveau, int matricule, float salaire, float nbre_heures_travail, Date date_embauche, string nom, string prenom, string CIN, int num_tel, Date date_naiss, string adresse) : Personnel(matricule, salaire, nbre_heures_travail, date_embauche, nom, prenom, CIN, num_tel, date_naiss, adresse)
{
    this->langue = langue;
    this->niveau = niveau;
}
Hotesse::Hotesse() : Personnel()
{
    cout << "donner la langue:" << endl;
    cin >> langue;
    cout << "donner le niveau:" << endl;
    cin >> niveau;
}
ostream &operator<<(ostream &out, Hotesse &h)
{
    out << "le nom :";
    out << h.nom << endl;
    out << "le prenom :";
    out << h.prenom << endl;
    out << "le numero de la carte d identité :";
    out << h.CIN << endl;
    out << "le numero de telephone :";
    out << h.num_tel << endl;
    out << "la date de naissance  :";
    out << h.date_naiss << endl;
    out << "adresse :";
    out << h.adresse << endl;
    out << "la matricule est :";
    out << h.matricule << endl;
    out << " le salaire est :";
    out << h.salaire << endl;
    out << "le nombred heure de travail est  :";
    out << h.nbre_heures_travail << endl;
    out << "la date d embauche est  :";
    out << h.date_embauche << endl;
    out << "la langue:";
    out << h.langue << endl;
    out << "le niveau :";
    out << h.niveau << endl;

    return out;
}
istream &operator>>(istream &in, Hotesse &h)
{
    cout << "donner le nom " << endl;
    in >> h.nom;
    cout << "donner le prenom " << endl;
    in >> h.prenom;
    cout << "donner le numero de la carte d identité " << endl;
    in >> h.CIN;
    cout << "donner le numero de telephne" << endl;
    in >> h.num_tel;
    cout << "donner la date de naissance" << endl;
    in >> h.date_naiss;
    cout << "donner l 'adresse  " << endl;
    in >> h.adresse;
    cout << "donner la matricule " << endl;
    in >> h.matricule;
    cout << "donner salaire" << endl;
    in >> h.salaire;
    cout << "Donner le nombre d heures de travail" << endl;
    in >> h.nbre_heures_travail;
    cout << "Donner la date d embauche" << endl;
    in >> h.date_embauche;
    cout << "donner la langue" << endl;
    in >> h.langue;
    cout << "donner le niveau " << endl;
    in >> h.niveau;

    return in;
}

int Hotesse::rechercheCIN(string CIN)
{
    for (int i = 0; i < tab.size(); i++)
    {
        if (tab[i].CIN == CIN)
        {
            return i;
        }
    }
    return -1;
}