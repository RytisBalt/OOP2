#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "funkcijos.h"

using namespace std;


int main() {
    int pkiekis;
    vector<studentas> kursas;
    studentas stud;
    skaitymas(kursas, &pkiekis);
    sort(kursas.begin(), kursas.end(), [](studentas a, studentas b)
        {
            return a.vardas < b.vardas;
        });
    spausdinimas(kursas, pkiekis);
    system("pause");
    return 0;
}
