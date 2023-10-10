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
    saugojimas(failas, studentai);
}

void saugojimas(const string& failas, const vector<Studentas>& studentai)
{
    ofstream F(failas);
    if (!F) {
        cerr << "Nepavyko atidaryti failo " << failas << endl;
        return;
    }

    F << "Vardas Pavarde";
    for (int i = 1; i <= 15; i++) {
        F << " ND" << i;
    }
    F << " Egzaminas" << endl;

    for (const Studentas& studentas : studentai) {
        F << studentas.vardas << " " << studentas.pavarde;
        for (int pazymys : studentas.pazymiai) {
            F << " " << pazymys;
        }
        F << "  " << studentas.egzaminas << endl;
    }

    F.close();
}
