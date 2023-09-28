#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::string;
using std::vector;

Studentas ivesk();

struct Studentas {
    std::string vardas, pavarde;
    std::vector<int> pazymiai;
    int egzaminas;
    float vidurkis, mediana, rezultatas;
};

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
  cout << "Iveskite egzamino pazymi: ";
  cin >> temp.egzaminas;
  return temp;
}
