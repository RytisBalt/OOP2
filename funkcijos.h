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
    float galutinisv = 0;
    float galutinism = 0;
};

unsigned int zodziu_kiekis(string const& str);
void skaitymas(vector<studentas>& kursas);
void spausdinimas(vector<studentas>& kursas);
float mediana(vector<int> nd);
float vidurkis(vector<int> nd);

