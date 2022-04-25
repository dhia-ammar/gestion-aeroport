#include <iostream>
#include "Date.cpp"
#include "personne.cpp"
#include "client.cpp"
#include "personnel.cpp"
#include "hotesse.cpp"
#include "pilote.cpp"
#include "employe.cpp"
#include "reservation.cpp"
#include "vol.cpp"
#include <fstream>
using namespace std;

void menu_client()
{ // partie login
    cout << "Donner votre num de CIN : ";
    string nCIN;
    cin >> nCIN;
    int choix;
    int indx = Client::rechercheCIN(nCIN);
    try
    {
        if (indx == -1)
        {
            throw nCIN;
        }
    }
    catch (string nCIN)
    {
        cout << "CE CIN n'existe pas!!" << endl;
    }
    Client client = Client::tab[indx];
    Date d(1, 1, 2000);
    cout << "Pour vous connectez a votre compte entrez votre date de naissance : " << endl;
    cin >> d;
    while (!(d == client.get_date_naiss()))
    {
        cout << "Date de naissance eronnee. Essayez de nouveau!" << endl;
        cin >> d;
    }
    // FIN LOGIN
    while (1)
    {
        cout << endl
             << "Que voulez vous faire?" << endl
             << "1- Afficher mes coordonnes" << endl
             << "2- Afficher mes reservations" << endl
             << "3- Effectuer Une Reservation" << endl
             << "4- Annuler Une reservation" << endl
             << "0-Quitter ce Menu" << endl
             << "99- Netoyez l'ecran" << endl;
        cin >> choix;
        if (choix == 1)
        {
            cout << client;
        }
        else if (choix == 2)
        {
            client.afficher_mes_reservations();
        }
        else if (choix == 3)
        {
            client.effectuer_reservation();
        }
        else if (choix == 4)
        {
            client.annuler_reservation();
        }
        else if (choix == 0)
        {
            system("CLS");
            break;
        }
        else if (choix == 99)
        {
            system("CLS");
        }
        else
        {
            cout << "Choix Invalide Reessayez." << endl;
        }
    }
}
void menu_responsable()
{

    cout << "Donner votre num de CIN : ";
    string nCIN;
    cin >> nCIN;
    int choix;
    int indx = Employe::rechercheCIN(nCIN);
    try
    {
        if (indx == -1)
        {
            throw nCIN;
        }
    }
    catch (string nCIN)
    {
        cout << "CE CIN n'existe pas!!" << endl;
    }
    Employe employe = Employe::tab[indx];
    Date d(1, 1, 2000);
    cout << "Pour vous connectez a votre compte entrez votre date de naissance : " << endl;
    cin >> d;
    while (!(d == employe.get_date_naiss()))
    {
        cout << "Date de naissance eronnee. Essayez de nouveau!" << endl;
        cin >> d;
    }
    while (1)
    {
        cout << endl
             << "Que voulez vous faire?" << endl
             << "1- Afficher mes coordonnes" << endl
             << "2- Afficher toutes les reservations" << endl
             << "3- Afficher tous les clients" << endl
             << "4- Ajouter un client" << endl
             << "5- Modifier un client" << endl
             << "6- Supprimer un client" << endl
             << "7- Afficher tous les Pilotes" << endl
             << "8- Ajouter un Pilote" << endl
             << "9- Modifier un Pilote" << endl
             << "10- Supprimer un Pilote" << endl
             << "11- Afficher toutes les Hotesses" << endl
             << "12- Ajouter une Hotesse" << endl
             << "13- Modifier une Hotesse" << endl
             << "14- Supprimer une Hotesse" << endl
             << "15- Afficher tous les Responsables" << endl
             << "16- Ajouter un Responsable" << endl
             << "17- Modifier un Responsable" << endl
             << "18- Supprimer un Responsable" << endl
             << "19- Afficher tous les Vols" << endl
             << "20- Ajouter un Vol" << endl
             << "0- Quitter ce Menu" << endl
             << "99- Netoyez l'ecran" << endl;
        cin >> choix;
        if (choix == 1)
        {
            cout << employe;
        }
        else if (choix == 2)
        {
            employe.afficher_tous<Reservation>();
        }
        else if (choix == 3)
        {
            employe.afficher_tous<Client>();
        }
        else if (choix == 4)
        {
            employe.ajouterClient();
        }
        else if (choix == 5)
        {
            employe.modifierClient();
        }
        else if (choix == 6)
        {
            employe.supprimerClient();
        }
        else if (choix == 7)
        {
            employe.afficher_tous<Pilote>();
        }
        else if (choix == 8)
        {
            employe.ajouterPilote();
        }
        else if (choix == 9)
        {
            employe.modifierPilote();
        }
        else if (choix == 10)
        {
            employe.supprimerPilote();
        }
        else if (choix == 11)
        {
            employe.afficher_tous<Hotesse>();
        }
        else if (choix == 12)
        {
            employe.ajouterHotesse();
        }
        else if (choix == 13)
        {
            employe.modifierHotesse();
        }
        else if (choix == 14)
        {
            employe.supprimerHotesse();
        }
        else if (choix == 15)
        {
            employe.afficher_tous<Employe>();
        }
        else if (choix == 16)
        {
            employe.ajouterEmploye();
        }
        else if (choix == 17)
        {
            employe.modifierEmploye();
        }
        else if (choix == 18)
        {
            employe.supprimerEmploye();
        }
        else if (choix == 19)
        {
            employe.afficher_tous<Vol>();
        }
        else if (choix == 20)
        {
            employe.ajouterVol();
        }
        else if (choix == 0)
        {
            system("CLS");
            break;
        }
        else if (choix == 99)
        {
            system("CLS");
        }
        else
        {
            cout << "Choix Invalide Reessayez." << endl;
        }
    }
}
void menu_pilote()
{
    cout << "Donner votre num de CIN : ";
    string nCIN;
    cin >> nCIN;
    int choix;
    int indx = Pilote::rechercheCIN(nCIN);
    try
    {
        if (indx == -1)
        {
            throw nCIN;
        }
    }
    catch (string nCIN)
    {
        cout << "CE CIN n'existe pas!!" << endl;
    }
    Pilote pilote = Pilote::tab[indx];
    Date d(1, 1, 2000);
    cout << "Pour vous connectez a votre compte entrez votre date de naissance : " << endl;
    cin >> d;
    while (!(d == pilote.get_date_naiss()))
    {
        cout << "Date de naissance eronnee. Essayez de nouveau!" << endl;
        cin >> d;
    }
    // FIN LOGIN
    while (1)
    {
        cout << endl
             << "Que voulez vous faire?" << endl
             << "1- Afficher mes coordonnes" << endl
             << "2- Afficher mes vols" << endl
             << "0-Quitter ce Menu" << endl
             << "99- Netoyez l'ecran" << endl;
        cin >> choix;
        if (choix == 1)
        {
            cout << pilote;
        }
        else if (choix == 2)
        {
            Vol::afficher_mes_vols_pilote(pilote);
        }
        else if (choix == 0)
        {
            system("CLS");
            break;
        }
        else if (choix == 99)
        {
            system("CLS");
        }
        else
        {
            cout << "Choix Invalide Reessayez." << endl;
        }
    }
}

