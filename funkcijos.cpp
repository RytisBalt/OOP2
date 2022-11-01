#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>
#include  <algorithm>
#include "funkcijos.h"
#include <random>
#include <chrono>
#include <ctime>
#include <list>
using namespace std;

/*unsigned int zodziu_kiekis(string const& str) {
    stringstream stream(str);
    return distance(istream_iterator<string>(stream), istream_iterator<string>());
} */

void skaitymas(vector<studentas>& kursas, int& skiekis, int& pkiekis) {
    auto start = chrono::high_resolution_clock::now();
    int temp;
    ifstream file;
    string buff;
    studentas s;
    string pavadinimas = "Studentai" + to_string(skiekis) + ".txt";
    file.open(pavadinimas);
    try {
        if (!file.is_open())
        {
            throw 333;
        }
        //cout << setw(25) << left << "Studento vardas" << setw(25) << left << "Pavarde" << setw(20) << left << "Galutinis(vidurkis)/ Galutinis(mediana)"
        //    << "--------------------------\n";
        for (int i = 0; i < skiekis; i++)
        {
            file >> s.vardas >> s.pavarde;
            for (int i = 0; i < pkiekis; i++)
            {
                file >> temp;
                s.nd.push_back(temp);
            }
            file >> s.egz;
            kursas.push_back(s);
            s.nd.clear();
        }
    }
    catch (int x) {
        cout << "NEATIDARYTAS FAILAS. ERRORO NUMERIS: " << x << endl << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << skiekis << " Elementu nuskaitymas uztruko: " << diff.count() << " s\n";
}
void skaitymasl(list<studentas>& kursas, int& skiekis, int& pkiekis) {

    auto start = chrono::high_resolution_clock::now();
    ifstream file;

    studentas s;
    string pavadinimas = "Studentai" + to_string(skiekis) + ".txt";
    file.open(pavadinimas);
    try {
        if (!file.is_open())
        {
            throw 333;
        }
        //cout << setw(25) << left << "Studento vardas" << setw(25) << left << "Pavarde" << setw(20) << left << "Galutinis(vidurkis)/ Galutinis(mediana)"
        //    << "--------------------------\n";
        for (int i = 0; i < skiekis; i++)
        {
            int temp;
            file >> s.vardas >> s.pavarde;
            for (int i = 0; i < pkiekis; i++)
            {
                file >> temp;
                s.nd.push_back(temp);
            }
            file >> s.egz;
            kursas.push_back(s);
            s.nd.clear();
        }
    }
    catch (int x) {
        cout << "NEATIDARYTAS FAILAS. ERRORO NUMERIS: " << x << endl << endl;
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << skiekis << " Elementu nuskaitymas uztruko: " << diff.count() << " s\n";
}


/*float mediana(vector<int> nd) {
    typedef vector<int>::size_type ndSize;
    ndSize size = nd.size();
    sort(nd.begin(), nd.end());
    ndSize vid = size / 2;
    return size % 2 == 0 ? (nd[vid] + nd[vid - 1]) / 2 : nd[vid];
}*/
float vidurkis(vector<int> nd) {
    return accumulate(nd.begin(), nd.end(), 0.0) / nd.size();

}
void kurimas(int& skiekis, int& pkiekis) {

    string pavadinimas = "Studentai" + to_string(skiekis) + ".txt";

    ofstream rf(pavadinimas);
    for (int i = 0; i < skiekis; i++) {
        rf << "Vardas" + to_string(i + 1) << " " << "Pavarde" + to_string(i + 1) << " ";
        for (int j = 0; j < pkiekis + 1; j++) {
            rf << rand() % 10 + 1 << " ";
        }
        rf << endl;
    }
    rf.close();

}
void suskirstymas(vector<studentas>& kursas, int& skiekis)
{
    auto start = chrono::high_resolution_clock::now();

    vector<studentas> geresni;
    vector<studentas> blogesni;

    for (int i = 0; i < kursas.size(); i++) {
        kursas[i].galutinisv = (vidurkis(kursas[i].nd) * 0.4) + (kursas[i].egz * 0.6);
        if (kursas[i].galutinisv < 5)
        {
            blogesni.push_back(kursas[i]);

        }
        else
        {
            geresni.push_back(kursas[i]);
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << skiekis << " Elementu suskirstymas i blogesnius ir geresnius uztruko: " << diff.count() << " s\n";
}
void suskirstymasl(list<studentas>& kursas, int& skiekis)
{
    auto start = chrono::high_resolution_clock::now();

    list<studentas> geresni;
    list<studentas> blogesni;

    for (studentas st : kursas) {
        st.galutinisv = (vidurkis(st.nd) * 0.4) + (st.egz * 0.6);
        if (st.galutinisv < 5)
        {
            blogesni.push_back(st);

        }
        else
        {
            geresni.push_back(st);
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << skiekis << " Elementu suskirstymas i blogesnius ir geresnius uztruko: " << diff.count() << " s\n";
}
void spausdinimasblogu(vector<studentas>& kursas, int& skiekis) {
    auto start = chrono::high_resolution_clock::now();
    string pavadinimas = "Blogesni" + to_string(skiekis) + ".txt";
    ofstream blog(pavadinimas);
    for (int i = 0; i < skiekis; i++) {
        if (kursas[i].galutinisv < 5)
        {
            blog << kursas[i].vardas << " " << kursas[i].pavarde << "     " << kursas[i].galutinisv << endl;
        }
    }
    blog.close();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << skiekis << " Elementu spausdinimas i blogesnius uztruko: " << diff.count() << " s\n";
}
void spausdinimasgeru(vector<studentas>& kursas, int& skiekis) {
    auto start = chrono::high_resolution_clock::now();
    string pavadinimas = "Geresni" + to_string(skiekis) + ".txt";
    ofstream ger(pavadinimas);
    for (int i = 0; i < skiekis; i++) {
        if (kursas[i].galutinisv >= 5)
        {
            ger << kursas[i].vardas << " " << kursas[i].pavarde << "     " << kursas[i].galutinisv << endl;
        }
    }
    ger.close();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << skiekis << " Elementu spausdinimas i geresnius uztruko: " << diff.count() << " s\n";
}
void rusiavimas(vector<studentas>& kursas, int& skiekis)
{
    auto start = chrono::high_resolution_clock::now();
    sort(kursas.begin(), kursas.end(), [](studentas a, studentas b)
        {
            return a.vardas < b.vardas;
        });
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> diff = end - start;
    cout << skiekis << " Elementu surusiavimas uztruko : " << diff.count() << " s\n";

}
void analize(int skiekis, int pkiekis, vector<studentas>& kursas) {


    kurimas(skiekis, pkiekis);
    skaitymas(kursas, skiekis, pkiekis);
    //rusiavimas(kursas, skiekis);
    suskirstymas(kursas, skiekis);
    //spausdinimasblogu(kursas, skiekis);
    //spausdinimasgeru(kursas, skiekis);
}
void analizel(int skiekis, int pkiekis, list<studentas>& kursas)
{

    kurimas(skiekis, pkiekis);
    skaitymasl(kursas, skiekis, pkiekis);
    suskirstymasl(kursas, skiekis);

}
