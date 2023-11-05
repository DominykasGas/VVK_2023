#include "mylib.h"
studentas::studentas() {
	cout << "Iveskite varda ";cin >> vard;
	cout << "Iveskite pavarde ";cin >> pav;
	cout << "Kiek pazymiu buvo semestre? ";int n; cin >> n;
	for (int i = 0; i < n;i++) {
		int k;
		cout << "Iveskite " << i + 1 << " semestro pazymi: ";cin >> k; paz.push_back(k);
	}
	cout << "Iveskite egzamino pazymi :"; cin >> egz;
	skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
}
	studentas::studentas(string v, string p, vector<int>pp, int e) {
		vard = v;
		pav = p;
		paz = pp;
		egz = e;
		skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
	}
	studentas::studentas(const studentas & temp) {
		vard = temp.vard;
		pav = temp.pav;
		paz = temp.paz;
		egz = temp.egz;
		skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
	}
	studentas& studentas:: operator=(const studentas & temp) {
		if (this == &temp)
			return *this;
		vard = temp.vard;
		pav = temp.pav;
		paz = temp.paz;
		egz = temp.egz;
		skaiciavimo_Strategija == 'm' ? rezMed() : rezVid();
		return *this;
	}
	studentas::~studentas() {
		vard.clear();
		pav.clear();
		paz.clear();
		egz = 0;
		rez = 0;

	}
	void studentas::printas() {
		printf("|%-10s|%20s|", vard.c_str(), pav.c_str());
		for (auto& a : paz) printf("%3d|", a);
		printf("%10d|\n", egz);
	}
	void studentas::printasRez() {
		printf("|%-10s|%20s|", vard.c_str(), pav.c_str());
		printf("%10f|\n", rez);
	}
	float studentas::rezVid() {
		return std::accumulate(paz.begin(), paz.end(), 0.0) / paz.size() * 0.4 + egz * 0.6;
		 
	}
	float studentas::rezMed() {
		return rez = mediana(paz) * 0.4 + egz * 0.6;

	}
	void studentas::Rezult(char skaiciavimo_Strategija) {
		if (skaiciavimo_Strategija == 'v') { rez = 0.4 * rezVid() + 0.6 * egz; }
		else { rez = 0.4 * rezMed() + 0.6 * egz; }
	}
	double studentas::mediana(vector<int> vec) {
		typedef vector<double>::size_type vecsize;
		vecsize size = vec.size();
		if (size == 0)
			throw std::domain_error("negalima skaiciuoti mediana tusciam vektoriui");
		sort(vec.begin(), vec.end());
		vecsize vid = size / 2;
		return size % 2 == 0 ? (vec[vid] + vec[vid - 1]) / 2.0 : vec[vid] / 1.0;

	}
	std::istream& operator>>(std::istream& in, studentas& a) {
		in >> a.vard;
		in >> a.pav;
		for (int i = 0;i < 5;i++) {
			int k;
			in >> k;
			a.paz.push_back(k);
		}
		in >> a.egz;
		skaiciavimo_Strategija == 'm' ? a.rezMed() : a.rezVid();
		return in;
	}
	std::ostream& operator<<(std::ostream& out, const studentas& a) {
		out << a.vard << "; " << a.pav << ";";
		for (auto& i : a.paz) cout << i << ": ";
		out << a.egz << endl;
		return out;
	}




	Studentas::Studentas() {
		vardas = "";
		pavarde = "";
		nd = {};
		egzaminas = 0;
		Rez = 0.0;
		}

	Studentas::Studentas(string N, string S, vector<int> H, int E) {
		vardas = N;
		pavarde = S;
		nd = H;
		egzaminas = E;
		Rezultatas('v');
	}

	Studentas::Studentas(const Studentas& A) {
		vardas = A.vardas;
		pavarde = A.pavarde;
		nd = A.nd;
		egzaminas = A.egzaminas;
		Rez = A.Rez;
		
	}

	Studentas& Studentas::operator=(const Studentas& A) {
		if (this == &A)
			return *this;
		vardas = A.vardas;
		pavarde = A.pavarde;
		nd = A.nd;
		egzaminas = A.egzaminas;
		Rez = A.Rez;
		return *this;
	}

	Studentas::~Studentas() {
		vardas.clear();
		pavarde.clear();
		nd.clear();
		egzaminas = 0;
		Rez = 0;
	}


	float Studentas::Vid() {
		return (accumulate(nd.begin(), nd.end(), 0.0) / (nd.size() * 1.0));

	}
	float Studentas::Med() {
		int n = nd.size() / 2;
		return
			(n % 2 == 1) ? nd[n] / 1.0 : (nd[n] + nd[n + 1]) / 2.0;
	}

	void Studentas::Rezultatas(char skaiciavimo_Strategija) {
		if (skaiciavimo_Strategija == 't') {
			Rez = 0.4 * Vid() + 0.6 * egzaminas;
		}
		else {
			Rez = 0.4 * Med() + 0.6 * egzaminas;
		}
	}
	void Studentas::printass(){
		cout << vardas << " ; " << pavarde << " | ";
		for (auto& i : nd) cout << i << " | ";
		cout << egzaminas << " | ";
		cout << "Rezultatas: " << Rez << endl;
	}
	bool Studentas::operator<(Studentas& B)
	{
		return this->Rez < B.GetRez();
	}
	
	std::ostream& operator<<(std::ostream& os, const Studentas& A) {
		os << A.vardas << " ; " << A.pavarde << " | ";
		for (auto& i : A.nd) os << i << " | ";
		os << A.egzaminas << " | ";
		os << " Rezultatas = " << A.Rez << endl;
		return os;
	}
	std::istream& operator>>(std::istream& in, Studentas& a) { 
		in >> a.vardas;
		in >> a.pavarde;
		a.nd.clear();
		for (int i = 0; i < 5; i++) {
			int k;
			in >> k; a.nd.push_back(k);
		}
		in >> a.egzaminas;
		a.Rezultatas('v');
		return in;
	}
	bool maziauVid(const Studentas& A, const Studentas& B) {
		return A.GetRez() < B.GetRez();
	}
	
	

