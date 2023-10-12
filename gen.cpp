#include "mylib.h"
#include "mylib2.h"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>

using namespace std;

void generavimas(vector<Studentas>& studentai, int count, const string& failas)
{
    studentai.clear();
    for (int i = 1; i < count +1; i++) {
        Studentas studentas;
        studentas.vardas = "Vardas" + to_string(i);
        studentas.pavarde = "Pavarde" + to_string(i);
        for (int j = 0; j < 15; j++) {
            studentas.pazymiai.push_back(rand() % 10 + 1);
        }
        studentas.egzaminas = rand() % 10 + 1;
        studentas.rezultatasv = galutinisVid(studentas);
        studentas.rezultatasm = galutinisMed(studentas);
        studentai.push_back(studentas);
    }
    saugojimas(failas, studentai);
    rusiavimas(studentai);
}

void saugojimas(const string& failas, const vector<Studentas>& studentai)
{
    ofstream F(failas);
    if (!F) {
        cerr << "Nepavyko atidaryti failo " << failas << endl;
        return;
    }

    F << left << setw(15) << "Vardas" << setw(15) << " Pavarde" << setw(15) << "Galutinis (Vid.) " << setw(15) << "Galutinis (Med.)" << endl;
    for (const Studentas& studentas : studentai) {
        F << setw(15) << studentas.vardas << " " << setw(15) << studentas.pavarde;
        F << " " << fixed << setprecision(2) << setw(16) << studentas.rezultatasv << " " << fixed << setprecision(2) << studentas.rezultatasm << endl;
    }
    F.close();
}

void skaityti2(vector<Studentas>& studentai, const string& pav) {
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
        Studentas studentas;
        iss >> studentas.vardas >> studentas.pavarde >> studentas.rezultatasv >> studentas.rezultatasm;
        studentai.push_back(studentas);
    }
    F.close();
   }
    catch (const exception& e) {
        cerr << "neperskaito...:" << e.what() << endl;
    }
};

void rusiavimas2(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai)
{
    for (const Studentas& studentas : studentai) {
        float galutinis = studentas.rezultatasv;

        if (galutinis < 5.0) {
            vargsiukai.push_back(studentas);
        } else if (galutinis >=5 && galutinis <= 10) {
            kietiakai.push_back(studentas);
        }
    }
}

void isvedimasV(const string& failas_vargsiukai, const vector<Studentas>& vargsiukai)
{
    saugojimas(failas_vargsiukai, vargsiukai);
}

void isvedimasK(const string& failas_kietiakai, const vector<Studentas>& kietiakai)
{
    saugojimas(failas_kietiakai, kietiakai);
}

void generavimoL(vector<Studentas>& studentai, int skaicius, const string& failas) {
    auto start = std::chrono::high_resolution_clock::now();
    generavimas(studentai, skaicius, failas);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << skaicius << " irasu failo generavimas uztruko: " << duration.count() << endl;
}

void skaitymoL(vector<Studentas>& studentai, int skaicius, const string& failas) {
    auto start = std::chrono::high_resolution_clock::now();
    skaityti2(studentai, failas);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << skaicius << " irasu failo skaitymas uztruko: " << duration.count() << endl;
}

void rusiavimoL(vector<Studentas>& studentai, int skaicius, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai) {
    auto start = std::chrono::high_resolution_clock::now();
    rusiavimas2(studentai, vargsiukai, kietiakai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << skaicius << " irasu rusiavimas uztruko: " << duration.count() << endl;
}

void isvedimoVL(const string& failas_vargsiukai, int skaicius, const vector<Studentas>& vargsiukai) {
    auto start = std::chrono::high_resolution_clock::now();
    isvedimasV(failas_vargsiukai, vargsiukai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << skaicius << " irasu vargsiuku isvedimas uztruko: " << duration.count() << endl;
}

void isvedimoKL(const string& failas_kietiakai, int skaicius, const vector<Studentas>& kietiakai) {
    auto start = std::chrono::high_resolution_clock::now();
    isvedimasK(failas_kietiakai, kietiakai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << skaicius << " irasu kietiaku isvedimas uztruko: " << duration.count() << endl;
}
