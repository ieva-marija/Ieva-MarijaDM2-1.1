#include <iostream>
#include <iomanip>
#include "mylib.h"
#include "mylib2.h"

using namespace std;

int main()
{
    vector <Studentas> studentai;
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

    return 0;
}
