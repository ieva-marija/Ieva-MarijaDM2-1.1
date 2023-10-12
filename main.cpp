#include <iostream>
#include <iomanip>
#include "mylib.h"
#include "mylib2.h"
#include <limits>
#include <chrono>

using namespace std;

int main()
{
    vector <Studentas> studentai;
    
    vector<Studentas> vargsiukai_1000;
    vector<Studentas> kietiakai_1000;
    generavimoL(studentai, 1000, "s_1000.txt");
    skaitymoL(studentai, 1000, "s_1000.txt");
    rusiavimoL(studentai, 1000, vargsiukai_1000, kietiakai_1000);
    isvedimoVL("vargsiukai_1000.txt", 1000, vargsiukai_1000);
    isvedimoKL("kietiakai_1000.txt", 1000, kietiakai_1000);

    cout<< "///////////////////////////////////////////////////////////////////////////" << endl;

    vector<Studentas> vargsiukai_10000;
    vector<Studentas> kietiakai_10000;
    generavimoL(studentai, 10000, "s_10000.txt");
    skaitymoL(studentai, 10000, "s_10000.txt");
    rusiavimoL(studentai, 10000, vargsiukai_10000, kietiakai_10000);
    isvedimoVL("vargsiukai_10000.txt", 10000, vargsiukai_10000);
    isvedimoKL("kietiakai_10000.txt", 10000, kietiakai_10000);

    cout<< "///////////////////////////////////////////////////////////////////////////" << endl;

    vector<Studentas> vargsiukai_100000;
    vector<Studentas> kietiakai_100000;
    generavimoL(studentai, 100000, "s_100000.txt");
    skaitymoL(studentai, 100000, "s_100000.txt");
    rusiavimoL(studentai, 100000, vargsiukai_100000, kietiakai_100000);
    isvedimoVL("vargsiukai_100000.txt", 100000, vargsiukai_100000);
    isvedimoKL("kietiakai_100000.txt", 100000, kietiakai_100000);

    cout<< "///////////////////////////////////////////////////////////////////////////" << endl;

    vector<Studentas> vargsiukai_1000000;
    vector<Studentas> kietiakai_1000000;
    generavimoL(studentai, 1000000, "s_1000000.txt");
    skaitymoL(studentai, 1000000, "s_1000000.txt");
    rusiavimoL(studentai, 1000000, vargsiukai_1000000, kietiakai_1000000);
    isvedimoVL("vargsiukai_1000000.txt", 1000000, vargsiukai_1000000);
    isvedimoKL("kietiakai_1000000.txt", 1000000, kietiakai_1000000);

    cout<< "///////////////////////////////////////////////////////////////////////////" << endl;

    vector<Studentas> vargsiukai_10000000;
    vector<Studentas> kietiakai_10000000;
    generavimoL(studentai, 10000000, "s_10000000.txt");
    skaitymoL(studentai, 10000000, "s_10000000.txt");
    rusiavimoL(studentai, 10000000, vargsiukai_10000000, kietiakai_10000000);
    isvedimoVL("vargsiukai_10000000.txt", 10000000, vargsiukai_10000000);
    isvedimoKL("kietiakai_10000000.txt", 10000000, kietiakai_10000000);

    return 0;
}
