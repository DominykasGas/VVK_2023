#include "mylib.h"
#include "failai.h"
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
    for (const Studentas& student : studentai) {
        failas << left << setw(12) << student.vardas << setw(12) << student.pavarde;
        for (int k : student.nd) {
            failas << setw(5) << k;
        }
        failas << setw(10) << student.egzaminas << endl;
    }
    
    failas.close();
    cout << "Sukurtas failas " << failoPavadinimas << endl;
    auto pabaigafailas = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> laikas = pabaigafailas - pradziafailas;
    cout << "Failo " << failoPavadinimas << " kurimas  uztruko " << laikas.count() << " sekundziu." << std::endl;

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
    void sukurtiFailaIrSkaiciuotiGalutinisulist(int n) {
        srand(time(nullptr));
        list<Studentas> studentai;

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
        for (const Studentas& student : studentai) {
            failas << left << setw(12) << student.vardas << setw(12) << student.pavarde;
            for (int k : student.nd) {
                failas << setw(5) << k;
            }
            failas << setw(10) << student.egzaminas << endl;
        }
        failas.close();
        cout << "Sukurtas failas " << failoPavadinimas << endl;
        auto pabaigafailas = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> laikas = pabaigafailas - pradziafailas;
        cout << "Failo " << failoPavadinimas << " kurimas  uztruko " << laikas.count() << " sekundziu." << std::endl;

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
    void sukurtiFailaIrSkaiciuotiGalutinisudeque(int n) {
        srand(time(nullptr));
        deque<Studentas> studentai;

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
        for (const Studentas& student : studentai) {
            failas << left << setw(12) << student.vardas << setw(12) << student.pavarde;
            for (int k : student.nd) {
                failas << setw(5) << k;
            }
            failas << setw(10) << student.egzaminas << endl;
        }
        failas.close();
        cout << "Sukurtas failas " << failoPavadinimas << endl;
        auto pabaigafailas = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> laikas = pabaigafailas - pradziafailas;
        cout << "Failo " << failoPavadinimas << " kurimas  uztruko " << laikas.count() << " sekundziu." << std::endl;

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
    void RinktiStudentus(std::vector<Studentas>& studentai, int n) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> nd_distribution(1, 10);
        std::uniform_int_distribution<int> egzaminas_distribution(1, 10);

        studentai.reserve(n);

        for (int j = 0; j < n; ++j) {
            Studentas student;
            student.pavarde = "Pavarde" + std::to_string(j + 1);
            student.vardas = "Vardas" + std::to_string(j + 1);

            for (int k = 0; k < 5; ++k) {
                student.nd.push_back(nd_distribution(gen));
            }

            student.egzaminas = egzaminas_distribution(gen);

            studentai.push_back(student);
        }
    }
    void RinktiStudentus(std::list<Studentas>& studentai, int n) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> nd_distribution(1, 10);
        std::uniform_int_distribution<int> egzaminas_distribution(1, 10);

        for (int j = 0; j < n; ++j) {
            Studentas student;
            student.pavarde = "Pavarde" + std::to_string(j + 1);
            student.vardas = "Vardas" + std::to_string(j + 1);

            for (int k = 0; k < 5; ++k) {
                student.nd.push_back(nd_distribution(gen));
            }

            student.egzaminas = egzaminas_distribution(gen);

            studentai.push_back(student);
        }
    }
    void RinktiStudentus(std::deque<Studentas>& studentai, int n) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<int> nd_distribution(1, 10);
        std::uniform_int_distribution<int> egzaminas_distribution(1, 10);

        for (int j = 0; j < n; ++j) {
            Studentas student;
            student.pavarde = "Pavarde" + std::to_string(j + 1);
            student.vardas = "Vardas" + std::to_string(j + 1);

            for (int k = 0; k < 5; ++k) {
                student.nd.push_back(nd_distribution(gen));
            }

            student.egzaminas = egzaminas_distribution(gen);

            studentai.push_back(student);
        }
    }

    void RusiuotiStudentus(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai) {
        for (const Studentas& student : studentai) {
            double vidurkis = 0.4 * (student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
            if (vidurkis <= 5.0) {
                vargsiukai.push_back(student);
            }
            else {
                kietiakai.push_back(student);
            }
        }
    }
    void RusiuotiStudentus(const list<Studentas>& studentai,list<Studentas>& vargsiukai, list<Studentas>& kietiakai) {
        for (const Studentas& student : studentai) {
            double vidurkis = 0.4 * (student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
            if (vidurkis <= 5.0) {
                vargsiukai.push_back(student);
            }
            else {
                kietiakai.push_back(student);
            }
        }
    }
    void RusiuotiStudentus(const deque<Studentas>& studentai, deque<Studentas>& vargsiukai, deque<Studentas>& kietiakai) {
        for (const Studentas& student : studentai) {
            double vidurkis = 0.4 * (student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
            if (vidurkis <= 5.0) {
                vargsiukai.push_back(student);
            }
            else {
                kietiakai.push_back(student);
            }
        }
    }
    void SpausdintiStudentus(const std::vector<Studentas>& studentai, const std::vector<Studentas>& vargsiukai, const std::vector<Studentas>& kietiakai) {
        
        
        
        std::cout << "Visi studentai:\n";
        for (const Studentas& student : studentai) {
            std::cout << student.vardas << " ; " << student.pavarde << " | ";
            for (auto& i : student.nd) std::cout << i << " | ";
            std::cout << student.egzaminas << " | ";
            double vidurkis = 0.4 * ((double)student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
            std::cout << "Rezultatas: " << vidurkis << std::endl;
            
        }

        std::cout << "Vargsiukai:\n";
        for (const Studentas& student : vargsiukai) {
            std::cout << student.vardas << " ; " << student.pavarde << " | ";
            for (auto& i : student.nd) std::cout << i << " | ";
            std::cout << student.egzaminas << " | ";
            double vidurkis = 0.4 * ((double)student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
            std::cout << "Rezultatas: " << vidurkis << std::endl;
         
        }

        std::cout << "Kietiakai:\n";
        for (const Studentas& student : kietiakai) {
            std::cout << student.vardas << " ; " << student.pavarde << " | ";
            for (auto& i : student.nd) std::cout << i << " | ";
            std::cout << student.egzaminas << " | ";
            double vidurkis = 0.4 * ((double)student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
            std::cout << "Rezultatas: " << vidurkis << std::endl;
        }
    }

    void SpausdintiStudentus(const list<Studentas>& studentai, const list<Studentas>& vargsiukai, const list<Studentas>& kietiakai) {
        std::cout << "Visi studentai:\n";
        for (const Studentas& student : studentai) {
            std::cout << student.vardas << " ; " << student.pavarde << " | ";
            for (auto& i : student.nd) std::cout << i << " | ";
            std::cout << student.egzaminas << " | ";
            double vidurkis = 0.4 * ((double)student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
            std::cout << "Rezultatas: " << vidurkis << std::endl;
        }

        std::cout << "Vargsiukai:\n";
        for (const Studentas& student : vargsiukai) {
            std::cout << student.vardas << " ; " << student.pavarde << " | ";
            for (auto& i : student.nd) std::cout << i << " | ";
            std::cout << student.egzaminas << " | ";
            double vidurkis = 0.4 * ((double)student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
            std::cout << "Rezultatas: " << vidurkis << std::endl;
        }

        cout << "Kietiakai:\n";
        for (const Studentas& student : kietiakai) {
            cout << student.vardas << " ; " << student.pavarde << " | ";
            for (auto& i : student.nd) cout << i << " | ";
            cout << student.egzaminas << " | ";
            double vidurkis = 0.4 * ((double)student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
            cout << "Rezultatas: " << vidurkis << std::endl;
        }
    }
    void SpausdintiStudentus(const deque<Studentas>& studentai, const deque<Studentas>& vargsiukai, deque<Studentas>& kietiakai) {
      

        cout << "Visi studentai:\n";
        for (const Studentas& student : studentai) {
            cout << student.vardas << " ; " << student.pavarde << " | ";
            for (auto& i : student.nd) cout << i << " | ";
            cout << student.egzaminas << " | ";
            double vidurkis = 0.4 * ((double)student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
  
            cout << "Rezultatas: " << vidurkis << std::endl;
        }

        std::cout << "Vargsiukai:\n";
        for (const Studentas& student : vargsiukai) {
            std::cout << student.vardas << " ; " << student.pavarde << " | ";
            for (auto& i : student.nd) std::cout << i << " | ";
            std::cout << student.egzaminas << " | ";
            double vidurkis = 0.4 * ((double)student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
             
            std::cout << "Rezultatas: " << vidurkis << std::endl;
        }

        std::cout << "Kietiakai:\n";
        for (const Studentas& student : kietiakai) {
            std::cout << student.vardas << " ; " << student.pavarde << " | ";
            for (auto& i : student.nd) std::cout << i << " | ";
            std::cout << student.egzaminas << " | ";
            double vidurkis = 0.4 * ((double)student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;

            std::cout << "Rezultatas: " << vidurkis << std::endl;
        }
    }
    

int main() {
    int pasir;
    cout << "Generuoti studentus -1, skaityti is failo -2, irasyti i faila -3\n";
    cin >> pasir;
    switch (pasir) {
    case 1: {
        cout << "Kaip skaiciuoti galutini? v/m";
        cin >> skaiciavimo_Strategija;
        cout << "Iveskite studenta ";
        vector <studentas> grupe;

        for (int i = 0; i < 1; i++) {
            studentas K;

            grupe.push_back(K);
        }

        cout << endl << grupe.size() << endl;
        printf("|%-10s|%20s|", "Vardas", "Pavarde");

        for (int i = 0; i < grupe[0].getPazNr(); i++) {
            printf("%s%d|", "ND", i + 1);
        }

        printf("%10s|\n", "Egzaminas");

        for (auto& a : grupe) {
            a.printas();
        }

        cout << endl;
        printf("|%-10s|%20s|", "Vardas", "Pavarde");
        printf("%10s|\n", skaiciavimo_Strategija == 'm' ? "Galutinis(m)" : "Galutinis(v)");

        for (auto& a : grupe) {
            a.Rezult(skaiciavimo_Strategija);
            a.printasRez();
        }
        break;
    }
    case 2: {
        cout << "Iveskite failo pavadinima";
        system("dir *.txt");
        string vardas;
        cin >> vardas;
        auto pradziafailass = std::chrono::high_resolution_clock::now();
        Data_read(vardas);
        auto pabaigafailass = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> laikas = pabaigafailass - pradziafailass;
        cout << " Nuskaitymas is failo uztruko " << laikas.count() << " sekundziu." << std::endl;
        break;
    }

    
    case 3: {
        int studentuSkaicius[] = { 1000, 10000, 100000 };//1000000, 10000000

        for (int i = 0; i < 3; i++) {
            cout << " " << endl;
            cout << "Darbas su vektoriais " << endl;
            sukurtiFailaIrSkaiciuotiGalutini(studentuSkaicius[i]);
            cout << " " << endl;
            cout << "Darbas su list " << endl;
            sukurtiFailaIrSkaiciuotiGalutinisulist(studentuSkaicius[i]);
            cout << " " << endl;
            cout << "Darbas su deque " << endl;
            sukurtiFailaIrSkaiciuotiGalutinisudeque(studentuSkaicius[i]);
        }
        vector<Studentas> studentai_vector;
        list<Studentas> studentai_list;
        deque<Studentas> studentai_deque;
        int n = 1000;
        RinktiStudentus(studentai_vector, n);
        RinktiStudentus(studentai_list, n);
        RinktiStudentus(studentai_deque, n);

        vector<Studentas> vargsiukai_vector;
        vector<Studentas> kietiakai_vector;
        RusiuotiStudentus(studentai_vector, vargsiukai_vector, kietiakai_vector);

        list<Studentas> vargsiukai_list;
        list<Studentas> kietiakai_list;
        RusiuotiStudentus(studentai_list, vargsiukai_list, kietiakai_list);

        deque<Studentas> vargsiukai_deque;
        deque<Studentas> kietiakai_deque;
        RusiuotiStudentus(studentai_deque, vargsiukai_deque, kietiakai_deque);
       auto laikasvector = std::chrono::high_resolution_clock::now();
       SpausdintiStudentus(studentai_vector, vargsiukai_vector, kietiakai_vector);
       auto pabaigavector = std::chrono::high_resolution_clock::now();
       std::chrono::duration<double> laikas = pabaigavector - laikasvector;

       auto laikaslist = std::chrono::high_resolution_clock::now();
       SpausdintiStudentus(studentai_list, vargsiukai_list, kietiakai_list);
       auto pabaigalist = std::chrono::high_resolution_clock::now();
       std::chrono::duration<double> laikas2 = pabaigalist - laikaslist;

       auto laikasdeque = std::chrono::high_resolution_clock::now();
       SpausdintiStudentus(studentai_deque, vargsiukai_deque, kietiakai_deque);
       auto pabaigadeque = std::chrono::high_resolution_clock::now();
       std::chrono::duration<double> laikas3 = pabaigadeque- laikasdeque;
      
       cout << "1 STRATEGIJA:: " << endl;
       cout << "Bendro studentai konteinerio rusiavimas i du naujus to paties tipo konteinerius vargsiuku ir kietiaku " << laikas.count() << " sekundziu." <<endl;
       cout << "Bendro studentai konteinerio rusiavimas i du naujus to paties tipo konteinerius vargsiuku ir kietiaku " << laikas2.count() << " sekundziu." <<endl;
       cout << "Bendro studentai konteinerio rusiavimas i du naujus to paties tipo konteinerius vargsiuku ir kietiaku " << laikas3.count() << " sekundziu." <<endl;
        break;
    }
            }
            return 0;
        }
