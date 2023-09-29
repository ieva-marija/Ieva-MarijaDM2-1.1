#ifndef MYLIB_H
#define MYLIB_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::setw;
using std::left;
using std::right;

struct Studentas {
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
    float vidurkis, mediana, rezultatasv, rezultatasm;
};

Studentas ivesk();
float galutinisVid(const Studentas& studentas);
float galutinisMed(const Studentas& studentas);
void skaityti(vector<Studentas>& studentai, const string& pav);

#endif // MYLIB_H
