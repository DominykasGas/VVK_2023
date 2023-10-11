#include "mylib.h"
char skaiciavimo_Strategija = 'v';
void sukurtiFailaIrSkaiciuotiGalutini(int n) {
    srand(time(nullptr));
    vector<Studentas> studentai;

    for (int j = 0; j < n; j++) {
        Studentas student;
        student.pavarde = "Pavarde" + std::to_string(j + 1);
        student.vardas = "Vardas" + std::to_string(j + 1);

        for (int k = 0; k < 5; k++) {
            student.nd.push_back(rand() % 10 + 1);
        }

        student.egzaminas = rand() % 10 + 1;

        studentai.push_back(student);
    }
    auto pradziafailas = std::chrono::high_resolution_clock::now();
    string failoPavadinimas = "studentai_" + std::to_string(n) + ".txt";

    std::ofstream failas(failoPavadinimas);
    if (!failas.is_open()) {
        cout << "Nepavyko atidaryti failo " << failoPavadinimas << endl;
        return;
    }

    failas << "Vardas    Pavarde      ND1  ND2  ND3  ND4  ND5  Egzaminas" << endl;
    auto pradziafailass = std::chrono::high_resolution_clock::now();
    for (const Studentas& student : studentai) {
        failas << left << setw(12) << student.vardas << setw(12) << student.pavarde;
        for (int k : student.nd) {
            failas << setw(5) << k;
        }
        failas << setw(10) << student.egzaminas << endl;
    }
    auto pabaigafailass = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas2 = pabaigafailass - pradziafailass;
    cout << "Nuskaitymas duomenu is failo uztruko " << laikas2.count() << " sekundziu." << std::endl;
    failas.close();
    cout << "Sukurtas failas " << failoPavadinimas << endl;
    auto pabaigafailas = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas = pabaigafailas- pradziafailas;
    cout << "Failo "<<failoPavadinimas<<" kurimas  uztruko " << laikas.count() << " sekundziu." << std::endl;

    std::ofstream malaciai("malaciai" + std::to_string(n) + ".txt");
    std::ofstream tinginiai("tinginiai" + std::to_string(n) + ".txt");

    if (!malaciai.is_open() || !tinginiai.is_open()) {
        cout << "Nepavyko atidaryti naujų failų." << endl;
        return;
    }
    auto rusiavimasp = std::chrono::high_resolution_clock::now();
    for (const Studentas& student : studentai) {
        double vidurkis = 0.4 * (student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
        if (vidurkis > 5.0) {
            malaciai << left << setw(12) << student.pavarde << setw(12) << student.vardas << setw(10) << vidurkis << endl;
        }
        else {
            tinginiai << left << setw(12) << student.pavarde << setw(12) << student.vardas << setw(10) << vidurkis << endl;
        }
    }
    auto rusiavimasb = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas3 = rusiavimasb - rusiavimasp;
    cout << "Surusiuotu studentu rusiavimas i grupes malaciai ir tinginiai uztruko " << laikas3.count() << " sekundziu." << std::endl;
    malaciai.close();
    tinginiai.close();

    cout << "Sukurti failai 'malaciai_" << n << ".txt' ir 'tinginiai" << n << ".txt'." << endl;
}
int main() {
    cout << "Kaip skaiciuoti galutini? v/m";
    cin >> skaiciavimo_Strategija;
    cout << "Iveskite studenta ";
    vector <studentas> grupe;
    for (int i = 0; i < 1;i++) {
        studentas K;
        //cin>>K;
        grupe.push_back(K);
        K.~studentas();
    }
    cout << endl << grupe.size() << endl;
    printf("|%-10s|%20s|", "Vardas", "Pavarde");
    for (int i = 0; i < grupe[0].getPazNr();i++)
        printf("%s%d|", "ND", i + 1);
    printf("%10s|\n", "Egzaminas");
    for (auto& a : grupe) a.printas();
    cout << endl;
    printf("|%-10s|%20s|", "Vardas", "Pavarde");
    printf("%10s|\n", skaiciavimo_Strategija == 'm' ? "Galutinis(m)" : "Galutinis(v)");
    for (auto& a : grupe) a.printasRez();
    for (auto& a : grupe) cout << a;

    try {
        ifstream failas("failo_kursiokai.txt");
        if (!failas.is_open()) {
            throw std::runtime_error("Failas 'failo_kursiokai.txt' nerastas.");
        }
        vector<Studentas> studentai;
        string eilute;
        getline(failas, eilute);
        while (getline(failas, eilute)) {
            Studentas student;
            std::istringstream iss(eilute);
            iss >> student.vardas>> student.pavarde;
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
        cout << "" << endl;
        cout << left << setw(12) << "Vardas" << setw(12) << "Pavarde" << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;cout << std::setfill('-') << setw(64) << "" << std::setfill(' ') << endl;
        cout << fixed << setprecision(2);
        for (const Studentas& student : studentai) {
            cout << setw(12) << student.vardas << setw(12) << student.pavarde << setw(20) << student.vidurkis << setw(20) << student.vidurkis << endl;

        }
        cout << "";
            int studentuSkaicius[] = { 1000, 10000, 100000 };

            for (int i = 0; i < 3; i++) {
                auto pradziosLaikas = std::chrono::high_resolution_clock::now();

                sukurtiFailaIrSkaiciuotiGalutini(studentuSkaicius[i]);

                auto pabaigosLaikas = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> trukme = pabaigosLaikas - pradziosLaikas;

                std::cout << "Surusiuotu studentu isvedimas i failus malaciai.txt ir tinginiai.txt uztruko "<< trukme.count() << " sekundziu." << std::endl;
            }
            return 0;
        }

    catch (const exception& e) {
        cout << "Klaida: " << e.what() << endl;
        return 1;
    }
}
