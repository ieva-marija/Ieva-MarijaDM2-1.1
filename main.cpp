#include <iostream>
#include <iomanip>
#include "mylib.h"
#include "mylib2.h"
#include <limits>

using namespace std;

int main()
{
    vector <Studentas> studentai;
    
    rankinisFailinis(studentai);
        
    rusiavimas(studentai);
    
    cout << left << setw(15) << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis (Vid.) " << setw(15) << "Galutinis (Med.)" << endl;
    cout << "----------------------------------------------------------------" << endl;

    for (const Studentas& studentas : studentai) {
            cout << setw(15) << studentas.vardas << setw(15) << studentas.pavarde
                 << fixed << setprecision(2) << setw(16) << studentas.rezultatasv << " " << fixed << setprecision(2) << setw(15) << studentas.rezultatasm << endl;
    }
    return 0;
}
