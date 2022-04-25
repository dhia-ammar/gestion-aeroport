#include <iostream>
#pragma once
using namespace std;
#include <string>
#include "Date.cpp"
#include "pilote.cpp"
#include "hotesse.cpp"
#include <vector>
class Vol
{
    Date date_vol = Date(1, 1, 1);
    float duree;
    string aeroport_depart;
    string aeroport_arrive;
    float prix_par_place;
    Pilote pilote = Pilote(false);
    Hotesse hotesse = Hotesse(false);
    int nbre_places_total;
    int nbre_places_restants;

public:
    static vector<Vol> tab;
    Vol();
    Vol(bool){};
    Vol(Date, float, string, string, float, Pilote, Hotesse, int);

    int get_nbre_places_restants();
    void set_nbre_places_restants(int);
    float get_prix_par_place();
    Pilote get_pilote() { return pilote; }
    Hotesse get_hotesse() { return hotesse; }
    static int get_nbre_vols_pilote(Pilote);
    static void afficher_mes_vols_pilote(Pilote);
    static int get_nbre_vols_hotesse(Hotesse);
    static void afficher_mes_vols_hotesse(Hotesse);
    static vector<Vol> vols_dispo(int);
    friend ostream &operator<<(ostream &, Vol &);
    friend istream &operator>>(istream &, Vol &);
    friend ostream &operator<<(ostream &, Vol *);
    friend istream &operator>>(istream &, Vol *);
    bool operator==(const Vol &vol) const;
};
vector<Vol> Vol::tab;