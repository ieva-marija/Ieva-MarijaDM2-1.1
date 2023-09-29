#include <iostream>
#include <iomanip>
#include "mylib.h"
#include <limits>

using namespace std;

int main()
{
    vector <Studentas> studentai;

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
        string pav = "kursiokai.txt";
        skaityti(studentai, pav);
    }
    else
    {
        cout << "PASIRINK" << endl;
        return 1;
    }

    int pasirinkimas;
    cout << "Pasirinkite, kaip skaiciuoti studento galutini bala:" << endl;
    cout << "Pagal vidurki - 1" << endl;
    cout << "Pagal mediana - 2" << endl;
    cin >> pasirinkimas;

    for (Studentas& studentas : studentai) {
        if (pasirinkimas == 1) {
            studentas.rezultatas = galutinisVid(studentas);
        } else if (pasirinkimas == 2) {
            studentas.rezultatas = galutinisMed(studentas);
        } else {
            cout << "you had one job !" << endl;
            return 1;
        }
    }

    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis balas";
    for (Studentas& studentas : studentai) {
        if (pasirinkimas == 1) {
            cout << "(Vid.)" << endl;
        }
        else if (pasirinkimas == 2) {
            cout << "(Med.)" << endl;
        }
    }
    cout << "---------------|---------------|-------" << endl;
    for (const Studentas& studentas : studentai) {
        cout << setw(15) << studentas.vardas << "|" << setw(15) << studentas.pavarde << "|" << fixed << setprecision(2) << setw(15) << studentas.rezultatas << endl;
    }
    return 0;
}
