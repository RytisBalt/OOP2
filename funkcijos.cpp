#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>
#include  <algorithm>
#include "funkcijos.h"
using namespace std;

unsigned int zodziu_kiekis(string const& str) {
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
}

void skaitymas(vector<studentas>& kursas) {
    int skiekis = 0;
    int temp;
    ifstream file;
    string buff;
    studentas s;
    file.open("kursiokai.txt");
    try {
        if (!file.is_open())
        {
            throw 333;
        }
        cout << setw(25) << left << "Studento vardas" << setw(25) << left << "Pavarde" << setw(20) << left << "Galutinis(vidurkis)/ Galutinis(mediana)"
            << "--------------------------\n";
        getline(file >> ws, buff);
        int pkiekis = zodziu_kiekis(buff) - 3;
        while (true) {
            //kursas.resize(kursas.size() + 1);
            if (file.eof()) {
                kursas.pop_back();
                break;
            }
            file >> s.vardas;
            file >> s.pavarde;
            for (int i = 0; i < 15; ++i) {
                file >> temp;
                s.nd.push_back(temp);
            }
            file >> s.egz;
            kursas.push_back(s);
            s.nd.clear();
        }
    }
    catch (int x) {
        cout << "NEATIDARYTAS FAILAS, NEIMANOMA UZPILDYTI LENTELES. ERRORO NUMERIS: " << x << endl << endl;
    }
}
void spausdinimas(vector<studentas>& kursas) {

    for (int i = 0; i < kursas.size(); i++) {
        kursas[i].galutinisv = (vidurkis(kursas[i].nd) * 0.4) + (kursas[i].egz * 0.6);
        kursas[i].galutinism = (mediana(kursas[i].nd) * 0.4) + (kursas[i].egz * 0.6);
        cout << setw(25) << left << kursas[i].vardas << setw(25) << left << kursas[i].pavarde << setw(20) << left << kursas[i].galutinisv << kursas[i].galutinism << endl;
    }
}
float mediana(vector<int> nd) {
    typedef vector<int>::size_type ndSize;
    ndSize size = nd.size();
    sort(nd.begin(), nd.end());
    ndSize vid = size / 2;
    return size % 2 == 0 ? (nd[vid] + nd[vid - 1]) / 2 : nd[vid];
}
float vidurkis(vector<int> nd) {
    return accumulate(nd.begin(), nd.end(), 0.0) / nd.size();

}
