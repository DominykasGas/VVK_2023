#include "mylib.h"
#include "failai.h"
char skaiciavimo_Strategija = 'v';

        int main() {
            int pasir;
            cout << "Generuoti studentus -1, skaityti is failo -2, irasyti i faila -3, 1STRATEGIJA -4, 2STRATEGIJA\n -5";
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
                break;
            }
            case 4: {
                vector<Studentas> studentai_vector;
                list<Studentas> studentai_list;
                deque<Studentas> studentai_deque;
                int n = 100;

                auto laikasvector = std::chrono::high_resolution_clock::now();
                RinktiStudentus(studentai_vector, n);
                vector<Studentas> vargsiukai_vector;
                vector<Studentas> kietiakai_vector;
                RusiuotiStudentus(studentai_vector, vargsiukai_vector, kietiakai_vector);
                SpausdintiStudentus(studentai_vector, vargsiukai_vector, kietiakai_vector);
                auto pabaigavector = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> laikas = pabaigavector - laikasvector;


                auto laikaslist = std::chrono::high_resolution_clock::now();
                RinktiStudentus(studentai_list, n);
                list<Studentas> vargsiukai_list;
                list<Studentas> kietiakai_list;
                RusiuotiStudentus(studentai_list, vargsiukai_list, kietiakai_list);
                SpausdintiStudentus(studentai_list, vargsiukai_list, kietiakai_list);
                auto pabaigalist = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> laikas2 = pabaigalist - laikaslist;

                auto laikasdeque = std::chrono::high_resolution_clock::now();
                RinktiStudentus(studentai_deque, n);
                deque<Studentas> vargsiukai_deque;
                deque<Studentas> kietiakai_deque;
                RusiuotiStudentus(studentai_deque, vargsiukai_deque, kietiakai_deque);
                SpausdintiStudentus(studentai_deque, vargsiukai_deque, kietiakai_deque);
                auto pabaigadeque = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> laikas3 = pabaigadeque - laikasdeque;

                cout << "1 STRATEGIJA:: " << endl;
                cout << "Bendro studentai konteinerio rusiavimas i du naujus to paties tipo konteinerius vargsiuku ir kietiaku (vector) " << laikas.count() << " sekundziu. " << endl;
                cout << "Bendro studentai konteinerio rusiavimas i du naujus to paties tipo konteinerius vargsiuku ir kietiaku (list) " << laikas2.count() << " sekundziu." << endl;
                cout << "Bendro studentai konteinerio rusiavimas i du naujus to paties tipo konteinerius vargsiuku ir kietiaku (deque) " << laikas3.count() << " sekundziu." << endl;
                break;
            }
            case 5: {
                int n = 100;
                std::vector<Studentas> studentai_vectorv;
                std::deque<Studentas> studentai_dequed;
                std::list<Studentas> studentai_listl;
                std::deque<Studentas> vargsiukai_dequed;
                std::list<Studentas> vargsiukai_listl;
                std::vector<Studentas> vargsiukai_vectorv;
                auto laikasvectorv = std::chrono::high_resolution_clock::now();
                RinktiStudentus(studentai_vectorv, n);
                SkaidytiStudentusiVarks(studentai_vectorv, vargsiukai_vectorv);
                SpausdintiStudentusVargs(vargsiukai_vectorv);
                auto pabaigavectorv = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> laikasv = pabaigavectorv - laikasvectorv;

                auto laikaslistl = std::chrono::high_resolution_clock::now();
                RinktiStudentus(studentai_dequed, n);
                SkaidytiStudentusiVarksd(studentai_dequed, vargsiukai_dequed);
                SpausdintiStudentusVargsd(vargsiukai_dequed);
                auto pabaigalistl = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> laikasl = pabaigalistl - laikaslistl;

                auto laikasdequed = std::chrono::high_resolution_clock::now();
                RinktiStudentus(studentai_listl, n);
                SkaidytiStudentusiVarksl(studentai_listl, vargsiukai_listl);
                SpausdintiStudentusVargsl(vargsiukai_listl);
                auto pabaigadequed = std::chrono::high_resolution_clock::now();
                std::chrono::duration<double> laikasd = pabaigadequed - laikasdequed;
                cout << "2 STRATEGIJA:: " << endl;
                cout << "Bendro studentai konteinerio rusiavimas panaudojant tik viena konteineri vargsiukai (vector) " << laikasv.count() << " sekundziu." << endl;
                cout << "Bendro studentai konteinerio rusiavimas panaudojant tik viena konteineri vargsiukai (list)   " << laikasl.count() << " sekundziu." << endl;
                cout << "Bendro studentai konteinerio rusiavimas panaudojant tik viena konteineri vargsiukai (deque)  " << laikasd.count() << " sekundziu." << endl;
                break;
            }
            }
            
                  return 0;
            }
