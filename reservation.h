#include <iostream>
#pragma once
using namespace std;
#include <string>
#include "Date.cpp"
#include "client.cpp"
#include "vol.cpp"
#include <vector>

class Reservation
{
    Date date_reservation = Date(1, 1, 1);
    Client client = Client(false);
    int nbre_de_places;
    Vol vol = Vol(false);
    float total_a_payer;

public:
    static vector<Reservation> tab;
    Reservation();
    Reservation(Date, string, int, Vol);
    Reservation(bool){};
    static void supprimer(Reservation);
    string get_cin_client();
    friend ostream &operator<<(ostream &, Reservation &);
    friend istream &operator>>(istream &, Reservation &);
    friend ostream &operator<<(ostream &, Reservation *);
    friend istream &operator>>(istream &, Reservation *);
    bool operator==(const Reservation &reservation) const;
};
vector<Reservation> Reservation::tab;