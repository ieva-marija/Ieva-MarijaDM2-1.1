#include "mylib.h"
#include "mylib2.h"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <chrono>

using namespace std;

void generavimasVector(vector<Studentas>& studentai, int count, const string& failas)
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
        studentas.rezultatasv = galutinisVidVector(studentas);
        studentas.rezultatasm = galutinisMedVector(studentas);
        studentai.push_back(studentas);
    }
    saugojimasVector(failas, studentai);
    rusiavimasVector(studentai);
}

void saugojimasVector(const string& failas, const vector<Studentas>& studentai)
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

void skaityti2Vector(vector<Studentas>& studentai, const string& pav) {
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

void rusiavimas2Vector(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai)
{
    kietiakai.clear();
    vargsiukai.clear();
    for (const Studentas& studentas : studentai) {
        float galutinis = studentas.rezultatasv;

        if (galutinis < 5.0) {
            vargsiukai.push_back(studentas);
        } else if (galutinis >=5 && galutinis <= 10) {
            kietiakai.push_back(studentas);
        }
    }
}

void isvedimasVVector(const string& failas_vargsiukai, const vector<Studentas>& vargsiukai)
{
    saugojimasVector(failas_vargsiukai, vargsiukai);
}

void isvedimasKVector(const string& failas_kietiakai, const vector<Studentas>& kietiakai)
{
    saugojimasVector(failas_kietiakai, kietiakai);
}

void generavimoLVector(vector<Studentas>& studentai, int skaicius, const string& failas) {
    auto start = std::chrono::high_resolution_clock::now();
    generavimasVector(studentai, skaicius, failas);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    cout << skaicius << " irasu failo generavimas uztruko: " << duration.count() << endl;
}

void skaitymoLVector(vector<Studentas>& studentai, int skaicius, const string& failas) {
    auto start = std::chrono::high_resolution_clock::now();
    skaityti2Vector(studentai, failas);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}

void rusiavimoLVector(vector<Studentas>& studentai, int skaicius, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai) {
    auto start = std::chrono::high_resolution_clock::now();
    rusiavimas2Vector(studentai, vargsiukai, kietiakai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}

void isvedimoVLVector(const string& failas_vargsiukai, int skaicius, const vector<Studentas>& vargsiukai) {
    auto start = std::chrono::high_resolution_clock::now();
    isvedimasVVector(failas_vargsiukai, vargsiukai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}

void isvedimoKLVector(const string& failas_kietiakai, int skaicius, const vector<Studentas>& kietiakai) {
    auto start = std::chrono::high_resolution_clock::now();
    isvedimasKVector(failas_kietiakai, kietiakai);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
}
