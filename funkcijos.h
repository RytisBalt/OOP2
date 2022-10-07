#pragma once
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <exception>

using namespace std;

struct studentas {
    string vardas, pavarde;
    vector<int> nd = { 0 };
    int egz;
    float galutinis;
};

unsigned int zodziu_kiekis(string const& str);
void skaitymas(vector<studentas>& kursas, int* pkiekis);
void spausdinimas(vector<studentas> kursas, int pkiekis);
float mediana(vector<int> nd);
