#pragma once
#include <iostream>
using namespace std;
#include "vol.h"
#include "Personnel.cpp"
#include "Date.cpp"
#include <vector>

class Vol;

class Pilote : public Personnel
{
private:
  int numero_pilote;
  bool diponibilite;
  int nbre_heure_vol;

public:
  Pilote();
  Pilote(bool a) : Personnel(a) { nbre_heure_vol = 0; };
  Pilote(int, int, float, float, Date, string, string, string, int, Date, string);
  static vector<Pilote> tab;
  static int rechercheCIN(string);
  //int get_nbre_vols();
  //void afficher_mes_vols();
  friend ostream &operator<<(ostream &, Pilote &);
  friend istream &operator>>(istream &, Pilote &);
  friend ostream &operator<<(ostream &, Pilote *);
  friend istream &operator>>(istream &, Pilote *);
};
vector<Pilote> Pilote::tab;
