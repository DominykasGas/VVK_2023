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