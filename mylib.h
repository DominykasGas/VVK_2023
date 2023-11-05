#pragma once
#include <iostream>
#include <iomanip>
#include <numeric>
#include <string>
#include <array>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <stdexcept>
#include <chrono>
#include<list>
#include<deque>
#include<random>
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::array;
using std::vector;
using std::left;
using std::right;
using std::setw;
using std::fixed;
using std::setprecision;
using std::domain_error;
using std::sort;
using std::getline;
using std::ifstream;
using std::exception;
using std::list;
using std::deque;
using std::uniform_int_distribution;
using std::sort;

extern char skaiciavimo_Strategija;
class studentas {
	string vard, pav;
	//array<int, 10> paz;
	vector<int> paz;
	int egz;
	float rez;
public:
	studentas();
	studentas(string v, string p, vector<int>pp, int e);
	studentas(const studentas& temp);
		
	studentas& operator=(const studentas& temp);	
	~studentas();
	inline string getVardas() {
		return vard;
	}
	inline int getPazNr() {
		return paz.size();
	}
	inline void setVardas(string t) {
		vard = t;
	}
	void printas();
	void printasRez();
	float rezVid();
	float rezMed();
	void Rezult(char skaiciavimo_Strategija);
	double mediana(vector<int> vec);
	friend std::istream& operator>>(std::istream& in, studentas& a);
	friend std::ostream& operator<<(std::ostream& out, const studentas& a);

};
struct Studentas {
	string pavarde;
	string vardas;
	vector<int> nd;
	int egzaminas;
	float Rez;
	double vidurkis;

public:
	Studentas();
	Studentas(string v, string p, vector<int>pp, int e);
	Studentas(const Studentas& A);
	Studentas& operator=(const Studentas& A);
	~Studentas();
	float Vid();
	float Med();
	void Rezultatas(char skaiciavimo_Strategija);
	inline void SetName(string N) { vardas = N; }
	inline void SetSurname(string S) { pavarde = S; }
	inline void SetHW(vector <int> Vec) { nd = Vec; }
	inline void SetExam(int n) { egzaminas = n; }
	float GetRez()const { return Rez; }
	void printass();
	friend std::ostream& operator<<(std::ostream& os, const Studentas& A);
	friend std::istream& operator>>(std::istream& in, Studentas& a);
	bool operator<(Studentas& B);

};
bool maziauVid(const Studentas& A, const Studentas& B);