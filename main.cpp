#include <iostream>
#include<iomanip> 
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;
struct studentas{
	string vardas, pavarde, pasirinkimas, decision;
	int nd[20];
	int egz, pkiekis;
    float suma = 0.0, vidurkis, galutinis, mediana = 0.0, galutinism;
 
};
void ivedimas(studentas[], int skiekis);
void spausdinimas(studentas[], int skiekis);

int main() {
    int skiekis;
    studentas m[30];
    cout << "Iveskite studentu kieki: " << endl;
    cin >> skiekis;

    ivedimas(m, skiekis);
    spausdinimas(m, skiekis);
    return 0;
    
}
void ivedimas(studentas s[], int skiekis)
{

    for (int i = 0; i < skiekis; i++) //INFORMACIJOS IVEDIMAS
    {
        cout << "Iveskite studento " << (i + 1) << " varda" << endl;
        cin >> s[i].vardas;
        cout << "Iveskite studento " << (i + 1) << " pavarde" << endl;
        cin >> s[i].pavarde;
        cout << "Ar noresite skaiciuoti galutini pagal vidurki ar pagal mediana? (Rasykite: Vidurkis arba Mediana)" << endl;
        cin >> s[i].pasirinkimas;
        cout << "Iveskite kiek gavo is egzamino " << (i + 1) << "-asis studentas " << endl;
        cin >> s[i].egz;
        cout << "Iveskite namu darbu pazymiu kieki" << endl;
        cin >> s[i].pkiekis;
        cout << "Iveskite ar norit random pazymiu? (Rasykite: Random arba Patys)" << endl;
        cin >> s[i].decision;
        if (s[i].decision == "Patys")
        for (int j = 0; j < s[i].pkiekis; j++)
        {
            cout << j + 1 << ". Kokie namu darbu pazymiai: ";
            cin >> s[i].nd[j];

        }
        else if (s[i].decision == "Random")
        {
            int max;
            max = 10;
            srand(time(0));
        for (int j = 0; j < s[i].pkiekis; j++)
            {
            s[i].nd[j] = rand() % max;
            cout << j + 1  << "Pazymys: " << s[i].nd[j] << "\n\n ";
        }
        }
        else {
            cout << "Ne ta ivedei" << endl;
        }

    }
}
void spausdinimas(studentas s[], int skiekis)
{
    for (int i = 0; i < skiekis; i++) {
        cout << "Vardas: " << s[i].vardas << " " << "\n" << "Pavarde: " << s[i].pavarde << " " << endl;
        if (s[i].pasirinkimas == "Vidurkis") {


            for (int j = 0; j < s[i].pkiekis; j++) {
                s[i].suma += s[i].nd[j];
            }
            s[i].vidurkis = s[i].suma / s[i].pkiekis;
            s[i].galutinis = 0.4 * s[i].vidurkis + 0.6 * s[i].egz;
            cout << fixed << setprecision(2) << "Galutinis balas = " << s[i].galutinis << endl;
            cout << endl;
        }
        else if (s[i].pasirinkimas == "Mediana") {
                     
            for (int j = 0; j < s[i].pkiekis; j++) {
                int vidurys = s[i].pkiekis / 2;
                
                if (vidurys / 2 == 0) {
                    s[i].mediana = (s[i].nd[vidurys - 1] +s[i].nd[vidurys]) / 2 ;
           
                }
                else {
                    s[i].mediana = s[i].nd[vidurys];
                }
            }        
         s[i].galutinism = 0.4 * s[i].mediana + 0.6 * s[i].egz;
         cout << fixed << setprecision(2) << "Galutinis balas pagal mediana = " << s[i].galutinism << endl;
         cout << endl;
            
        }
        else {
            cout << "Ne taip ivedei" << " ";
        }
    }
}

