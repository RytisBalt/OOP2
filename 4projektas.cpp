#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <random>
#include "funkcijos.h"
#include <list>

using namespace std;


int main() {
;
    vector<studentas> kursas;
    list<studentas> kursasl;
    cout << "Spartos analize su VECTOR: " << endl;
    analize(1000, 5, kursas);
    cout << endl;
    analize(10000, 5, kursas);
    cout << endl;
    analize(100000, 5, kursas);
    cout << endl;
    analize(1000000, 5, kursas);
    cout << endl;
    analize(10000000, 5, kursas);
    cout << endl;


    cout << "Spartos analize su LIST: " << endl;
    analizel(1000, 5, kursasl);
    cout << endl;
    analizel(10000, 5, kursasl);
    cout << endl;
    analizel(100000, 5, kursasl);
    cout << endl;
    analizel(1000000, 5, kursasl);
    cout << endl;
    analizel(10000000, 5, kursasl);
    cout << endl;


    system("pause");
    return 0;
}
