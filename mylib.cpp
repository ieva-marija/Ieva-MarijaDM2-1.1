#include "mylib.h"
#include <algorithm>

Studentas ivesk()
{
  Studentas temp;
  cout << "Įveskite vardą: ";
  cin >> temp.vardas;
  cout << "Įveskite pavardę: ";
  cin >> temp.pavarde;
  cout << "Įveskite pažymių kiekį: ";
  int n;
  cin >> n;
  temp.vidurkis=0;
  for(int i=0; i<n; i++)
    {
      int pazymys;
      cout << "Iveskite pazymi: ";
      cin >> pazymys;
      temp.pazymiai.push_back(pazymys);
      temp.vidurkis+=pazymys;
    }
  if (n>0)
  {
      temp.vidurkis=static_cast<float>(temp.vidurkis/n);
  }
  sort(temp.pazymiai.begin(), temp.pazymiai.end());
    if (n % 2 == 0) {
        int vidurys = n / 2;
        temp.mediana = static_cast<float>(temp.pazymiai[vidurys - 1] + temp.pazymiai[vidurys]) / 2;
    } else {
        temp.mediana = static_cast<float>(temp.pazymiai[n / 2]);
    }
  cout << "Įveskite egzamino pažymį: ";
  cin >> temp.egzaminas;
  return temp;
};

float galutinisVid(const Studentas& studentas) {
    float vidurkis = studentas.vidurkis;
    return 0.4 * vidurkis + 0.6 * studentas.egzaminas;
};

float galutinisMed(const Studentas& studentas) {
    float mediana = studentas.mediana;
    return 0.4 * mediana + 0.6 * studentas.egzaminas;
};
