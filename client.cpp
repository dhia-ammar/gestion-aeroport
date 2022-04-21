#pragma once
#include <iostream>
using namespace std;
#include "client.h"
Client::Client() : Personne()
{
    cout << "donner l identifiant " << endl;
    cin >> id;
}
Client::Client(int id, string nom, string prenom, string CIN, int num_tel, Date date_naiss, string adresse) : Personne(nom, prenom, CIN, num_tel, date_naiss, adresse)
{
    this->id = id;
};
void Client::afficher()
{
    cout << "l identifaiant est :" << id << endl;

    cout << "le nom : :" << nom << endl;
    cout << "le prenom :" << prenom << endl;
    cout << "le numero de carte d identite: " << CIN << endl;
    cout << "le numero de telephone :" << num_tel << endl;
    cout << "la date de naissance est :" << date_naiss.getJours() << "/" << date_naiss.getMois() << "/" << date_naiss.getAnnee() << endl;
    cout << "l adresse est :" << adresse << endl;
}
ostream &operator<<(ostream &out, Client &c)
{
    out << "identifiant :";
    out << c.id << endl;
    out << "le nom :";
    out << c.nom << endl;
    out << "le prenom :";
    out << c.prenom << endl;
    out << "le numero de la carte d identité :";
    out << c.CIN << endl;
    out << "le numero de telephone :";
    out << c.num_tel << endl;
    out << "la date de naissance  :";
    out << c.date_naiss << endl;
    out << "adresse :";
    out << c.adresse << endl;

    return out;
}
istream &operator>>(istream &in, Client &c)
{
    cout << "donner le nom " << endl;
    in >> c.nom;
    cout << "donner le prenom " << endl;
    in >> c.prenom;
    cout << "donner le numero de la carte d identite " << endl;
    in >> c.CIN;
    cout << "donner le numero de telephne" << endl;
    in >> c.num_tel;
    cout << "donner la date de naissance" << endl;
    in >> c.date_naiss;
    cout << "donner l 'adresse  " << endl;
    in >> c.adresse;
    cout << "donner l identifiant " << endl;
    in >> c.id;
    return in;
}
int Client::rechercheCIN(string CIN)
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