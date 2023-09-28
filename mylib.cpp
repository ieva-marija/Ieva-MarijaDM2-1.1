#include "mylib.h"

Studentas ivesk()
{
  Studentas temp;
  cout << "Iveskite varda: ";
  cin >> temp.vardas;
  cout << "Iveskite pavarde: ";
  cin >> temp.pavarde;
  cout << "Iveskite pazymiu kieki: ";
    int n;
    cin >> n;
    temp.vidurkis = 0;
    for (int i = 0; i < n; i++) {
        int pazymys;
        cout << "Iveskite pazymi: ";
        cin >> pazymys;
        temp.pazymiai.push_back(pazymys);
        temp.vidurkis += pazymys;
    }
    if (n > 0) {
        temp.vidurkis = static_cast<float>(temp.vidurkis) / n;
    }
  sort(temp.pazymiai.begin(), temp.pazymiai.end());
    if (n % 2 == 0) {
        int vidurys = n / 2;
        temp.mediana = static_cast<float>(temp.pazymiai[vidurys - 1] + temp.pazymiai[vidurys]) / 2;
    } else {
        temp.mediana = static_cast<float>(temp.pazymiai[n / 2]);
    }
  cout << "Iveskite egzamino pazymi: ";
  cin >> temp.egzaminas;
  
  return temp;
}
