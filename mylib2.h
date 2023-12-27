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
void rusiavimasVector2(vector<Studentas>& studentai);
void rusiavimasVector3(vector<Studentas>& studentai);
void rusiavimasList(list<Studentas2>& studentai);
void rusiavimasList2(list<Studentas2>& studentai2);
void rusiavimasList3(list<Studentas2>& studentai2);
int rankinisFailinis(vector<Studentas>& studentai);

void generavimasVector(vector<Studentas>& studentai, int count, const string& failas, const string& failas0, int skaicius);
void saugojimas0Vector(const string& failas0, const vector<Studentas>& pradinis);
void saugojimasVector(const string& failas, const vector<Studentas>& studentai);
void skaityti2Vector(vector<Studentas>& studentai, const string& pav);

void rusiavimas2Vector(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai, int skaiciux);
void isvedimasVVector(const string& failas_vargsiukai, const vector<Studentas>& vargsiukai);
void isvedimasKVector(const string& failas_kietiakai, const vector<Studentas>& kietiakai);

void generavimoLVector(vector<Studentas>& studentai, int skaicius, const string& failas, const string& failas0, int sk);
void skaitymoLVector(vector<Studentas>& studentai, const string& failas);
void rusiavimoLVector(vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai, int skaiciux);
void isvedimoVLVector(const string& failas_vargsiukai, const vector<Studentas>& vargsiukai);
void isvedimoKLVector(const string& failas_kietiakai, const vector<Studentas>& kietiakai);

void testavimasv(const string& failoPav, const string& kietiakaiF, const string& vargsiukaiF, int skaiciux);

//list

void generavimasList(list<Studentas2>& studentai2, int count, const string& failas, int skaicius);
void saugojimas0List(const string& failas0, const list<Studentas2>& pradinis);
void saugojimasList(const string& failas, const list<Studentas2>& studentai2);
void skaityti2List(list<Studentas2>& studentai2, const string& pav);

void rusiavimas2List(const list<Studentas2>& studentai2, list<Studentas2>& vargsiukai, list<Studentas2>& kietiakai, int skaiciux);
void isvedimasVList(const string& failas_vargsiukai, const list<Studentas2>& vargsiukai);
void isvedimasKList(const string& failas_kietiakai, const list<Studentas2>& kietiakai);

void generavimoLList(list<Studentas2>& studentai2, int skaicius, const string& failas, const string& failas0, int sk);
void skaitymoLList(list<Studentas2>& studentai2, const string& failas);
void rusiavimoLList(list<Studentas2>& studentai2, list<Studentas2>& vargsiukai, list<Studentas2>& kietiakai, int skaiciux);
void isvedimoVLList(const string& failas_vargsiukai, const list<Studentas2>& vargsiukai);
void isvedimoKLList(const string& failas_kietiakai, const list<Studentas2>& kietiakai);

void testavimasl(const string& failoPav, const string& kietiakaiF, const string& vargsiukaiF, int skaiciux);
#endif
