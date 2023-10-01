﻿#include "mylib.h"
char skaiciavimo_Strategija = 'v';
struct Studentas {
    string pavarde;
    string vardas;
    vector<int> nd;
    int egzaminas;
    double vidurkis;
};

double skaiciuotiGalutiniVidurki(const Studentas& studentas) {
    double ndVidurkis = 0.0;
    for (int pazymys : studentas.nd) {
        ndVidurkis += pazymys;
    }
    ndVidurkis /= studentas.nd.size();
    return 0.4 * ndVidurkis + 0.6 * studentas.egzaminas;
}

double skaiciuotiGalutiniMediana(const Studentas& studentas) {
    vector<int> pazymiai = studentas.nd;
    pazymiai.push_back(studentas.egzaminas);
    sort(pazymiai.begin(), pazymiai.end());

    if (pazymiai.size() % 2 == 0) {
        int vidurinis1 = pazymiai[pazymiai.size() / 2 - 1];
        int vidurinis2 = pazymiai[pazymiai.size() / 2];
        return 0.3 * (vidurinis1 + vidurinis2) / 2.0 + 0.7 * studentas.egzaminas;
    }
    else {
        return 0.3 * pazymiai[pazymiai.size() / 2] + 0.7 * studentas.egzaminas;
    }
}
int main() {
	cout << "Kaip skaiciuoti galutini? v/m";
	cin >> skaiciavimo_Strategija;
	cout << "Iveskite studenta ";
	vector <studentas> grupe;
	for (int i = 0; i < 1;i++) {
		studentas K; grupe.push_back(K);
		K.~studentas();
	}
	cout << endl << grupe.size() << endl;
	printf("|%-10s|%20s|", "Vardas", "Pavarde");
	for (int i = 0; i < grupe[0].getPazNr();i++) 
		printf("%s%d|", "ND",i+1);
	printf("%10s|\n", "Egzaminas");
	for (auto& a : grupe) a.printas();
	cout << endl;
	printf("|%-10s|%20s|", "Vardas", "Pavarde");
	printf("%10s|\n", skaiciavimo_Strategija == 'm' ? "Galutinis(m)" : "Galutinis(v)");
	for (auto& a : grupe) a.printasRez();

    ifstream failas("failo_kursiokai.txt");
    if (!failas.is_open()) {
        cout << "Failas 'failo_kursiokai.txt' nerastas." <<endl;
        return 1;
    }

    vector<Studentas> studentai;
    string eilute;
    getline(failas, eilute);
    while (getline(failas, eilute)) {
        Studentas student;
        std::istringstream iss(eilute);
        iss >> student.pavarde >> student.vardas;
        int pazymys;
        while (iss >> pazymys) {
            student.nd.push_back(pazymys);
        }
        iss >> student.egzaminas;
 
    double suma = 0.0;
    for (int pazymys : student.nd) {
        suma += pazymys;
    }
    student.vidurkis = (suma / student.nd.size());

    studentai.push_back(student);
}

failas.close();
cout << ""<<endl;
cout << left << setw(12) << "Pavarde" << setw(12) << "Vardas" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;cout << std::setfill('-') << setw(64) << "" << std::setfill(' ') << endl;
cout << fixed << setprecision(2);
for (const Studentas& student : studentai) {
    cout << setw(12) << student.pavarde << setw(12) << student.vardas << setw(20) << student.vidurkis << setw(20) << student.vidurkis << endl;
}
return 0;
}

