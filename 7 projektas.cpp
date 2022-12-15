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

    /*vector<studentas> kursas;
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
    cout << endl;  */
    
    StudentasClass S1, S2;
    Zmogus* z1 = &S1;
    z1->print();

    
    cout << "Iveskite studento duomenis (1. Vardas, 2. Pavarde, 3. Egzaminas, 4. Rasykite namu darbus, kai nebenoresite irasykite -1): " << endl;
    cin >> S1;
    cout << "Studentas: " << S1 << endl;
    S2 = S1; //Copy Constructor
    cout << "Studentas(2)" << S2 << endl;
    

    system("pause");
    return 0;
}
