#pragma once
#include <iostream>
#include "personnel.h"
using namespace std;
Personnel::Personnel() : Personne()
{
    cout << "donner la matricule" << endl;
    cin >> matricule;
    cout << "donner le salaire" << endl;
    cin >> salaire;
    cout << "donner le nombre d heures du travail" << endl;
    cin >> nbre_heures_travail;
    cout << "donner la date d embauche" << endl;
    cin >> date_embauche;
}

Personnel::Personnel(int matricule, float salaire, float nbre_heures_travail, Date date_embauche, string nom, string prenom, string CIN, int num_tel, Date date_naiss, string adresse) : Personne(nom, prenom, CIN, num_tel, date_naiss, adresse)
{
    this->matricule = matricule;
    this->salaire = salaire;
    this->nbre_heures_travail = nbre_heures_travail;
    this->date_embauche = date_embauche;
}
void Personnel::afficher()
{
    cout << "le nom est :" << nom << endl;
    cout << "le prenom est :" << prenom << endl;
    cout << " le numero de la carte d identite est :" << CIN << endl;
    cout << "le numero de telephone est :" << num_tel << endl;
    cout << "la date de naissance  est :" << this->date_naiss.getJours() << "/" << this->date_naiss.getMois() << "/" << this->date_naiss.getAnnee() << endl;
    cout << "l adresse   est :" << adresse << endl;
    cout << "la matricule est :" << matricule << endl;
    cout << "le salaire est :" << salaire << endl;
    cout << "la date d embauche est :" << this->date_embauche.getJours() << "/" << this->date_embauche.getMois() << "/" << this->date_embauche.getAnnee() << endl;
};
ostream &operator<<(ostream &out, Personnel &p)
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

    return out;
}
istream &operator>>(istream &in, Personnel &p)
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
    return in;
}