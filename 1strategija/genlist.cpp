#include "mylib.h"
#include "mylib2.h"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>

using namespace std;

void generavimasList(list<Studentas2>& studentai2, int count, const string& failas, const string& failas0, int skaicius)
{
    studentai2.clear();
    for (int i = 1; i < count +1; i++) {
        Studentas2 studentas;
        studentas.vardas = "Vardas" + to_string(i);
        studentas.pavarde = "Pavarde" + to_string(i);
        for (int j = 0; j < 15; j++) {
            studentas.pazymiai.push_back(rand() % 10 + 1);
        }
        studentas.egzaminas = rand() % 10 + 1;
        studentas.rezultatasv = galutinisVidList(studentas);
        studentas.rezultatasm = galutinisMedList(studentas);
        studentai2.push_back(studentas);
    }
    list<Studentas2> pradinis = studentai2;
    saugojimas0List(failas0, pradinis);
    if(skaicius==0){
        rusiavimasList2(studentai2);
    }
    else if(skaicius==1){
        rusiavimasList(studentai2);
    }
    else if (skaicius==2){
        rusiavimasList3(studentai2);
    }
    saugojimasList(failas, studentai2);
}
//--------------------------------------------------------------------------------------
void saugojimas0List(const string& failas0, const list<Studentas2>& pradinis)
{
    ofstream F(failas0);
    if (!F) {
        cerr << "Nepavyko atidaryti failo " << failas0 << endl;
        return;
    }
    int maxNumND = 0;
    for (const Studentas2& studentas : pradinis) {
        maxNumND = max(maxNumND, static_cast<int>(studentas.pazymiai.size()));
    }
    F << left << setw(15) << "Vardas" << setw(17) << " Pavarde";
    for(int i=0; i<maxNumND; i++){
        F << setw(10) <<  "Nd." + to_string(i);
    }
    F << setw(15) << "Egzaminas " << endl;
    for (const Studentas2& studentas : pradinis) {
        F << setw(15) << studentas.vardas << " " << setw(17) << studentas.pavarde;
        for(auto it = studentas.pazymiai.begin(); it != studentas.pazymiai.end(); ++it){
            F << setw(10) << *it;
        }
        F << studentas.egzaminas <<  endl;
    }
    F.close();
}
//------------------------------------------------------------------------------
void saugojimasList(const string& failas, const list<Studentas2>& studentai2)
{
    ofstream F(failas);
    if (!F) {
        cerr << "Nepavyko atidaryti failo " << failas << endl;
        return;
    }
    F << left << setw(15) << "Vardas" << setw(15) << " Pavarde" << setw(15) << "Galutinis (Vid.) " << setw(15) << "Galutinis (Med.)" << endl;
    for (const Studentas2& studentas : studentai2) {
        F << setw(15) << studentas.vardas << " " << setw(15) << studentas.pavarde;
        F << " " << fixed << setprecision(2) << setw(16) << studentas.rezultatasv << " " << fixed << setprecision(2) << studentas.rezultatasm << endl;
    }
    F.close();
}
//-------------------------------------------------------------------------------------
void skaityti2List(list<Studentas2>& studentai2, const string& pav) {
    ifstream F(pav);

   try {
   if (!F) {
        throw runtime_error("nera tokio failo: " + pav);
    }
    string line;
    bool firstLine = true;
    while (getline(F, line)) {
        if (firstLine) {
            firstLine = false;
            continue;
        }
        istringstream iss(line);
        Studentas2 studentas;
        iss >> studentas.vardas >> studentas.pavarde >> studentas.rezultatasv >> studentas.rezultatasm;
        studentai2.push_back(studentas);
    }
    F.close();
   }
    catch (const exception& e) {
        cerr << "neperskaito...:" << e.what() << endl;
    }
};
//--------------------------------------------------------------------------------------------------
void rusiavimas2List(const list<Studentas2>& studentai2, list<Studentas2>& vargsiukai, list<Studentas2>& kietiakai, int skaiciux)
{
    kietiakai.clear();
    vargsiukai.clear();
    for (const Studentas2& studentas : studentai2) {
        float galutinis = studentas.rezultatasv;

        if (galutinis < 5.0) {
            vargsiukai.push_back(studentas);
        } else if (galutinis >=5 && galutinis <= 10) {
            kietiakai.push_back(studentas);
        }
    }
    if(skaiciux==0){
        rusiavimasList2(vargsiukai);
        rusiavimasList2(kietiakai);
    }
    else if(skaiciux==1){
        rusiavimasList(vargsiukai);
        rusiavimasList(kietiakai);
    }
    else if(skaiciux==2){
        rusiavimasList3(vargsiukai);
        rusiavimasList3(kietiakai);
    }
}
//-----------------------------------------------------------------------------------------------------------------------
void isvedimasVList(const string& failas_vargsiukai, const list<Studentas2>& vargsiukai)
{
    saugojimasList(failas_vargsiukai, vargsiukai);
}
//-----------------------------------------------------------------------------------------------------------------------
void isvedimasKList(const string& failas_kietiakai, const list<Studentas2>& kietiakai)
{
    saugojimasList(failas_kietiakai, kietiakai);
}
//-----------------------------------------------------------------------------------------------------------------------
void generavimoLList(list<Studentas2>& studentai2, int skaicius, const string& failas, const string& failas0, int sk) {
    auto start = std::chrono::high_resolution_clock::now();
    generavimasList(studentai2, skaicius, failas, failas0, sk);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << skaicius << " irasu failo generavimas uztruko: " << duration.count() << endl;
}
//-----------------------------------------------------------------------------------------------------------------------
void skaitymoLList(list<Studentas2>& studentai2, const string& failas) {
    auto start = std::chrono::high_resolution_clock::now();
    skaityti2List(studentai2, failas);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}
//-----------------------------------------------------------------------------------------------------------------------
void rusiavimoLList(list<Studentas2>& studentai2, list<Studentas2>& vargsiukai, list<Studentas2>& kietiakai, int skaiciux) {
    auto start = std::chrono::high_resolution_clock::now();
    rusiavimas2List(studentai2, vargsiukai, kietiakai, skaiciux);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}
//-----------------------------------------------------------------------------------------------------------------------
void isvedimoVLList(const string& failas_vargsiukai, const list<Studentas2>& vargsiukai) {
    auto start = std::chrono::high_resolution_clock::now();
    isvedimasVList(failas_vargsiukai, vargsiukai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}
//-----------------------------------------------------------------------------------------------------------------------
void isvedimoKLList(const string& failas_kietiakai, const list<Studentas2>& kietiakai) {
    auto start = std::chrono::high_resolution_clock::now();
    isvedimasKList(failas_kietiakai, kietiakai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}