void menu_hotesse()
{
    cout << "Donner votre num de CIN : ";
    string nCIN;
    cin >> nCIN;
    int choix;
    int indx = Hotesse::rechercheCIN(nCIN);
    try
    {
        if (indx == -1)
        {
            throw nCIN;
        }
    }
    catch (string nCIN)
    {
        cout << "CE CIN n'existe pas!!" << endl;
    }
    Hotesse hotesse = Hotesse::tab[indx];
    Date d(1, 1, 2000);
    cout << "Pour vous connectez a votre compte entrez votre date de naissance : " << endl;
    cin >> d;
    while (!(d == hotesse.get_date_naiss()))
    {
        cout << "Date de naissance eronnee. Essayez de nouveau!" << endl;
        cin >> d;
    }
    // FIN LOGIN
    while (1)
    {
        cout << endl
             << "Que voulez vous faire?" << endl
             << "1- Afficher mes coordonnes" << endl
             << "2- Afficher mes vols" << endl
             << "0-Quitter ce Menu" << endl
             << "99- Netoyez l'ecran" << endl;
        cin >> choix;
        if (choix == 1)
        {
            cout << hotesse;
        }
        else if (choix == 2)
        {
            Vol::afficher_mes_vols_hotesse(hotesse);
        }
        else if (choix == 0)
        {
            system("CLS");
            break;
        }
        else if (choix == 99)
        {
            system("CLS");
        }
        else
        {
            cout << "Choix Invalide Reessayez." << endl;
        }
    }
}
int main()
{
    Employe admin = Employe("DeptA", "Emplo", 15, 5000, 5, Date(13, 12, 2020), "Isslem", "Hidoussi", "07235743", 92, Date(13, 9, 1999), "F");
    // PARTIE CHARGEMENT A NE PAS MODIFIER

    Employe::charger<Client>();
    Employe::charger<Pilote>();
    Employe::charger<Hotesse>();
    Employe::charger<Employe>();
    Employe::charger_autres<Vol>();
    Employe::charger_autres<Reservation>();

    // MENU PRINCIPAL
    int choix;
    while (1)
    {
        cout << "Vous etes? " << endl
             << "1- Un Client" << endl
             << "2- Un Responsable" << endl
             << "3- Une Hotesse" << endl
             << "4- Un Pilote" << endl;
        cin >> choix;
        switch (choix)
        {
        case 1:
            system("CLS");
            menu_client();
            break;
        case 2:
            system("CLS");
            menu_responsable();
            break;
        case 3:
            system("CLS");
            menu_hotesse();
            break;
        case 4:
            system("CLS");
            menu_pilote();
        default:
            cout << "Choix Invalide Reessayez." << endl;
        }
    }
    return 0;
}
