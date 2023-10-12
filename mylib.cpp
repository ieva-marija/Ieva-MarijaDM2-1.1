#include "mylib.h"
#include "mylib2.h"
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <limits>
#include <fstream>
#include <sstream>

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
        while (temp.egzaminas > 10) {
            cout << "MELAGIS. VESK IS NAUJO";
            cin >> temp.egzaminas;
        }
     }
     else {
        cout << "nu cia nei 5, nei 9........" << endl;
        return temp;
     }
     temp.rezultatasv=galutinisVid(temp);
     temp.rezultatasm=galutinisMed(temp);
  return temp;
};
//----------------------------------------------------------------
int rankinisFailinis(vector<Studentas>& studentai) {

    char pasirinkimas3;
    cout << "Pasirinkite, kaip norite ivesti duomenis:" << endl;
    cout << "R - Rankiniu budu" << endl;
    cout << "F - Nuskaityti is .txt failo" << endl;
    cin >> pasirinkimas3;

    if (pasirinkimas3 == 'R' || pasirinkimas3 == 'r')
    {
        int studentu_sk;
        cout << "Iveskite studentu skaiciu: ";
        cin >> studentu_sk;
        for (int i = 0; i < studentu_sk; i++) {
            cout << "Iveskite duomenis apie studenta:" << endl;
            studentai.push_back(ivesk());
        }
    }
    else if(pasirinkimas3 == 'F' || pasirinkimas3 == 'f')
    {
        string failoPavadinimas = "studentai10000.txt";
        skaityti(studentai, failoPavadinimas);
   }
    else
    {
        cout << "PASIRINK" << endl;
        return 1;
    }
    return 0;
};
//-----------------------------------------------------------------
void skaityti(vector<Studentas>& studentai, const string& pav) {
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
        if (iss >> studentas.vardas >> studentas.pavarde) {
            int pazymys;
            while (iss >> pazymys) {
                if (pazymys == -1) {
                    break;
                }
                studentas.pazymiai.push_back(pazymys);
            }
            if (studentas.pazymiai.size() > 0) {
                studentas.egzaminas = studentas.pazymiai.back();
                studentas.pazymiai.pop_back();
                studentas.rezultatasv = galutinisVid(studentas);
                studentas.rezultatasm = galutinisMed(studentas);
                studentai.push_back(studentas);
            } else {
                cout << "erroras!" << endl;
            }
        } else {
            cout << "daugiau studentu nebera" << endl;
        }
    }
    F.close();
   }
    catch (const exception& e) {
        cerr << "neperskaito...:" << e.what() << endl;
    }
};
//-------------------------------------------------------
float galutinisVid(const Studentas& studentas) {
    float vidurkis = 0;
    for (int pazymys : studentas.pazymiai) {
        vidurkis += pazymys;
    }
    vidurkis = static_cast<float>(vidurkis) / studentas.pazymiai.size();
    return 0.4 * vidurkis + 0.6 * studentas.egzaminas;
};

//--------------------------------------------------------
float galutinisMed(const Studentas& studentas) {
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
//----------------------------------------------------------
void rusiavimas(vector<Studentas>& studentai) {
    std::sort(studentai.begin(), studentai.end(), [](const Studentas& a, const Studentas& b) {
        return a.pavarde < b.pavarde;
    });
};
