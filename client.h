#pragma once
#include <iostream>
using namespace std;
#include "personne.cpp"
#include <vector>
#include <fstream>

class Client : public Personne
{
    int id;

public:
    static vector<Client> tab;
    Client();
    Client(bool a) : Personne(a){};
    Client(int, string, string, string, int, Date, string);
    void afficher();
    static int rechercheCIN(string);
    // void remplir_tab();
    // void supprimer_client();
    friend ostream &operator<<(ostream &, Client &);
    friend istream &operator>>(istream &, Client &);
    friend ostream &operator<<(ostream &, Client *);
    friend istream &operator>>(istream &, Client *);
};
vector<Client> Client::tab;