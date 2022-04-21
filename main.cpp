#include <iostream>
#include "Date.cpp"
#include "personne.cpp"
#include "client.cpp"
#include "personnel.cpp"
#include "hotesse.cpp"
#include "pilote.cpp"
#include "employe.cpp"
using namespace std;

int main()
{

    Employe e2 = Employe("DeptA", "Emplo", 1313, 1220, 58, Date(23, 2, 2020), "Isslem", "Hidoussi", "07235743", 41678, Date(13, 11, 1999), "Fouchena");
    e2.ajouterClient();
    e2.ajouterHotesse();
    e2.ajouterPilote();
    cout << Personne::tab.size();

    return 0;
}
