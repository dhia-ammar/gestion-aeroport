#pragma once
#include <iostream>
using namespace std;
#include "employe.h"
#include "client.h"
#include "hotesse.h"
#include "pilote.h"
#include <fstream>
#include "vol.h"
#include "reservation.h"

Employe::Employe() : Personnel()
{
    cout << "donner le departement" << endl;
    cin >> departement;
    cout << "donner la poste " << endl;
    cin >> poste;
}
Employe::Employe(string departement, string poste, int matricule, float salaire, float nbre_heures_travail, Date date_embauche, string nom, string prenom, string CIN, int num_tel, Date date_naiss, string adresse) : Personnel(matricule, salaire, nbre_heures_travail, date_embauche, nom, prenom, CIN, num_tel, date_naiss, adresse)
{
    this->departement = departement;
    this->poste = poste;
}

int Employe::rechercheCIN(string CIN)
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

void Employe::ajouterClient()
{
    Client client = Client();
    this->sauvegarder<Client>(client);
    cout << "Ajout avec Success!" << endl;
}
void Employe::ajouterEmploye()
{
    Employe employe = Employe();
    this->sauvegarder<Employe>(employe);
    cout << "Ajout avec Success!" << endl;
}
void Employe::ajouterHotesse()
{
    Hotesse hotesse = Hotesse();
    this->sauvegarder<Hotesse>(hotesse);
    cout << "Ajout avec Success!" << endl;
}
void Employe::ajouterPilote()
{
    Pilote pilote = Pilote();
    this->sauvegarder<Pilote>(pilote);
    cout << "Ajout avec Success!" << endl;
}
void Employe::ajouterVol()
{
    Vol vol = Vol();
    this->sauvegarder_autre<Vol>(vol);
    cout << "Ajout avec Success!" << endl;
}

