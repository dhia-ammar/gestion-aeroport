#pragma once
#include <iostream>
using namespace std;
#include "reservation.h"
#include <vector>
#include <fstream>
#include "client.cpp"
#include "vol.cpp"
#include "employe.cpp"
Reservation::Reservation()
{
    cout << "Donner la date de reservation" << endl;
    cin >> this->date_reservation;
    cout << "Donner le client qui effectue la reservation" << endl;
    cin >> this->client;
    cout << "Donner le nombre de places a reserver :" << endl;
    cin >> this->nbre_de_places;
    cout << "Donner le vol a reserver : " << endl;
    cin >> this->vol;
    this->total_a_payer = this->vol.get_prix_par_place() * this->nbre_de_places;
}

Reservation::Reservation(Date date_reservation, string cin_client, int nbre_de_places, Vol vol)
{
    this->date_reservation = date_reservation;
    this->client = Client::tab[Client::rechercheCIN(cin_client)];

    this->nbre_de_places = nbre_de_places;
    this->vol = vol;
    this->total_a_payer = this->vol.get_prix_par_place() * this->nbre_de_places;
    for (int i = 0; i < Vol::tab.size(); i++)
    {
        if (vol == Vol::tab[i])
        {

            Vol::tab[i].set_nbre_places_restants(Vol::tab[i].get_nbre_places_restants() - nbre_de_places);
        }
    }
    Employe::enregistrer_vector_autre(Vol::tab);
}
string Reservation::get_cin_client()
{
    return this->client.get_cin();
}
void Reservation::supprimer(Reservation res)
{
    int idx;
    for (int i = 0; i < Reservation::tab.size(); i++)
    {
        if (Reservation::tab[i] == res)
        {
            idx = i;
            break;
        }
    }
    for (int i = 0; i < Vol::tab.size(); i++)
    {
        if (res.vol == Vol::tab[i])
        {
            Vol::tab[i].set_nbre_places_restants(Vol::tab[i].get_nbre_places_restants() + res.nbre_de_places);
        }
    }
    Reservation::tab.erase(Reservation::tab.begin() + idx);
    Employe::enregistrer_vector_autre(Reservation::tab);
    Employe::enregistrer_vector_autre(Vol::tab);
}

ostream &operator<<(ostream &out, Reservation &reservation)
{

    out << "Date de reservation : " << reservation.date_reservation << endl
        << "Infos Client : " << endl
        << reservation.client << endl
        << "Nombre de places Reserves : " << reservation.nbre_de_places << endl
        << "Infos Vol : " << endl
        << reservation.vol << endl
        << "Total a Payer : " << reservation.total_a_payer << endl;
    return out;
}

istream &operator>>(istream &in, Reservation &reservation)
{

    return in;
}

ostream &operator<<(ostream &out, Reservation *reservation)
{
    out << &(reservation->date_reservation) << "\t"
        << &(reservation->client) << "\t"
        << reservation->nbre_de_places << "\t"
        << &(reservation->vol) << "\t"
        << reservation->total_a_payer << endl;
    return out;
}

istream &operator>>(istream &in, Reservation *reservation)
{
    string client_cin;
    in >> &(reservation->date_reservation) >> &(reservation->client) >> reservation->nbre_de_places >> &(reservation->vol) >> reservation->total_a_payer;

    return in;
}

bool Reservation::operator==(const Reservation &reservation) const
{
    return (this->client == reservation.client && this->date_reservation == reservation.date_reservation && this->nbre_de_places == reservation.nbre_de_places && this->vol == reservation.vol);
}