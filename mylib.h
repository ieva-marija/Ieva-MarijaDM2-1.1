#ifndef MYLIB_H
#define MYLIB_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct Studentas {
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
    float vidurkis, mediana, rezultatasv, rezultatasm;
};

#endif // MYLIB_H
