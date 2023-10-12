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
void skaityti2(vector<Studentas>& studentai, const string& pav);

void rusiavimas2(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai);
void isvedimasV(const string& failas_vargsiukai, const vector<Studentas>& vargsiukai);
void isvedimasK(const string& failas_kietiakai, const vector<Studentas>& kietiakai);

void generavimoL(vector<Studentas>& studentai, int skaicius, const string& failas);
void skaitymoL(vector<Studentas>& studentai, int skaicius, const string& failas);
void rusiavimoL(vector<Studentas>& studentai, int skaicius, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai);
void isvedimoVL(const string& failas_vargsiukai, int skaicius, const vector<Studentas>& vargsiukai);
void isvedimoKL(const string& failas_kietiakai, int skaicius, const vector<Studentas>& kietiakai);
#endif
