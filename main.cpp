#include <iostream>
#include <iomanip>
#include "mylib.h"
#include "mylib2.h"

using namespace std;

int main()
{
    vector <Studentas> studentai;
    list <Studentas> studentai2;
    int pasirinkimas5;
    char pasirinkimas6;
    cout << "Norite sugeneruoti duomenis dabar ar norite testuoti jau sugeneruotus is anksciau? 1-dabar, 2-is anksciau" << endl;
    while(!(cin >> pasirinkimas5) || pasirinkimas5<0 || pasirinkimas5>3)
    {
        cout << "ka cia spaudai.... is naujo vesk..";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "Norite naudoti vector (v) tipo konteinerius ar list (l)?" << endl;
    while(!(cin >> pasirinkimas6) || (pasirinkimas6!='v' && pasirinkimas6!='V' && pasirinkimas6!='l' && pasirinkimas6!='L'))
    {
        cout << "ne taip, per naujo. ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if(pasirinkimas5 == 1)
    {
        if(pasirinkimas6=='v' || pasirinkimas6=='V')
        {
            generavimoLVector(studentai, 1000, "s_1000.txt");
            generavimoLVector(studentai, 10000, "s_10000.txt");
            generavimoLVector(studentai, 100000, "s_100000.txt");
            generavimoLVector(studentai, 1000000, "s_1000000.txt");
            generavimoLVector(studentai, 10000000, "s_10000000.txt");

        cout << "-----------------------------------------------------" << endl;

            testavimasv("s_1000.txt", 1000, "kietiakai_1000.txt", "vargsiukai_1000.txt");
            testavimasv("s_10000.txt", 10000, "kietiakai_10000.txt", "vargsiukai_10000.txt");
            testavimasv("s_100000.txt", 100000, "kietiakai_100000.txt", "vargsiukai_100000.txt");
            testavimasv("s_1000000.txt", 1000000, "kietiakai_1000000.txt", "vargsiukai_1000000.txt");
            testavimasv("s_10000000.txt", 10000000, "kietiakai_10000000.txt", "vargsiukai_10000000.txt");
        }
        else
        {
            generavimoLList(studentai2, 1000, "s_1000.txt");
            generavimoLList(studentai2, 10000, "s_10000.txt");
            generavimoLList(studentai2, 100000, "s_100000.txt");
            generavimoLList(studentai2, 1000000, "s_1000000.txt");
            generavimoLList(studentai2, 10000000, "s_10000000.txt");

        cout << "-----------------------------------------------------" << endl;
            testavimasl("s_1000.txt", 1000, "kietiakai_1000.txt", "vargsiukai_1000.txt");
            testavimasl("s_10000.txt", 10000, "kietiakai_10000.txt", "vargsiukai_10000.txt");
            testavimasl("s_100000.txt", 100000, "kietiakai_100000.txt", "vargsiukai_100000.txt");
            testavimasl("s_1000000.txt", 1000000, "kietiakai_1000000.txt", "vargsiukai_1000000.txt");
            testavimasl("s_10000000.txt", 10000000, "kietiakai_10000000.txt", "vargsiukai_10000000.txt");
        }
    }
    else if (pasirinkimas5 == 2)
    {
        if(pasirinkimas6=='v' || pasirinkimas6=='V')
        {
            testavimasv("s_1000.txt", 1000, "kietiakai_1000.txt", "vargsiukai_1000.txt");
            testavimasv("s_10000.txt", 10000, "kietiakai_10000.txt", "vargsiukai_10000.txt");
            testavimasv("s_100000.txt", 100000, "kietiakai_100000.txt", "vargsiukai_100000.txt");
            testavimasv("s_1000000.txt", 1000000, "kietiakai_1000000.txt", "vargsiukai_1000000.txt");
            testavimasv("s_10000000.txt", 10000000, "kietiakai_10000000.txt", "vargsiukai_10000000.txt");
        }
        else
        {
            testavimasl("s_1000.txt", 1000, "kietiakai_1000.txt", "vargsiukai_1000.txt");
            testavimasl("s_10000.txt", 10000, "kietiakai_10000.txt", "vargsiukai_10000.txt");
            testavimasl("s_100000.txt", 100000, "kietiakai_100000.txt", "vargsiukai_100000.txt");
            testavimasl("s_1000000.txt", 1000000, "kietiakai_1000000.txt", "vargsiukai_1000000.txt");
            testavimasl("s_10000000.txt", 10000000, "kietiakai_10000000.txt", "vargsiukai_10000000.txt");
        }
    }
    return 0;
}
