#pragma once
#include <iostream>
using namespace std;
#include "client.h"
#include "reservation.cpp"
#include <vector>

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
void Client::effectuer_reservation()
{
    Date date_res = Date(1, 1, 1);
    int nb_places;
    int num_vol;
    vector<Vol> vols_dispo;
    cout << "Donner la date de reservation" << endl;
    cin >> date_res;
    cout << "Donner le nombre de palces que vous voulez reserver" << endl;
    cin >> nb_places;
    vols_dispo = Vol::vols_dispo(nb_places);
    if (vols_dispo.size() > 0)
    {
        for (int i = 0; i < vols_dispo.size(); i++)
        {
            cout << i + 1 << " - " << vols_dispo[i];
        }
        cout << "Donner le numero de vol a reserver ou 0 si vous ne voulez reserver aucun vol: " << endl;
        cin >> num_vol;
        while (num_vol > vols_dispo.size() || num_vol < 0)
        {
            cout << "Numero de vol invalide donner un numero inferieur a " << vols_dispo.size() << endl;
            cin >> num_vol;
        }
        if (num_vol != 0)
        {
            Reservation reservation = Reservation(date_res, this->CIN, nb_places, vols_dispo[num_vol - 1]);
            Reservation::tab.push_back(reservation);
            Employe::enregistrer_vector_autre(Reservation::tab);
        }
        else
        {
            cout << "Vouz avez annuler la reservation!" << endl;
        }
    }
    else
    {
        cout << "Desole aucun vol n'est disponible!" << endl;
    }
}

void Client::annuler_reservation()
{
    vector<Reservation> reservations;
    int num_res;
    for (int i = 0; i < Reservation::tab.size(); i++)
    {
        if (Reservation::tab[i].get_cin_client() == this->CIN)
        {
            reservations.push_back(Reservation::tab[i]);
        }
    }
    if (reservations.size() > 0)
    {

        for (int i = 0; i < reservations.size(); i++)
        {
            cout << i + 1 << " - " << Reservation::tab[i];
        }
        cout << "Choisissez une reservation a annuler ou 0 si vous ne voulez annuler aucune reservation: " << endl;
        cin >> num_res;
        while (num_res > reservations.size() || num_res < 0)
        {
            cout << "Choix invalide! Choisissez une reservation a annuler ou 0 si vous ne voulez annuler aucune reservation: " << endl;
        }
        if (num_res != 0)
        {
            Reservation::supprimer(reservations[num_res - 1]);

            cout << "Annulation avec success !";
        }
        else
        {
            cout << "Vous n avez annuler aucune reservation" << endl;
        }
    }
    else
    {
        cout << "vous n 'avez aucune reservation a annuler";
    }
}
void Client::afficher_mes_reservations()
{
    vector<Reservation> reservations;
    int num_res, idx;
    for (int i = 0; i < Reservation::tab.size(); i++)
    {
        if (Reservation::tab[i].get_cin_client() == this->CIN)
        {
            reservations.push_back(Reservation::tab[i]);
        }
    }
    if (reservations.size() > 0)
    {
        cout << "Mes Reservations : " << endl;
        for (int i = 0; i < reservations.size(); i++)
        {
            cout << reservations[i];
        }
    }
    else
    {
        cout << "Vous n avez aucune reservation" << endl;
    }
}
int Client::get_nbre_reservations()
{
    vector<Reservation> reservations;

    for (int i = 0; i < Reservation::tab.size(); i++)
    {
        if (Reservation::tab[i].get_cin_client() == this->CIN)
        {
            reservations.push_back(Reservation::tab[i]);
        }
    }
    return reservations.size();
}
ostream &operator<<(ostream &out, Client &c)
{
    out << "identifiant :";
    out << c.id << endl;
    out << "le nom :";
    out << c.nom << endl;
    out << "le prenom :";
    out << c.prenom << endl;
    out << "le numero de la carte d identite :";
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
ostream &operator<<(ostream &out, Client *c)
{
    out << c->id << "\t" << c->nom << "\t" << c->prenom << "\t" << c->CIN << "\t" << c->num_tel << "\t" << &(c->date_naiss) << "\t" << c->adresse << endl;
    return out;
}

istream &operator>>(istream &in, Client *c)
{
    in >> c->id >> c->nom >> c->prenom >> c->CIN >> c->num_tel >> &(c->date_naiss) >> c->adresse;
    return in;
}