void Employe::modifierClient()
{
    string CIN;
    cout << "Donner le CIN du client a modifier: " << endl;
    cin >> CIN;
    int idx_clients, idx_personnes;
    idx_personnes = Personne::rechercheCIN(CIN);
    idx_clients = Client::rechercheCIN(CIN);
    if (idx_clients == -1 || idx_personnes == -1)
    {
        cout << "CIN n'existe pas" << endl;
    }
    else
    {
        Personne::tab.erase(Personne::tab.begin() + idx_personnes);
        Client::tab.erase(Client::tab.begin() + idx_clients);
        Client client = Client();
        Client::tab.push_back(client);
        Personne p = static_cast<Personne>(client);
        Personne::tab.push_back(p);
        this->enregistrer_vector<Client>(Client::tab);
        cout << "Modification avec success!" << endl;
        cout << client;
    }
}
void Employe::modifierEmploye()
{
    string CIN;
    cout << "Donner le CIN de l employe a modifier: " << endl;
    cin >> CIN;
    int idx_employes, idx_personnes;
    idx_personnes = Personne::rechercheCIN(CIN);
    idx_employes = Employe::rechercheCIN(CIN);
    if (idx_employes == -1 || idx_personnes == -1)
    {
        cout << "CIN n'existe pas" << endl;
    }
    else
    {
        Personne::tab.erase(Personne::tab.begin() + idx_personnes);
        Employe::tab.erase(Employe::tab.begin() + idx_employes);
        Employe employe = Employe();
        Employe::tab.push_back(employe);
        Personne p = static_cast<Personne>(employe);
        Personne::tab.push_back(p);
        this->enregistrer_vector<Employe>(Employe::tab);
        cout << "Modification avec success!" << endl;
        cout << employe;
    }
}
void Employe::modifierHotesse()
{
    string CIN;
    cout << "Donner le CIN de l hotesse a modifier: " << endl;
    cin >> CIN;
    int idx_hotesses, idx_personnes;
    idx_personnes = Personne::rechercheCIN(CIN);
    idx_hotesses = Hotesse::rechercheCIN(CIN);
    if (idx_hotesses == -1 || idx_personnes == -1)
    {
        cout << "CIN n'existe pas" << endl;
    }
    else
    {
        Personne::tab.erase(Personne::tab.begin() + idx_personnes);
        Hotesse::tab.erase(Hotesse::tab.begin() + idx_hotesses);
        Hotesse hotesse = Hotesse();
        Hotesse::tab.push_back(hotesse);
        Personne p = static_cast<Personne>(hotesse);
        Personne::tab.push_back(p);
        this->enregistrer_vector<Hotesse>(Hotesse::tab);
        cout << "Modification avec success!" << endl;
        cout << hotesse;
    }
}
void Employe::modifierPilote()
{
    string CIN;
    cout << "Donner le CIN du pilote a modifier: " << endl;
    cin >> CIN;
    int idx_pilotes, idx_personnes;
    idx_personnes = Personne::rechercheCIN(CIN);
    idx_pilotes = Pilote::rechercheCIN(CIN);
    if (idx_pilotes == -1 || idx_personnes == -1)
    {
        cout << "CIN n'existe pas" << endl;
    }
    else
    {
        Personne::tab.erase(Personne::tab.begin() + idx_personnes);
        Pilote::tab.erase(Pilote::tab.begin() + idx_pilotes);
        Pilote pilote = Pilote();
        Pilote::tab.push_back(pilote);
        Personne p = static_cast<Personne>(pilote);
        Personne::tab.push_back(p);
        this->enregistrer_vector<Pilote>(Pilote::tab);
        cout << "Modification avec success!" << endl;
        cout << pilote;
    }
}
void Employe::supprimerClient()
{
    string CIN;
    cout << "Donner le CIN du client a supprimer: " << endl;
    cin >> CIN;
    int idx_clients, idx_personnes;
    idx_personnes = Personne::rechercheCIN(CIN);
    idx_clients = Client::rechercheCIN(CIN);
    if (idx_clients == -1 || idx_personnes == -1)
    {
        cout << "CIN n'existe pas" << endl;
    }
    else
    {
        if (Client::tab[idx_clients].get_nbre_reservations() > 0)
        {
            cout << "Impossible de supprimer ce client car il a des reservations" << endl;
        }
        else
        {
            Personne::tab.erase(Personne::tab.begin() + idx_personnes);
            Client::tab.erase(Client::tab.begin() + idx_clients);
            this->enregistrer_vector<Client>(Client::tab);
            cout << "Suppression avec success!" << endl;
        }
    }
}
void Employe::supprimerEmploye()
{
    string CIN;
    cout << "Donner le CIN de l employe a supprimer: " << endl;
    cin >> CIN;
    int idx_employes, idx_personnes;
    idx_personnes = Personne::rechercheCIN(CIN);
    idx_employes = Employe::rechercheCIN(CIN);
    if (idx_employes == -1 || idx_personnes == -1)
    {
        cout << "CIN n'existe pas" << endl;
    }
    else
    {
        Personne::tab.erase(Personne::tab.begin() + idx_personnes);
        Employe::tab.erase(Employe::tab.begin() + idx_employes);
        this->enregistrer_vector<Employe>(Employe::tab);
        cout << "Suppression avec success!" << endl;
    }
}
void Employe::supprimerHotesse()
{
    string CIN;
    cout << "Donner le CIN de l hotesse a supprimer: " << endl;
    cin >> CIN;
    int idx_hotesses, idx_personnes;
    idx_personnes = Personne::rechercheCIN(CIN);
    idx_hotesses = Hotesse::rechercheCIN(CIN);
    if (idx_hotesses == -1 || idx_personnes == -1)
    {
        cout << "CIN n'existe pas" << endl;
    }
    else
    {
        if (Vol::get_nbre_vols_hotesse(Hotesse::tab[idx_hotesses]) > 0)
        {
            cout << "Impossible de supprimer cette Hotesse car elle a des vols" << endl;
        }
        else
        {
            Personne::tab.erase(Personne::tab.begin() + idx_personnes);
            Hotesse::tab.erase(Hotesse::tab.begin() + idx_hotesses);
            this->enregistrer_vector<Hotesse>(Hotesse::tab);
            cout << "suppression avec success!" << endl;
        }
    }
}
void Employe::supprimerPilote()
{
    string CIN;
    cout << "Donner le CIN du pilote a supprimer: " << endl;
    cin >> CIN;
    int idx_pilotes, idx_personnes;
    idx_personnes = Personne::rechercheCIN(CIN);
    idx_pilotes = Pilote::rechercheCIN(CIN);
    if (idx_pilotes == -1 || idx_personnes == -1)
    {
        cout << "CIN n'existe pas" << endl;
    }
    else
    {
        if (Vol::get_nbre_vols_pilote(Pilote::tab[idx_pilotes]) > 0)
        {
            cout << "Impossible de supprimer ce Pilote car elle a des vols" << endl;
        }
        else
        {
            Personne::tab.erase(Personne::tab.begin() + idx_personnes);
            Pilote::tab.erase(Pilote::tab.begin() + idx_pilotes);
            this->enregistrer_vector<Pilote>(Pilote::tab);
            cout << "Suppression avec success!" << endl;
        }
    }
}

