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
    nbre_heure_vol = 0;
}

Pilote::Pilote(int numero_pilote, int matricule, float salaire, float nbre_heures_travail, Date date_embauche, string nom, string prenom, string CIN, int num_tel, Date date_naiss, string adresse) : Personnel(matricule, salaire, nbre_heures_travail, date_embauche, nom, prenom, CIN, num_tel, date_naiss, adresse)
{
    this->numero_pilote = numero_pilote;
    nbre_heure_vol = 0;
}

ostream &operator<<(ostream &out, Pilote &p)
{

    out << "le nom :";
    out << p.nom << endl;
    out << "le prenom :";
    out << p.prenom << endl;
    out << "le numero de la carte d identite :";
    out << p.CIN << endl;
    out << "le numero de telephone :";
    out << p.num_tel << endl;
    out << "la date de naissance  :";
    out << p.date_naiss << endl;
    out << "adresse :";
    out << p.adresse << endl;
    out << "la matricule est :";
    out << p.matricule << endl;
    out << " le salaire est :";
    out << p.salaire << endl;
    out << "le nombred heure de travail est  :";
    out << p.nbre_heures_travail << endl;
    out << "la date d embauche est  :";
    out << p.date_embauche << endl;
    out << "le numero de pilote :";
    out << p.numero_pilote << endl;
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
    cout << "donner le numero de la carte d identite " << endl;
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

ostream &operator<<(ostream &out, Pilote *p)
{
    out << p->nom << "\t"
        << p->prenom << "\t"
        << p->CIN << "\t"
        << p->num_tel << "\t"
        << &(p->date_naiss) << "\t"
        << p->adresse << "\t"
        << p->matricule << "\t"
        << p->salaire << "\t"
        << &(p->date_embauche) << "\t"
        << p->nbre_heures_travail << "\t"
        << p->numero_pilote << endl;
    return out;
}
istream &operator>>(istream &in, Pilote *p)
{
    in >> p->nom >> p->prenom >> p->CIN >> p->num_tel >> &(p->date_naiss) >> p->adresse >> p->matricule >> p->salaire >> &(p->date_embauche) >> p->nbre_heures_travail >> p->numero_pilote;
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