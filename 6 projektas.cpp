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

    vector<studentas> kursas;
    vector<StudentasClass> kursasc;
    list<studentas> kursasl;
    cout << "Spartos analize su STRUCT: " << endl;
    //analize(1000, 5, kursas);
    cout << endl;
    //analize(10000, 5, kursas);
    cout << endl;
    analize(100000, 5, kursas);
    cout << endl;
    analize(1000000, 5, kursas);
    cout << endl;
    //analize(10000000, 5, kursas);
    cout << endl;


    cout << "Spartos analize su CLASS: " << endl;
    //analizeclass(1000, 5, kursasc);
    cout << endl;
    //analizeclass(10000, 5, kursasc);
    cout << endl;
    analizeclass(100000, 5, kursasc);
    cout << endl;
    analizeclass(1000000, 5, kursasc);
    cout << endl;
    //analizeclass(10000000, 5, kursasc);
    cout << endl;



    system("pause");
    return 0;
}
