#include "mylib.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <limits>

using namespace std;

Studentas ivesk()
{
  Studentas temp;
  cout << "Iveskite varda: ";
  cin >> temp.vardas;
  cout << "Iveskite pavarde: ";
  cin >> temp.pavarde;

 int pazymys;
  int pasirinkimas2;
  cout << "Ar norite, kad programa studento pazymius ir egzamino rezultata generuotu atsitiktinai?" << endl;
  cout << "5 - taip, noriu, aciu" << endl;
  cout << "9 - ne, noriu ivesti savarankiskai" << endl;
    cin >> pasirinkimas2;

    if (pasirinkimas2 == 5) {
        srand(time(0));
        int a_pazymiai_sk = rand() % 11;
        cout << "Sugeneruoti atsitiktinai pazymiai: ";
        for (int i = 0; i < a_pazymiai_sk; ++i) {
            int a_pazymys = rand() % 11 + 1;
            temp.pazymiai.push_back(a_pazymys);
            cout << a_pazymys << " ";
        }

        srand(time(0));
        temp.egzaminas = rand() % 10 + 1;
        cout << "Sugeneruotas egzamino pazymys: "<< temp.egzaminas << endl;
        cout << "\n";
    }
     else if (pasirinkimas2 == 9) {
       while (true) {
            cout << "Iveskite namu darbu rezultatus (iveskite -1, kai suvedete visus norimus pazymius): ";
            if (cin >> pazymys) {
                if (pazymys == -1) {
                    cin.clear();
                    cin.ignore(256, '\n');
                    break;
                }
                if (pazymys >= 0 && pazymys <= 10) {
                    temp.pazymiai.push_back(pazymys);
                }
                else {
                    cout << "??????????" << endl;
                    }
            }
            else {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "????????????" << endl;
                }
       }
       cout << "Iveskite egzamino pazymi: ";
        cin >> temp.egzaminas;
     }
     else {
        cout << "nu cia nei 5, nei 9........" << endl;
        return temp;
     }
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
