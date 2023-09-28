#include <iostream>
#include <iomanip>
#include "mylib.h"

using namespace std;

int main()
{
    Studentas A;
    A = ivesk();
 
    cout << "Studento duomenys:" << endl;
    cout << "Vardas: " << A.vardas 
    cout << "Pavarde: " << A.pavarde << endl;
    cout << "Galutinis balas: " << fixed << setprecision(2) << A.rezultatas << endl;

    return 0;
}
