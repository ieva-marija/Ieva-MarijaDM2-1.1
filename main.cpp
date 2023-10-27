#include <iostream>
#include <iomanip>
#include "mylib.h"
#include "mylib2.h"

using namespace std;

int main()
{
    vector <Studentas> studentai;
    int pasirinkimas5;
    cout << "Norite sugeneruoti duomenis dabar ar norite testuoti jau sugeneruotus is anksciau? 1-dabar, 2-is anksciau" << endl;
    while(!(cin >> pasirinkimas5) || pasirinkimas5<0 || pasirinkimas5>3)
    {
        cout << "ka cia spaudai... is naujo vesk.. ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    if(pasirinkimas5 == 1)
    {
        generavimoL(studentai, 1000, "s_1000.txt");
        generavimoL(studentai, 10000, "s_10000.txt");
        generavimoL(studentai, 100000, "s_100000.txt");
        generavimoL(studentai, 1000000, "s_1000000.txt");
        generavimoL(studentai, 10000000, "s_10000000.txt");
    
        cout << "-----------------------------------------------------" << endl;
    
        testavimas("s_1000.txt", 1000, "kietiakai_1000.txt", "vargsiukai_1000.txt");
        testavimas("s_10000.txt", 10000, "kietiakai_10000.txt", "vargsiukai_10000.txt");
        testavimas("s_100000.txt", 100000, "kietiakai_100000.txt", "vargsiukai_100000.txt");
        testavimas("s_1000000.txt", 1000000, "kietiakai_1000000.txt", "vargsiukai_1000000.txt");
        testavimas("s_10000000.txt", 10000000, "kietiakai_10000000.txt", "vargsiukai_10000000.txt");
    }
    else if (pasirinkimas5 ==2)
    {
        testavimas("s_1000.txt", 1000, "kietiakai_1000.txt", "vargsiukai_1000.txt");
        testavimas("s_10000.txt", 10000, "kietiakai_10000.txt", "vargsiukai_10000.txt");
        testavimas("s_100000.txt", 100000, "kietiakai_100000.txt", "vargsiukai_100000.txt");
        testavimas("s_1000000.txt", 1000000, "kietiakai_1000000.txt", "vargsiukai_1000000.txt");
        testavimas("s_10000000.txt", 10000000, "kietiakai_10000000.txt", "vargsiukai_10000000.txt");
    }
    return 0;
}
