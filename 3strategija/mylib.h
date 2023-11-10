#ifndef MYLIB_H
#define MYLIB_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>

using std::string;
using std::vector;
using std::list;

struct Studentas {
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
    float vidurkis, mediana, rezultatasv, rezultatasm;
};

struct Studentas2 {
    std::string vardas, pavarde;
    std::list<int> pazymiai;
    int egzaminas;
    float vidurkis, mediana, rezultatasv, rezultatasm;
};

#endif // MYLIB_H
