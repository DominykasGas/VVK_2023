#include "failai.h"

void Data_read(string FailoVardas)
{
	std::ifstream open_f(FailoVardas);
	vector<Studentas>Grupe;
	//deque<Studentas>Grupe;
	//list<Studentas>Grupe;
	string NuskEil;
	std::getline(open_f, NuskEil);
	while (open_f) {
		if (!open_f.eof()) {
			std::getline(open_f, NuskEil);
			std::stringstream my_buffer(NuskEil);
			Studentas Temp;
			string TEil;
			my_buffer >> TEil; Temp.SetName(TEil);
			my_buffer >> TEil; Temp.SetSurname(TEil);
			
			vector<int> Laikpaz;
			int t;
			while (my_buffer >> t) {
				if (t >= 0 && t < 11) Laikpaz.push_back(t);
				else std::cerr << "Pazymis sugadintas\n";

			}
			if (Laikpaz.empty()) std::cerr << "Studentas neturi iverciu \n";
			else
			{
				Temp.SetExam(Laikpaz.back());
				Laikpaz.pop_back();
				Temp.SetHW(Laikpaz);
				Temp.Rezultatas('v');
				Grupe.push_back(Temp);
			}
			Laikpaz.clear();
			Temp.SetHW(Laikpaz);
		}
		else break;
		}
	sort(Grupe.begin(), Grupe.end());
    for (const auto& duom : Grupe) 
       std::cout << duom;
    
}
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
void RusiuotiStudentus(const list<Studentas>& studentai, list<Studentas>& vargsiukai, list<Studentas>& kietiakai) {
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
void SkaidytiStudentusiVarks(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsiukai) {
    const double riba = 5.0;
    auto it = studentai.begin();

    while (it != studentai.end()) {
        double vidurkis = 0.4 * ((double)it->nd[0] + it->nd[1] + it->nd[2] + it->nd[3] + it->nd[4]) / 5.0 + 0.6 * it->egzaminas;
        if (vidurkis < riba) {
            vargsiukai.push_back(*it);
            it = studentai.erase(it);
        }
        else {
            ++it;
        }
    }
}
void SkaidytiStudentusiVarksl(std::list<Studentas>& studentai, std::list<Studentas>& vargsiukai) {
    const double riba = 5.0;
    auto it = studentai.begin();

    while (it != studentai.end()) {
        double vidurkis = 0.4 * ((double)it->nd[0] + it->nd[1] + it->nd[2] + it->nd[3] + it->nd[4]) / 5.0 + 0.6 * it->egzaminas;
        if (vidurkis < riba) {
            vargsiukai.push_back(*it);
            it = studentai.erase(it);
        }
        else {
            ++it;
        }
    }
}
void SkaidytiStudentusiVarksd(std::deque<Studentas>& studentai, std::deque<Studentas>& vargsiukai) {
    const double riba = 5.0;
    //panaudotas std:partition
    auto partition_point = std::partition(studentai.begin(), studentai.end(), [riba](const Studentas& student) {
        double vidurkis = 0.4 * (student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
        return vidurkis < riba;
        });
    std::move(partition_point, studentai.end(), std::back_inserter(vargsiukai));


    studentai.erase(partition_point, studentai.end());
}
void SpausdintiStudentusVargs(const std::vector<Studentas>& vargsiukai) {
    std::cout << "Vargsiukai vector:\n";
    for (const Studentas& student : vargsiukai) {
        std::cout << student.vardas << " ; " << student.pavarde << " | ";
        for (auto& i : student.nd) std::cout << i << " | ";
        std::cout << student.egzaminas << " | ";
        double vidurkis = 0.4 * ((double)student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
        std::cout << "Rezultatas: " << vidurkis << std::endl;
    }
}
void SpausdintiStudentusVargsd(const std::deque<Studentas>& vargsiukai) {
    std::cout << "Vargsiukai deque:\n";
    for (const Studentas& student : vargsiukai) {
        std::cout << student.vardas << " ; " << student.pavarde << " | ";
        for (auto& i : student.nd) std::cout << i << " | ";
        std::cout << student.egzaminas << " | ";
        double vidurkis = 0.4 * ((double)student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
        std::cout << "Rezultatas: " << vidurkis << std::endl;
    }
}
void SpausdintiStudentusVargsl(const std::list<Studentas>& vargsiukai) {
    std::cout << "Vargsiukai list:\n";
    for (const Studentas& student : vargsiukai) {
        std::cout << student.vardas << " ; " << student.pavarde << " | ";
        for (auto& i : student.nd) std::cout << i << " | ";
        std::cout << student.egzaminas << " | ";
        double vidurkis = 0.4 * ((double)student.nd[0] + student.nd[1] + student.nd[2] + student.nd[3] + student.nd[4]) / 5.0 + 0.6 * student.egzaminas;
        std::cout << "Rezultatas: " << vidurkis << std::endl;
    }
}
