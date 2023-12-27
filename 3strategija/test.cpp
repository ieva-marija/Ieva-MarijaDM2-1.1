#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include "mylib.h"
#include "mylib2.h"
#include <fstream>
#include <list>

using namespace std;

void testavimasv(const string& failoPav, const string& kietiakaiF, const string& vargsiukaiF, int skaiciux) {
    vector<Studentas> studentai;
    vector<Studentas> vargsiukai;
    vector<double> skaitymoLaikai;
    vector<double> rusiavimoLaikai;
    vector<double> isvedimoVLaikai;
    vector<double> isvedimoKLaikai;

    int kartai = 5;
    int skaicius;
    for (int i = 0; i < kartai; i++) {
        auto startSk = std::chrono::high_resolution_clock::now();
        skaitymoLVector(studentai, failoPav);
        auto endSk = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationSk = endSk - startSk;
        skaitymoLaikai.push_back(durationSk.count());

        auto startRus = std::chrono::high_resolution_clock::now();
        rusiavimoLVector(studentai, vargsiukai, skaiciux);
        auto endRus = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationRus = endRus - startRus;
        rusiavimoLaikai.push_back(durationRus.count());

        auto startIsVL = std::chrono::high_resolution_clock::now();
        isvedimoVLVector(vargsiukaiF, vargsiukai);
        auto endIsVL = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationIsVL = endIsVL - startIsVL;
        isvedimoVLaikai.push_back(durationIsVL.count());

        auto startIsKL = std::chrono::high_resolution_clock::now();
        isvedimoKLVector(kietiakaiF, studentai);
        auto endIsKL = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationIsKL = endIsKL - startIsKL;
        isvedimoKLaikai.push_back(durationIsKL.count());

        skaicius = (studentai.size() + vargsiukai.size());
        studentai.clear();
        vargsiukai.clear();
    }

    double vidSL = std::accumulate(skaitymoLaikai.begin(), skaitymoLaikai.end(), 0.0) / skaitymoLaikai.size();
    double vidRL = std::accumulate(rusiavimoLaikai.begin(), rusiavimoLaikai.end(), 0.0) / rusiavimoLaikai.size();
    double vidIVL = std::accumulate(isvedimoVLaikai.begin(), isvedimoVLaikai.end(), 0.0) / isvedimoVLaikai.size();
    double vidIKL = std::accumulate(isvedimoKLaikai.begin(), isvedimoKLaikai.end(), 0.0) / isvedimoKLaikai.size();

    cout << "Vector konteineriu: " << endl;
    cout << skaicius << " irasu skaitymas vidutiniskai uztruko: " << vidSL << endl;
    cout << skaicius << " irasu rusiavimas vidutiniskai uztruko: " << vidRL << endl;
    cout << skaicius << " irasu vargsiuku isvedimas vidutiniskai uztruko: " << vidIVL << endl;
    cout << skaicius << " irasu kietiaku isvedimas vidutiniskai uztruko: " << vidIKL << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
}
void testavimasl(const string& failoPav, const string& vargsiukaiF, const string& kietiakaiF, int skaiciux) {
    list<Studentas2> studentai2;
    list<Studentas2> vargsiukai;
    list<double> skaitymoLaikai;
    list<double> rusiavimoLaikai;
    list<double> isvedimoVLaikai;
    list<double> isvedimoKLaikai;

    int kartai = 5;
    int skaicius2;
    for (int i = 0; i < kartai; i++) {
        auto startSk = std::chrono::high_resolution_clock::now();
        skaitymoLList(studentai2, failoPav);
        auto endSk = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationSk = endSk - startSk;
        skaitymoLaikai.push_back(durationSk.count());

        auto startRus = std::chrono::high_resolution_clock::now();
        rusiavimoLList(studentai2, vargsiukai, skaiciux);
        auto endRus = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationRus = endRus - startRus;
        rusiavimoLaikai.push_back(durationRus.count());

        auto startIsVL = std::chrono::high_resolution_clock::now();
        isvedimoVLList(vargsiukaiF, vargsiukai);
        auto endIsVL = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationIsVL = endIsVL - startIsVL;
        isvedimoVLaikai.push_back(durationIsVL.count());

        auto startIsKL = std::chrono::high_resolution_clock::now();
        isvedimoKLList(kietiakaiF, studentai2);
        auto endIsKL = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationIsKL = endIsKL - startIsKL;
        isvedimoKLaikai.push_back(durationIsKL.count());

        skaicius2 = (studentai2.size() + vargsiukai.size());
        studentai2.clear();
        vargsiukai.clear();
    }

    double vidSL = std::accumulate(skaitymoLaikai.begin(), skaitymoLaikai.end(), 0.0) / skaitymoLaikai.size();
    double vidRL = std::accumulate(rusiavimoLaikai.begin(), rusiavimoLaikai.end(), 0.0) / rusiavimoLaikai.size();
    double vidIVL = std::accumulate(isvedimoVLaikai.begin(), isvedimoVLaikai.end(), 0.0) / isvedimoVLaikai.size();
    double vidIKL = std::accumulate(isvedimoKLaikai.begin(), isvedimoKLaikai.end(), 0.0) / isvedimoKLaikai.size();

    cout << "List konteineriu: " << endl;
    cout << skaicius2 << " irasu skaitymas vidutiniskai uztruko: " << vidSL << endl;
    cout << skaicius2 << " irasu rusiavimas vidutiniskai uztruko: " << vidRL << endl;
    cout << skaicius2 << " irasu vargsiuku isvedimas vidutiniskai uztruko: " << vidIVL << endl;
    cout << skaicius2 << " irasu kietiaku isvedimas vidutiniskai uztruko: " << vidIKL << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
}