ostream &operator<<(ostream &out, Employe &e)
{

    out << "le nom :";
    out << e.nom << endl;
    out << "le prenom :";
    out << e.prenom << endl;
    out << "le numero de la carte d identite :";
    out << e.CIN << endl;
    out << "le numero de telephone :";
    out << e.num_tel << endl;
    out << "la date de naissance  :";
    out << e.date_naiss << endl;
    out << "adresse :";
    out << e.adresse << endl;
    out << "matricule :";
    out << e.matricule << endl;
    out << "salaire :";
    out << e.salaire << endl;
    out << "date d embauche :";
    out << e.date_embauche << endl;
    out << "nombre d heures de travail :";
    out << e.nbre_heures_travail << endl;
    out << "le departement :";
    out << e.departement << endl;
    out << "le poste :";
    out << e.poste << endl;

    return out;
}
istream &operator>>(istream &in, Employe &e)
{
    cout << "donner le nom " << endl;
    in >> e.nom;
    cout << "donner le prenom " << endl;
    in >> e.prenom;
    cout << "donner le numero de la carte d identite " << endl;
    in >> e.CIN;
    cout << "donner le numero de telephne" << endl;
    in >> e.num_tel;
    cout << "donner la date de naissance" << endl;
    in >> e.date_naiss;
    cout << "donner l 'adresse  " << endl;
    in >> e.adresse;
    cout << "donner la matricule :";
    in >> e.matricule;
    cout << "donner le salaire :";
    in >> e.salaire;
    cout << "donner la date d embauche :";
    in >> e.date_embauche;
    cout << "donner le nombre d heures de travail :";
    in >> e.nbre_heures_travail;
    cout << "donner le depatement" << endl;
    in >> e.departement;
    cout << "donner le poste" << endl;
    in >> e.poste;

    return in;
}

ostream &operator<<(ostream &out, Employe *e)
{
    out << e->nom << "\t"
        << e->prenom << "\t"
        << e->CIN << "\t"
        << e->num_tel << "\t"
        << &(e->date_naiss) << "\t"
        << e->adresse << "\t"
        << e->matricule << "\t"
        << e->salaire << "\t"
        << &(e->date_embauche) << "\t"
        << e->nbre_heures_travail << "\t"
        << e->departement << "\t"
        << e->poste << endl;
    return out;
}
istream &operator>>(istream &in, Employe *e)
{
    in >> e->nom >> e->prenom >> e->CIN >> e->num_tel >> &(e->date_naiss) >> e->adresse >> e->matricule >> e->salaire >> &(e->date_embauche) >> e->nbre_heures_travail >> e->departement >> e->poste;
    return in;
}
