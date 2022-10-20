#include <iostream>
#include <iomanip>
#include <vector>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <random>
#include "funkcijos.h"

using namespace std;


int main() {


    vector<studentas> kursas;
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
    system("pause");
    return 0;
}
