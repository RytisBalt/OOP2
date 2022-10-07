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

void skaitymas(vector<studentas>& kursas, int* pkiekis) {
    int skiekis = 0;
    int temp;
    ifstream file;
    string buff;
    file.open("kursiokai.txt");
    try {
        if (!file.is_open())
        {
            throw 333;
        }
        getline(file >> ws, buff);
        *pkiekis = zodziu_kiekis(buff) - 3;
        while (true) {
            kursas.resize(kursas.size() + 1);
            file >> kursas.at(skiekis).vardas;
            if (file.eof()) {
                kursas.pop_back();
                break;
            }
            file >> kursas.at(skiekis).pavarde;
            for (int i = 0; i < *pkiekis; ++i) {
                file >> temp;
                kursas.at(skiekis).nd.push_back(temp);
            }
            file >> kursas.at(skiekis).egz;
            kursas.at(skiekis).galutinis = kursas.at(skiekis).galutinis * 0.4 + 0.6 * kursas.at(skiekis).egz;
            skiekis++;
        }
    }
    catch (int x) {
        cout << "NEATIDARYTAS FAILAS, NEIMANOMA UZPILDYTI LENTELES. ERRORO NUMERIS: " << x << endl << endl;
    }
}
void spausdinimas(vector<studentas> kursas, int pkiekis) {

    cout << setw(25) << left << "Studento vardas" << setw(25) << left << "Pavarde" << setw(20) << left << "Galutinis(vidurkis)/ Galutinis(mediana)"
        << "--------------------------\n";
    for (int i = 0; i < kursas.size(); i++) {
        cout << setw(25) << left << kursas[i].vardas << setw(25) << left << kursas[i].pavarde << setw(20) << left << kursas[i].galutinis << mediana(kursas[i].nd) << endl;
    }
}
float mediana(vector<int> nd) {
    int counter = 0;
    for (int i = 0; i < 10; i++) {
        if (nd[i] != 0) {
            counter++;
        }
        if (nd[i] == -1) {
            nd[i] = 0;
            counter--;
            break;
        }
    }
    if (counter % 2 == 0) {
        return float(((nd[counter / 2 - 1]) + (nd[(counter / 2)])) / 2.0);
    }
    else {
        return float(nd[(counter / 2)]);
    }
}
