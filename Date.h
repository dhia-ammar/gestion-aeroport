#include <iostream>
using namespace std;
#pragma once
class Date
{
    int jours;
    int mois;
    int annee;

public:
    Date();
    Date(int, int, int);
    void afficher_DATE();
    int getJours();
    int getMois();
    int getAnnee();
    void setJours(int);
    void setMois(int);
    void setAnnee(int);
    bool controle_date();
    friend ostream &operator<<(ostream &, Date &);
    friend istream &operator>>(istream &, Date &);
    friend istream &operator>>(istream &, Date *);
    friend ostream &operator<<(ostream &, Date *);
    bool operator==(const Date &d) const { return (this->jours == d.jours && this->mois == d.mois && this->annee == d.annee); };
};