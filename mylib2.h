#ifndef MYLIB2_H_INCLUDED
#define MYLIB2_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <list>

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
using std::list;

Studentas ivesk();
float galutinisVidVector(const Studentas& studentas);
float galutinisVidList(const Studentas2& studentas);
float galutinisMedVector(const Studentas& studentas);
float galutinisMedList(const Studentas2& studentas);

void skaityti(vector<Studentas>& studentai, const string& pav);
void rusiavimasVector(vector<Studentas>& studentai);
void rusiavimasList(list<Studentas2>& studentai);
int rankinisFailinis(vector<Studentas>& studentai);

void generavimasVector(vector<Studentas>& studentai, int count, const string& failas);
void saugojimasVector(const string& failas, const vector<Studentas>& studentai);
void skaityti2Vector(vector<Studentas>& studentai, const string& pav);

void rusiavimas2Vector(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai);
void isvedimasVVector(const string& failas_vargsiukai, const vector<Studentas>& vargsiukai);
void isvedimasKVector(const string& failas_kietiakai, const vector<Studentas>& kietiakai);

void generavimoLVector(vector<Studentas>& studentai, int skaicius, const string& failas);
void skaitymoLVector(vector<Studentas>& studentai, int skaicius, const string& failas);
void rusiavimoLVector(vector<Studentas>& studentai, int skaicius, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai);
void isvedimoVLVector(const string& failas_vargsiukai, int skaicius, const vector<Studentas>& vargsiukai);
void isvedimoKLVector(const string& failas_kietiakai, int skaicius, const vector<Studentas>& kietiakai);

void testavimasv(const string& failoPav, int skaicius, const string& kietiakaiF, const string& vargsiukaiF);

//list

void generavimasList(list<Studentas2>& studentai2, int count, const string& failas);
void saugojimasList(const string& failas, const list<Studentas2>& studentai2);
void skaityti2List(list<Studentas2>& studentai2, const string& pav);

void rusiavimas2List(const list<Studentas2>& studentai2, list<Studentas2>& vargsiukai, list<Studentas2>& kietiakai);
void isvedimasVList(const string& failas_vargsiukai, const list<Studentas2>& vargsiukai);
void isvedimasKList(const string& failas_kietiakai, const list<Studentas2>& kietiakai);

void generavimoLList(list<Studentas2>& studentai2, int skaicius, const string& failas);
void skaitymoLList(list<Studentas2>& studentai2, int skaicius, const string& failas);
void rusiavimoLList(list<Studentas2>& studentai2, int skaicius, list<Studentas2>& vargsiukai, list<Studentas2>& kietiakai);
void isvedimoVLList(const string& failas_vargsiukai, int skaicius, const list<Studentas2>& vargsiukai);
void isvedimoKLList(const string& failas_kietiakai, int skaicius, const list<Studentas2>& kietiakai);

void testavimasl(const string& failoPav, int skaicius, const string& kietiakaiF, const string& vargsiukaiF);
#endif
