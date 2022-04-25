#pragma once
#include <iostream>
using namespace std;
#include "vol.h"
#include <vector>
#include <fstream>
#include "pilote.cpp"
#include "hotesse.cpp"

Vol::Vol()
{
    string cin_pilote, cin_hotesse;
    cout << "Donner la date de vol : " << endl;
    cin >> this->date_vol;
    cout << "Donner la duree du vol en heures" << endl;
    cin >> this->duree;
    cout << "Donner l'aeroport de depart" << endl;
    cin >> this->aeroport_depart;
    cout << "Donner l'aeroport d arrive" << endl;
    cin >> this->aeroport_arrive;
    cout << "Donner le prix par place" << endl;
    cin >> this->prix_par_place;
    cout << "Donner le numero de CIN du pilote" << endl;
    cin >> cin_pilote;
    while (Pilote::rechercheCIN(cin_pilote) == -1)
    {
        cout << "Aucun Pilote avec ce CIN. Donner un CIN valide !" << endl;
        cin >> cin_pilote;
    }
    this->pilote = Pilote::tab[Pilote::rechercheCIN(cin_pilote)];
    cout << "Donner le numero de CIN de l hotesse" << endl;
    cin >> cin_hotesse;
    while (Hotesse::rechercheCIN(cin_hotesse) == -1)
    {
        cout << "Aucune Hotesse avec ce CIN. Donner un CIN valide !" << endl;
        cin >> cin_hotesse;
    }
    this->hotesse = Hotesse::tab[Hotesse::rechercheCIN(cin_hotesse)];
    cout << "Donner le nombre total de places" << endl;
    cin >> this->nbre_places_total;
    this->nbre_places_restants = this->nbre_places_total;
}

Vol::Vol(Date date_vol, float duree, string aeroport_depart, string aeroport_arrive, float prix_par_place, Pilote pilote, Hotesse hotesse, int nbre_places_total)
{
    this->date_vol = date_vol;
    this->duree = duree;
    this->aeroport_depart = aeroport_depart;
    this->aeroport_arrive = aeroport_arrive;
    this->prix_par_place = prix_par_place;
    this->pilote = pilote;
    this->hotesse = hotesse;
    this->nbre_places_total = nbre_places_total;
    this->nbre_places_restants = this->nbre_places_total;
}

vector<Vol> Vol::vols_dispo(int nbre_places)
{
    vector<Vol> dispo;
    for (int i = 0; i < tab.size(); i++)
    {
        if (tab[i].nbre_places_restants >= nbre_places)
        {
            dispo.push_back(tab[i]);
        }
    }
    return dispo;
}

int Vol::get_nbre_places_restants()
{
    return this->nbre_places_restants;
}

void Vol::set_nbre_places_restants(int nbre_places_restants)
{
    this->nbre_places_restants = nbre_places_restants;
}

float Vol::get_prix_par_place()
{
    return this->prix_par_place;
}

ostream &operator<<(ostream &out, Vol &vol)
{
    out << "Date de vol : " << vol.date_vol << endl
        << "Duree de Vol : " << vol.duree << " Heures" << endl
        << "Aeroport De Depart : " << vol.aeroport_depart << "\t"
        << "Aerorport D'arrive : " << vol.aeroport_arrive << endl
        << "Prix Par Place : " << vol.prix_par_place << endl
        << "Informations Pilote :" << endl
        << vol.pilote << endl
        << "Informations Hotesse :" << endl
        << vol.hotesse << endl
        << "Nombre Total de places : " << vol.nbre_places_total << "\t"
        << "Nombre de places restants : " << vol.nbre_places_restants << endl;
    return out;
}

int Vol::get_nbre_vols_pilote(Pilote pilote)
{
    vector<Vol> vols;
    for (int i = 0; i < Vol::tab.size(); i++)
    {
        if (Vol::tab[i].get_pilote().get_cin() == pilote.get_cin())
        {
            vols.push_back(Vol::tab[i]);
        }
    }
    return vols.size();
}

void Vol::afficher_mes_vols_pilote(Pilote pilote)
{
    for (int i = 0; i < Vol::tab.size(); i++)
    {
        if (Vol::tab[i].get_pilote().get_cin() == pilote.get_cin())
        {
            cout << Vol::tab[i];
        }
    }
}

int Vol::get_nbre_vols_hotesse(Hotesse hotesse)
{
    vector<Vol> vols;
    for (int i = 0; i < Vol::tab.size(); i++)
    {
        if (Vol::tab[i].get_hotesse().get_cin() == hotesse.get_cin())
        {
            vols.push_back(Vol::tab[i]);
        }
    }
    return vols.size();
}

void Vol::afficher_mes_vols_hotesse(Hotesse hotesse)
{
    for (int i = 0; i < Vol::tab.size(); i++)
    {
        if (Vol::tab[i].get_hotesse().get_cin() == hotesse.get_cin())
        {
            cout << Vol::tab[i];
        }
    }
}
istream &operator>>(istream &in, Vol &vol)
{
    string cin_pilote, cin_hotesse;
    cout << "Donner la date de vol : " << endl;
    in >> vol.date_vol;
    cout << "Donner la duree du vol en heures" << endl;
    in >> vol.duree;
    cout << "Donner l'aeroport de depart" << endl;
    in >> vol.aeroport_depart;
    cout << "Donner l'aeroport d arrive" << endl;
    in >> vol.aeroport_arrive;
    cout << "Donner le prix par place" << endl;
    in >> vol.prix_par_place;
    cout << "Donner le numero de CIN du pilote" << endl;
    cin >> cin_pilote;
    while (Pilote::rechercheCIN(cin_pilote) == -1)
    {
        cout << "Aucun Pilote avec ce CIN. Donner un CIN valide !" << endl;
        cin >> cin_pilote;
    }
    vol.pilote = Pilote::tab[Pilote::rechercheCIN(cin_pilote)];
    cout << "Donner le numero de CIN de l hotesse" << endl;
    in >> cin_hotesse;
    while (Hotesse::rechercheCIN(cin_hotesse) == -1)
    {
        cout << "Aucune Hotesse avec ce CIN. Donner un CIN valide !" << endl;
        cin >> cin_hotesse;
    }
    vol.hotesse = Hotesse::tab[Hotesse::rechercheCIN(cin_hotesse)];
    cout << "Donner le nombre total de places" << endl;
    in >> vol.nbre_places_total;
    vol.nbre_places_restants = vol.nbre_places_total;
    return in;
}

ostream &operator<<(ostream &out, Vol *vol)
{
    out << &(vol->date_vol) << "\t"
        << vol->duree << "\t"
        << vol->aeroport_depart << "\t"
        << vol->aeroport_arrive << "\t"
        << vol->prix_par_place << "\t"
        << &(vol->pilote) << "\t"
        << &(vol->hotesse) << "\t"
        << vol->nbre_places_total << "\t"
        << vol->nbre_places_restants << endl;
    return out;
}

istream &operator>>(istream &in, Vol *vol)
{
    string cin_pilote, cin_hotesse;
    in >> &(vol->date_vol) >> vol->duree >> vol->aeroport_depart >> vol->aeroport_arrive >> vol->prix_par_place >> &(vol->pilote) >> &(vol->hotesse) >> vol->nbre_places_total >> vol->nbre_places_restants;
    return in;
}

bool Vol::operator==(const Vol &vol) const
{
    return (this->aeroport_arrive == vol.aeroport_arrive && this->aeroport_depart == vol.aeroport_depart && this->date_vol == vol.date_vol && this->duree == vol.duree && this->nbre_places_total == vol.nbre_places_total);
}