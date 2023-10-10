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
    generavimas(studentai, 10000, "s_10000.txt");
    generavimas(studentai, 100000, "s_100000.txt");
    generavimas(studentai, 1000000, "s_1000000.txt");
    generavimas(studentai, 10000000, "s_10000000.txt");
    
    return 0;
}
