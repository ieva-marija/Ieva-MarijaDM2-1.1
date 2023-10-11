#include <iostream>
#include <iomanip>
#include "mylib.h"
#include "mylib2.h"
#include <limits>

using namespace std;

int main()
{
    vector <Studentas> studentai;
    generavimas(studentai, 1000, "s_1000.txt");
    vector<Studentas> vargsiukai_1000;
    vector<Studentas> kietiakai_1000;
    rusiavimas2(studentai, vargsiukai_1000, kietiakai_1000);
    isvedimas("vargsiukai_1000.txt", "kietiakai_1000.txt", vargsiukai_1000, kietiakai_1000);

    generavimas(studentai, 10000, "s_10000.txt");
    vector<Studentas> vargsiukai_10000;
    vector<Studentas> kietiakai_10000;
    rusiavimas2(studentai, vargsiukai_10000, kietiakai_10000);
    isvedimas("vargsiukai_10000.txt", "kietiakai_10000.txt", vargsiukai_10000, kietiakai_10000);

    generavimas(studentai, 100000, "s_100000.txt");
    vector<Studentas> vargsiukai_100000;
    vector<Studentas> kietiakai_100000;
    rusiavimas2(studentai, vargsiukai_100000, kietiakai_100000);
    isvedimas("vargsiukai_100000.txt", "kietiakai_100000.txt", vargsiukai_100000, kietiakai_100000);

    generavimas(studentai, 1000000, "s_1000000.txt");
    vector<Studentas> vargsiukai_1000000;
    vector<Studentas> kietiakai_1000000;
    rusiavimas2(studentai, vargsiukai_1000000, kietiakai_1000000);
    isvedimas("vargsiukai_1000000.txt", "kietiakai_1000000.txt", vargsiukai_1000000, kietiakai_1000000);

    generavimas(studentai, 10000000, "s_10000000.txt");
    vector<Studentas> vargsiukai_10000000;
    vector<Studentas> kietiakai_10000000;
    rusiavimas2(studentai, vargsiukai_10000000, kietiakai_10000000);
    isvedimas("vargsiukai_10000000.txt", "kietiakai_10000000.txt", vargsiukai_10000000, kietiakai_10000000);

    return 0;
}
