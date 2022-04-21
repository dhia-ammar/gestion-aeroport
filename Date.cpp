#include <iostream>
#pragma once
using namespace std;
#include "Date.h"
Date::Date()
{
    cout << "donner le jour" << endl;
    cin >> jours;
    cout << "donner le mois" << endl;
    cin >> mois;
    cout << "donner l annee" << endl;
    cin >> annee;
};
Date::Date(int j, int m, int a)
{
    this->jours = j;
    this->mois = m;
    this->annee = a;
};
int Date::getJours() { return (this->jours); }

int Date::getMois() { return (this->mois); }

int Date::getAnnee() { return (this->annee); }

void Date::setJours(int jour) { this->jours = jour; }

void Date::setMois(int mois) { this->mois = mois; }

void Date::setAnnee(int annee) { this->annee = annee; }

void Date::afficher_DATE()
{
    cout << jours << "/" << mois << "/" << annee << endl;
};
ostream &operator<<(ostream &out, Date &d)
{
    out << d.jours << "/" << d.mois << "/" << d.annee;
    return out;
}
istream &operator>>(istream &in, Date &d)
{
    in >> d.jours >> d.mois >> d.annee;
    return in;
}