#include <iostream>
#include <iomanip>
#include "mylib.h"

using namespace std;

int main()
{
    int studentu_sk;
    cout << "Iveskite studentu skaiciu: ";
    cin >> studentu_sk;
    vector <Studentas> studentai;

    int pasirinkimas;
    cout << "Pasirinkite, kaip skaiciuoti studento galutini bala:" << endl;
    cout << "Pagal vidurki - 1" << endl;
    cout << "Pagal mediana - 2" << endl;
    cin >> pasirinkimas;

    for (int i = 0; i < studentu_sk; i++) {
        cout << "Iveskite duomenis apie studenta:" << endl;
        studentai.push_back(ivesk());
    }

    for (Studentas& studentas : studentai) {
        if (pasirinkimas == 1) {
            studentas.rezultatas = galutinisVid(studentas);
        } else if (pasirinkimas == 2) {
            studentas.rezultatas = galutinisMed(studentas);
        } else {
            cout << "you had one job !" << endl;
            return 0;
        }
    }

    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis balas" << endl;
    cout << "---------------|---------------|-------" << endl;
    for (const Studentas& studentas : studentai) {
        cout << setw(15) << studentas.vardas << "|" << setw(15) << studentas.pavarde << "|" << fixed << setprecision(2) << setw(15) << studentas.rezultatas << endl;
    }
    return 0;
}
