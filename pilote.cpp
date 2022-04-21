#pragma once
#include <iostream>
using namespace std;
#include "pilote.h"
#include <vector>
#include <fstream>
Pilote::Pilote() : Personnel()
{

    cout << "donner le numero de pilote" << endl;
    cin >> numero_pilote;
}

Pilote::Pilote(int numero_pilote, int matricule, float salaire, float nbre_heures_travail, Date date_embauche, string nom, string prenom, string CIN, int num_tel, Date date_naiss, string adresse) : Personnel(matricule, salaire, nbre_heures_travail, date_embauche, nom, prenom, CIN, num_tel, date_naiss, adresse)
{
    this->numero_pilote = numero_pilote;
}

ostream &operator<<(ostream &out, Pilote &p)
{

    out << "le nom :" << endl;
    out << p.nom;
    out << "le prenom :" << endl;
    out << p.prenom;
    out << "le numero de la carte d identité :" << endl;
    out << p.CIN;
    out << "le numero de telephone :" << endl;
    out << p.num_tel;
    out << "la date de naissance  :" << endl;
    out << p.date_naiss;
    out << "adresse :" << endl;
    out << p.adresse;
    out << "la matricule est :" << endl;
    out << p.matricule;
    out << " le salaire est :" << endl;
    out << p.salaire;
    out << "le nombred heure de travail est  :" << endl;
    out << p.nbre_heures_travail;
    out << "la date d embauche est  :" << endl;
    out << p.date_embauche;
    out << "le numero de pilote" << endl;
    out << p.numero_pilote;
    out << "Le nombre d'heures de vol est :";
    out << p.nbre_heure_vol << endl;
    return out;
}
istream &operator>>(istream &in, Pilote &p)
{
    cout << "donner le nom " << endl;
    in >> p.nom;
    cout << "donner le prenom " << endl;
    in >> p.prenom;
    cout << "donner le numero de la carte d identité " << endl;
    in >> p.CIN;
    cout << "donner le numero de telephne" << endl;
    in >> p.num_tel;
    cout << "donner la date de naissance" << endl;
    in >> p.date_naiss;
    cout << "donner l 'adresse  " << endl;
    in >> p.adresse;
    cout << "donner la matricule " << endl;
    in >> p.matricule;
    cout << "donner salaire" << endl;
    in >> p.salaire;
    cout << "Donner le nombre d heures de travail" << endl;
    in >> p.nbre_heures_travail;
    cout << "Donner la date d embauche" << endl;
    in >> p.date_embauche;
    cout << "Donner le numero du pilote" << endl;
    in >> p.numero_pilote;

    return in;
}

int Pilote::rechercheCIN(string CIN)
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