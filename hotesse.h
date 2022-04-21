#pragma once
#include <iostream>
using namespace std;
#include "personnel.cpp"
#include <vector>
#include <fstream>
class Hotesse : public Personnel
{
  string langue;
  string niveau;

public:
  static vector<Hotesse> tab;
  Hotesse();
  Hotesse(bool a) : Personnel(a){};
  Hotesse(string, string, int, float, float, Date, string, string, string, int, Date, string);
  static int rechercheCIN(string);
  friend ostream &operator<<(ostream &, Hotesse &);
  friend istream &operator>>(istream &, Hotesse &);
  friend ostream &operator<<(ostream &, Hotesse *);
  friend istream &operator>>(istream &, Hotesse *);
};
vector<Hotesse> Hotesse::tab;