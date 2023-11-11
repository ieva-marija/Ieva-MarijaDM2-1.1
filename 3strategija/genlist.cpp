#include "mylib.h"
#include "mylib2.h"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>

using namespace std;

void generavimasList(list<Studentas2>& studentai2, int count, const string& failas)
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
    rusiavimasList(studentai2);
    saugojimasList(failas, studentai2);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rusiavimas2List(list<Studentas2>& studentai2, list<Studentas2>& vargsiukai)
{
    vargsiukai.clear();

    std::remove_copy_if(studentai2.begin(), studentai2.end(), std::back_inserter(vargsiukai), [](const Studentas2& studentas) {
        return studentas.rezultatasv >= 5;
    });

    studentai2.erase(std::remove_if(studentai2.begin(), studentai2.end(), [](const Studentas2& studentas) {
        return studentas.rezultatasv < 5;
    }), studentai2.end());
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void isvedimasVList(const string& failas_vargsiukai, const list<Studentas2>& vargsiukai)
{
    saugojimasList(failas_vargsiukai, vargsiukai);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void isvedimasKList(const string& failas_kietiakai, const list<Studentas2>& studentai2)
{
    saugojimasList(failas_kietiakai, studentai2);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void generavimoLList(list<Studentas2>& studentai2, int skaicius, const string& failas) {
    auto start = std::chrono::high_resolution_clock::now();
    generavimasList(studentai2, skaicius, failas);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << skaicius << " irasu failo generavimas uztruko: " << duration.count() << endl;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void skaitymoLList(list<Studentas2>& studentai2, int skaicius, const string& failas) {
    auto start = std::chrono::high_resolution_clock::now();
    skaityti2List(studentai2, failas);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void rusiavimoLList(list<Studentas2>& studentai2, int skaicius, list<Studentas2>& vargsiukai) {
    auto start = std::chrono::high_resolution_clock::now();
    rusiavimas2List(studentai2, vargsiukai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void isvedimoVLList(const string& failas_vargsiukai, int skaicius, const list<Studentas2>& vargsiukai) {
    auto start = std::chrono::high_resolution_clock::now();
    isvedimasVList(failas_vargsiukai, vargsiukai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void isvedimoKLList(const string& failas_kietiakai, int skaicius, const list<Studentas2>& studentai2) {
    auto start = std::chrono::high_resolution_clock::now();
    isvedimasKList(failas_kietiakai, studentai2);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}
