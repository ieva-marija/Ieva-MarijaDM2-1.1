#include "mylib.h"
#include "mylib2.h"
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

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
        studentai.push_back(studentas);
    }
    rusiavimas(studentai);
    saugojimas(failas, studentai);
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
        F << " " << fixed << setprecision(2) << setw(16) << galutinisVid(studentas) << " " << fixed << setprecision(2) << galutinisMed(studentas) << endl;
    }
    F.close();
}

void rusiavimas2(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai)
{
    for (const Studentas& studentas : studentai) {
        float galutinis = galutinisVid(studentas);
        if (galutinis < 5.0) {
            vargsiukai.push_back(studentas);
        } else if (galutinis >=5 && galutinis <= 10) {
            kietiakai.push_back(studentas);
        }
        else {
            throw runtime_error("kazkas su pazymiais negerai...");
        }
    }
}

void isvedimas(const string& failas_vargsiukai, const string& failas_kietiakai, const vector<Studentas>& vargsiukai, const vector<Studentas>& kietiakai)
{
    saugojimas(failas_vargsiukai, vargsiukai);
    saugojimas(failas_kietiakai, kietiakai);
}
