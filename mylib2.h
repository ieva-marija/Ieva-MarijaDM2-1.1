#ifndef MYLIB2_H_INCLUDED
#define MYLIB2_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>

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
using std::sort;

Studentas ivesk();
int rankinisFailinis(vector<Studentas>& studentai);
void skaityti(vector<Studentas>& studentai, const string& pav);
float galutinisVid(const Studentas& studentas);
float galutinisMed(const Studentas& studentas);
void rusiavimas(vector<Studentas>& studentai);
void generavimas(vector<Studentas>& studentai, int count, const string& failas);
void saugojimas(const string& failas, const vector<Studentas>& studentai);

#endif // MYLIB2_H_INCLUDED
