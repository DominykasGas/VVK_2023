#pragma once
#include "mylib.h"
#include <sstream>
#include <fstream>
using std::sort;



void Data_read(string Failovardas);
void sukurtiFailaIrSkaiciuotiGalutini(int n);
void sukurtiFailaIrSkaiciuotiGalutinisulist(int n);
void sukurtiFailaIrSkaiciuotiGalutinisudeque(int n);
void RinktiStudentus(std::vector<Studentas>& studentai, int n);
void RinktiStudentus(std::list<Studentas>& studentai, int n);
void RinktiStudentus(std::deque<Studentas>& studentai, int n);
void RusiuotiStudentus(const vector<Studentas>& studentai, vector<Studentas>& vargsiukai, vector<Studentas>& kietiakai);
void RusiuotiStudentus(const list<Studentas>& studentai, list<Studentas>& vargsiukai, list<Studentas>& kietiakai);
void RusiuotiStudentus(const deque<Studentas>& studentai, deque<Studentas>& vargsiukai, deque<Studentas>& kietiakai);
void SpausdintiStudentus(const vector<Studentas>& studentai, const std::vector<Studentas>& vargsiukai, const std::vector<Studentas>& kietiakai);
void SpausdintiStudentus(const list<Studentas>& studentai, const list<Studentas>& vargsiukai, const list<Studentas>& kietiakai);
void SpausdintiStudentus(const deque<Studentas>& studentai, const deque<Studentas>& vargsiukai, deque<Studentas>& kietiakai);
void SkaidytiStudentusiVarks(std::vector<Studentas>& studentai, std::vector<Studentas>& vargsiukai);
void SkaidytiStudentusiVarksl(std::list<Studentas>& studentai, std::list<Studentas>& vargsiukai);
void SkaidytiStudentusiVarksd(std::deque<Studentas>& studentai, std::deque<Studentas>& vargsiukai);
void SpausdintiStudentusVargs(const std::vector<Studentas>& vargsiukai);
void SpausdintiStudentusVargsd(const std::deque<Studentas>& vargsiukai);
void SpausdintiStudentusVargsl(const std::list<Studentas>& vargsiukai);



