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
float galutinisVid(const Studentas& studentas);
float galutinisMed(const Studentas& studentas);
void skaityti(vector<Studentas>& studentai, const string& pav);
void rusiavimas(vector<Studentas>& studentai);
int rankinisFailinis(vector<Studentas>& studentai);
void generavimas(vector<Studentas>& studentai, int count, const string& failas);
void saugojimas(const string& failas, const vector<Studentas>& studentai);
void rusiavimas2(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai);
void isvedimas(const string& failas_vargsiukai, const string& failas_kietiakai, const vector<Studentas>& vargsiukai, const vector<Studentas>& kietiakai);

#endif 
