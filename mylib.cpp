#include "mylib.h"
#include <algorithm>

Studentas ivesk()
{
  Studentas temp;
  cout << "Įveskite vardą: ";
  cin >> temp.vardas;
  cout << "Įveskite pavardę: ";
  cin >> temp.pavarde;
  cout << "Iveskite namu darbu rezultatus (iveskite -1, kai suvedete visus norimus pazymius): ";
    int pazymys;
    while (cin >> pazymys) {
            if (pazymys == -1) {
            cin.clear();
            cin.ignore(256, '\n');
            break;
        }
        temp.pazymiai.push_back(pazymys);
    }
  cout << "Įveskite egzamino pažymį: ";
  cin >> temp.egzaminas;
  return temp;
};

float galutinisVid(const Studentas& studentas) {
    float vidurkis = 0;
    for (int pazymys : studentas.pazymiai) {
        vidurkis += pazymys;
    }
    if (!studentas.pazymiai.empty()) {
        vidurkis = static_cast<float>(vidurkis) / studentas.pazymiai.size();
    }
    return 0.4 * vidurkis + 0.6 * studentas.egzaminas;
};

float galutinisMed(const Studentas& studentas) {
    if (studentas.pazymiai.empty()) {
        return 0.4 * 0 + 0.6 * studentas.egzaminas;
    }
    vector<int> pazymiai = studentas.pazymiai;
    sort(pazymiai.begin(), pazymiai.end());
    if (pazymiai.size() % 2 == 0) {
        int vidurys = pazymiai.size() / 2;
        float mediana = static_cast<float>(pazymiai[vidurys - 1] + pazymiai[vidurys]) / 2;
        return 0.4 * mediana + 0.6 * studentas.egzaminas;
    } else {
        float mediana = static_cast<float>(pazymiai[pazymiai.size() / 2]);
        return 0.4 * mediana + 0.6 * studentas.egzaminas;
    }
};
