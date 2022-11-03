#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <functional>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

struct studentas {
    string vardas, pavarde, pasirinkimas;
    vector<int> nd;
    int egz;
    float galutinisv = 0;
    float galutinism = 0;
};

void ivedimas(studentas s[], int skiekis) {


    int value = 0;
    string desicion, desicionnd;
    for (int i = 0; i < skiekis; i++)
    {
        cout << "Iveskite " << (i + 1) << "-ojo studento varda " << endl;
        cin >> s[i].vardas;
        cout << "Iveskite " << (i + 1) << "-ojo studento pavarde " << endl;
        cin >> s[i].pavarde;
        cout << "Ar egzamino pazymi noresite irasyti pats ar random (Rasykite: Patys arba Random)" << endl;
        cin >> desicion;
        if (desicion == "Patys")
        {
            cout << "Iveskite " << (i + 1) << "-ojo studento egzamino pazymi" << endl;
            cin >> s[i].egz;
        }
        else if (desicion == "Random")
        {
            srand(time(0));
            s[i].egz = rand() % 10 + 1;
            cout << (i + 1) << "-ojo studento random egzamino pazymys: " << s[i].egz << endl;
        }

        cout << "Ar noresite skaiciuoti galutini pagal vidurki ar pagal mediana (Rasykite: Vidurkis arba Mediana) " << endl;
        cin >> s[i].pasirinkimas;
        cout << "Ar noresite patys irasyti namu darbus ar sugeneruoti random? (Rasykite: NDPatys arba NDRandom) " << endl;
        cin >> desicionnd;
        if (desicionnd == "NDPatys")
        {
            cout << "Veskite namu darbus, uzbaigimui irasykite -1" << endl;
            while (true)
            {
                cout << "Namu darbo pazymis" << ": " << endl;
                cin >> value;
                if (value == -1) break;
                s[i].nd.push_back(value);

            }
        }
        else if (desicionnd == "NDRandom")
        {
            int pkiekis;
            cout << "Iveskite namu darbu kieki, kuri norite sugeneruoti: " << endl;
            cin >> pkiekis;
            srand(time(0));
            for (int j = 0; j < pkiekis; j++)
            {
                s[i].nd.push_back(rand() % 10 + 1);
            }
            cout << "Sugeneruoti atsitiktiniai namu darbu pazymiai: " << endl;
            for (auto elem : s[i].nd)
                cout  << elem << " ";
            cout << endl;
        }
        
    }

    cout << endl;
 }

float mediana(vector<int> nd) {
    typedef vector<int>::size_type ndSize;
    ndSize size = nd.size();
    sort(nd.begin(), nd.end());
    ndSize vid = size / 2;
    return size % 2 == 0 ? (nd[vid] + nd[vid - 1]) / 2 : nd[vid];
}
float vidurkis(vector<int> nd) {
    return accumulate(nd.begin(), nd.end(), 0.0) / nd.size();

}

void spausdinimas(studentas s[], int skiekis) {
    string pasirinkimas;
    cout << setw(25) << left << "Studento vardas" << setw(25) << left << "Pavarde" << setw(20) << left << "Galutinis(vidurkis)/ Galutinis(mediana)"
        << "\n";

    for (int i = 0; i < skiekis; i++)
    {
        cout << setw(25) << left << s[i].vardas << setw(25) << left << s[i].pavarde << " ";
        s[i].galutinisv = (vidurkis(s[i].nd) * 0.4) + (s[i].egz * 0.6);
        s[i].galutinism = (mediana(s[i].nd) * 0.4) + (s[i].egz * 0.6);
        if (s[i].pasirinkimas == "Vidurkis")
        {
            cout << fixed << setprecision(2) << setw(20) << left << s[i].galutinisv << " " << endl;
        }
        else if (s[i].pasirinkimas == "Mediana")
        {
            cout << fixed << setprecision(2) << setw(20) << left <<  s[i].galutinism << " " << endl;
        }
        

    }

}

int main()
{
    studentas s[30];
    int skiekis;
    cout << "Iveskite kiek yra studentu visame kurse: " << endl;
    cin >> skiekis;
    ivedimas(s, skiekis);
    spausdinimas(s, skiekis);

}
