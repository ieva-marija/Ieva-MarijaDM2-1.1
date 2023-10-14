#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>
#include "mylib.h"
#include "mylib2.h"
#include <fstream>

using namespace std;

void testavimas(const string& failoPav, int skaicius, const string& kietiakaiF, const string& vargsiukaiF) {
    vector<Studentas> studentai;
    vector<Studentas> vargsiukai;
    vector<Studentas> kietiakai;
    vector<double> skaitymoLaikai;
    vector<double> rusiavimoLaikai;
    vector<double> isvedimoVLaikai;
    vector<double> isvedimoKLaikai;

    int kartai = 5;
    for (int i = 0; i < kartai; i++) {
        auto startSk = std::chrono::high_resolution_clock::now();
        skaitymoL(studentai, skaicius, failoPav);
        auto endSk = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationSk = endSk - startSk;
        skaitymoLaikai.push_back(durationSk.count());

        rusiavimas(studentai);

        auto startRus = std::chrono::high_resolution_clock::now();
        rusiavimoL(studentai, skaicius, vargsiukai, kietiakai);
        auto endRus = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationRus = endRus - startRus;
        rusiavimoLaikai.push_back(durationRus.count());

        auto startIsVL = std::chrono::high_resolution_clock::now();
        isvedimoVL(vargsiukaiF, skaicius, vargsiukai);
        auto endIsVL = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationIsVL = endIsVL - startIsVL;
        isvedimoVLaikai.push_back(durationIsVL.count());

        auto startIsKL = std::chrono::high_resolution_clock::now();
        isvedimoKL(kietiakaiF, skaicius, kietiakai);
        auto endIsKL = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> durationIsKL = endIsKL - startIsKL;
        isvedimoKLaikai.push_back(durationIsKL.count());
        studentai.clear();
    }

    double vidSL = std::accumulate(skaitymoLaikai.begin(), skaitymoLaikai.end(), 0.0) / skaitymoLaikai.size();
    double vidRL = std::accumulate(rusiavimoLaikai.begin(), rusiavimoLaikai.end(), 0.0) / rusiavimoLaikai.size();
    double vidIVL = std::accumulate(isvedimoVLaikai.begin(), isvedimoVLaikai.end(), 0.0) / isvedimoVLaikai.size();
    double vidIKL = std::accumulate(isvedimoKLaikai.begin(), isvedimoKLaikai.end(), 0.0) / isvedimoKLaikai.size();

    cout << skaicius << " irasu skaitymas vidutiniskai uztruko: " << vidSL << endl;
    cout << skaicius << " irasu rusiavimas vidutiniskai uztruko: " << vidRL << endl;
    cout << skaicius << " irasu vargsiuku isvedimas vidutiniskai uztruko: " << vidIVL << endl;
    cout << skaicius << " irasu kietiaku isvedimas vidutiniskai uztruko: " << vidIKL << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
}
