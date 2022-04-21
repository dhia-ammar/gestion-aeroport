#pragma once
#include <iostream>
using namespace std;

#include "Personnel.cpp"
#include "Date.cpp"
#include <vector>
class Pilote : public Personnel
{
private:
  int numero_pilote;
  bool diponibilite;
  int nbre_heure_vol;

public:
  Pilote();
  Pilote(int, int, float, float, Date, string, string, string, int, Date, string);
  static vector<Pilote> tab;
  static int rechercheCIN(string);
  friend ostream &operator<<(ostream &, Pilote &);
  friend istream &operator>>(istream &, Pilote &);
};
vector<Pilote> Pilote::tab;