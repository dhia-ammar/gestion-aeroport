#include <iostream>
#include "Date.cpp"
#include "personne.cpp"
#include "client.cpp"
#include "personnel.cpp"
#include "hotesse.cpp"
#include "pilote.cpp"
#include "employe.cpp"
#include <fstream>
using namespace std;

int main()
{

    Employe e2 = Employe("DeptA", "Emplo", 1313, 1220, 58, Date(23, 2, 2020), "Ammar", "Dhia", "07235743", 41678, Date(13, 11, 1999), "Fouchena");
    // PARTIE CHARGEMENT DO NOT TOUCH THIS PART
    e2.charger<Client>();
    e2.charger<Pilote>();
    e2.charger<Hotesse>();
    e2.charger<Employe>();

    Client c = Client(13, "Dhia", "Ammar", "07235743", 41, Date(13, 11, 1999), "Fouchena");
    Hotesse h = Hotesse("Arabe", "C2", 15, 5000, 5, Date(13, 12, 2020), "Isslem", "Hidoussi", "07235743", 92, Date(13, 9, 1999), "F");

    e2.modifierClient();
    e2.supprimerClient();

    /*e2.ajouterClient();
    e2.ajouterHotesse();
    e2.ajouterPilote();
    cout << Personne::tab.size();*/

    return 0;
}
