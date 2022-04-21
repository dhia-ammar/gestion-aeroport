#pragma once
#include <iostream>
using namespace std;
#include "personne.h"

Personne::Personne()
{
    string s;
    cout << "donner le nom" << endl;
    cin >> nom;
    cout << "donner le prenom " << endl;
    cin >> prenom;
    cout << "donner le numero de la carte d identité" << endl;
    cin >> s;
    while (controleCIN(s) == false || rechercheCIN(s) != -1)
    {
        if (controleCIN(s) == false)
        {
            cout << "CIN Invalide! Reessayez: " << endl;
            cin >> s;
        }
        else
        {
            cout << "ce CIN existe deja! Les CINs doivent etre unique!" << endl;
            cin >> s;
        }
    }
    this->CIN = s;
    cout << "donner le numero de telephone" << endl;
    cin >> num_tel;
    cout << "donner la date de naissance " << endl;
    cin >> date_naiss;
    cout << "donner ladresse " << endl;
    cin >> adresse;
}
Personne::Personne(string nom, string prenom, string CIN, int num_tel, Date d, string adresse)
{
    this->nom = nom;
    this->prenom = prenom;
    this->CIN = CIN;
    this->num_tel = num_tel;
    this->date_naiss.setJours(d.getJours());
    this->date_naiss.setMois(d.getMois());
    this->date_naiss.setAnnee(d.getAnnee());
    this->adresse = adresse;
}
bool Personne::controleCIN(string CIN)
{
    if (CIN.length() != 8)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < 8; i++)
        {
            if (CIN[i] > '9' || CIN[i] < '0')
            {
                return false;
            }
        }
        return true;
    }
}

int Personne::rechercheCIN(string CIN1)
{
    for (int i = 0; i < tab.size(); i++)
    {
        if (tab[i].CIN == CIN1)
        {
            return i;
        }
    }
    return -1;
}