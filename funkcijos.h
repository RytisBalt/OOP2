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
#include <random>
#include <list>

using namespace std;

struct studentas {
    string vardas, pavarde;
    vector<int> nd = { 0 };
    int egz;
    float galutinisv = 0;
    //float galutinism = 0;
};
class StudentasClass {
private: 
    string vardas;
    string pavarde;
    int egz;
    vector<int> nd;
    float galutinisv;

public:
    StudentasClass() : egz(0), galutinisv(0) {} // default konstruktorius
    StudentasClass(ifstream& file, int& pkiekis);
    inline string getVardas() const { return vardas; }   
    inline string getPavarde() const { return pavarde; }
    inline int getEgz() const { return egz; }
    inline vector<int> getNd() const {return nd; }
    float getGalutinis();
    void readStudent(ifstream&, int&);
    


};

//unsigned int zodziu_kiekis(string const& str);
void skaitymas(vector<studentas>& kursas, int& skiekis, int& pkiekis);
void spausdinimasblogu(vector<studentas>& kursas, int& skiekis);
void spausdinimasgeru(vector<studentas>& kursas, int& skiekis);
//float mediana(vector<int> nd);
float vidurkis(vector<int> nd);
void kurimas(int& skiekis, int& pkiekis);
void suskirstymas(vector<studentas>& kursas, int& skiekis);
void analize(int skiekis, int pkiekis, vector<studentas>& kursas);
void rusiavimas(vector<studentas>& kursas, int& skiekis);
void skaitymasl(list<studentas>& kursas, int& skiekis, int& pkiekis);
void analizeclass(int skiekis, int pkiekis, vector<StudentasClass>& kursas);
void suskirstymasl(list<studentas>& kursas, int& skiekis);
void suskirstymas2(vector<studentas>& kursas, int& skiekis);
void suskirstymasl2(list<studentas>& kursas, int& skiekis);
