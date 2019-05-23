#include "stdafx.h"
#include "Vehicul.h"
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;
//Vehicul::Vehicul(int x, int y):masa(x),an(y){}
void Vehicul::Random()
{
	srand(time(NULL));
	for (map<string, int>::iterator it = Stare.begin(); it != Stare.end(); ++it)
		it->second = 100 - rand() % (2020 - an);
	//for (map<string, int>::iterator it = Stare.begin(); it != Stare.end(); ++it)
	//	cout << it->first << " " << it->second << "\n";
}
/*istream & operator>>(istream &i, Automobil &A);
istream & operator>>(istream &i, Vehicul &V)
{
	//cout << "AAAH";
	string s;
	while (s!="END")
	{
		i >> s;
		if (s == "Automobil") { Automobil A(V); i >> A; V = A; }
		if (s == "Motocicleta") {Motocicleta M(V); i >> M; V = M; }
		if (s == "Bicicleta") { Bicicleta B(V); i >> B; V = B; }
	}
	return i;
}
*/
istream & operator>>(istream &i, Automobil &A)
{
	//cout << "AAAH";
	string s;
	int x;
	while (s != "END")
	{
		//cout << "OOF";
		i >> s;
		//cout << s<<"\n";
		if (s == "Model:") { i >> s; A.model = s; }
		else if (s == "An") { i >> s; i >> x; A.an = x; }
		else if (s == "Motor:") { i >> x; A.motor = x; }
		else if (s == "Putere:") { i >> x; A.putere = x; }
		else if (s == "Cuplu:") { i >> x; A.cuplu = x; }
		else if (s == "Masa:") { i >> x; A.masa = x; }
		else if (s == "Combustibil:") { i >> s; A.combustibil = s; }
		else if (s == "Usi:") { i >> x; A.usi = x; }
		else if (s == "Anvelope:") { i >> s; A.anvelope = s; }
	}
	return i;
}
ostream & operator<<(ostream &out, Automobil &A)
{
	out << "\nAutomobil\n";
	out << "Model: " << A.model << "\n";
	out << "An fabricatie: " << A.an << "\n";
	out << "Motor: " << A.motor << " cmc\n";
	out << "Putere: " << A.putere << " CP\n";
	out << "Masa: " << A.masa << " kg\n";
	out << "Combustibil: " << A.combustibil << "\n";
	out << "Numar usi: " << A.usi << "\n";
	out << "Tip anvelope: " << A.anvelope << "\n\n";
	return out;
}


istream & operator>>(istream &i, Motocicleta &M)
{
	//cout << "AAAH";
	string s;
	int x;
	while (s != "END")
	{
		i >> s;
		if (s == "Model:") { i >> s; M.model = s; }
		else if (s == "An") { i >> s; i >> x; M.an = x; }
		else if (s == "Motor:") { i >> x; M.motor = x; }
		else if (s == "Putere:") { i >> x; M.putere = x; }
		else if (s == "Cuplu:") { i >> x; M.cuplu = x; }
		else if (s == "Masa:") { i >> x; M.masa = x; }
		else if (s == "Anvelope:") { i >> s; M.anvelope = s; }
	}
	return i;
}

ostream & operator<<(ostream &out, Motocicleta &A)
{
	out << "\nMotocicleta\n";
	out << "Model: " << A.model << "\n";
	out << "An fabricatie: " << A.an << "\n";
	out << "Motor: " << A.motor << " cmc\n";
	out << "Putere: " << A.putere << " CP\n";
	out << "Masa: " << A.masa << " kg\n";
	out << "Tip anvelope: " << A.anvelope << "\n\n";
	return out;
}

istream & operator>>(istream &i, Bicicleta &B)
{
	//cout << "AAAH";
	string s;
	int x;
	while (s != "END")
	{
		i >> s;
		//cout << s << "\n";
		//cout << s;
		if (s == "Model:") { i >> s; B.model = s; }
		else if (s == "An") { i >> s; i >> x; B.an = x; }
		else if (s == "Masa:") { i >> x; B.masa = x; }
	}
	return i;
}
ostream & operator<<(ostream &out, Bicicleta &A)
{
	out << "\nBicicleta\n";
	out << "Model: " << A.model << "\n";
	out << "An fabricatie: " << A.an << "\n";
	out << "Masa: " << A.masa << " kg\n";
	return out;
}

void Bicicleta::Diagnoza(map<string, int>Cost) {
	pair<int, double>cost = { 0,0 };
	pair<int, double>s;
	cout << "\nSistemul de franare:\n";
	s = F.Check(Cost);
	cost.first += s.first;
	cost.second += s.second;

	cout << "\nDirectia:\n";
	s = D.Check(Cost);
	cost.first += s.first;
	cost.second += s.second;

	cout << "\nDistributia:\n";
	s = Ds.Check(Cost);
	cost.first += s.first;
	cost.second += s.second;
	cout << "\nCostul tuturor componentelor este " << cost.first << " lei\n";
	cout << "\nTimpul estimativ de lucru este de " << cost.second << " ore\n";
}
void Motocicleta::Diagnoza(map<string, int>Cost) {
	pair<int, double>cost = { 0,0 };
	pair<int, double>s;
	cout << "\nSistemul de franare:\n";
	s = F.Check(Cost);
	cost.first += s.first;
	cost.second += s.second;

	cout << "\nDirectia:\n";
	s = D.Check(Cost);
	cost.first += s.first;
	cost.second += s.second;


	cout << "\nMotorul:\n";
	s = M.Check(Cost);
	cost.first += s.first;
	cost.second += s.second;


	cout << "\nLuminile:\n";
	s = Fa.Check(Cost);
	cost.first += s.first;
	cost.second += s.second;

	cout << "\nCostul tuturor componentelor este " << cost.first << " lei\n";
	cout << "\nTimpul estimativ de lucru este de " << cost.second << " ore\n";
}
void Automobil::Diagnoza(map<string, int>Cost) {
	pair<int, double>cost = { 0,0 };
	pair<int, double>s;
	cout << "\nSistemul de franare:\n";
	s = F.Check(Cost);
	cost.first += s.first;
	cost.second += s.second;

	cout << "\nDirectia:\n";
	s = D.Check(Cost);
	cost.first += s.first;
	cost.second += s.second;


	cout << "\nMotorul:\n";
	s = M.Check(Cost);
	cost.first += s.first;
	cost.second += s.second;

	cout << "\nCaroseria:\n";
	s = C.Check(Cost);
	cost.first += s.first;
	cost.second += s.second;

	cout << "\nLuminile:\n";
	s = Fa.Check(Cost);
	cost.first += s.first;
	cost.second += s.second;

	cout << "\nCostul tuturor componentelor este " << cost.first << " lei\n";
	cout << "\nTimpul estimativ de lucru este de " << cost.second << " ore\n";
}

void Automobil::Traumatizare()
{
	int x;
	cout << "Alege din urmatoarele optiuni: \n";
	cout << "1 -> Uzeaza discurile de frana\n";
	cout << "2 -> Taie cauciucurile cu cutitul\n";
	cout << "3 -> Incepe sa arzi ulei\n";
	cout << "4 -> Oxideaza tabla\n";
	cout << "5 -> Sparge becurile\n";
	cin >> x;
	if (x == 1) {
		F.Traumatizare();
		cout << "Discurile au fost uzate\n";
	}
	if (x == 2) {
		D.Traumatizare();
		cout << "Cauciucurile au fost taiate\n";
	}
	if (x == 3) {
		M.Traumatizare();
		cout << "Uleiul a fost ars\n";
	}
	if (x == 4) {
		C.Traumatizare();
		cout << "Tabla a ruginit\n";
	}
	if (x == 5) {
		Fa.Traumatizare();
		cout << "Becurile s-au spart\n";
	}
}
void Motocicleta::Traumatizare()
{
	int x;
	cout << "Alege din urmatoarele optiuni: \n";
	cout << "1 -> Uzeaza discurile de frana\n";
	cout << "2 -> Stramba ghidonul\n";
	cout << "3 -> Incepe sa arzi ulei\n";
	cout << "4 -> Sparge becurile\n";
	cin >> x;
	if (x == 1) {
		F.Traumatizare();
		cout << "Discurile au fost uzate\n";
	}
	if (x == 2) {
		D.Traumatizare();
		cout << "Ghidonul a fost strambat\n";
	}
	if (x == 3) {
		M.Traumatizare();
		cout << "Uleiul a fost ars\n";
	}
	if (x == 4) {
		Fa.Traumatizare();
		cout << "Becurile s-au spart\n";
	}
}
void Bicicleta::Traumatizare()
{
	int x;
	cout << "Alege din urmatoarele optiuni: \n";
	cout << "1 -> Uzeaza discurile de frana\n";
	cout << "2 -> Stramba ghidonul\n";
	cout << "3 -> Fura lantul\n";
	cin >> x;
	if (x == 1) {
		F.Traumatizare();
		cout << "Discurile au fost uzate\n";
	}
	if (x == 2) {
		D.Traumatizare();
		cout << "Ghidonul a fost strambat\n";
	}
	if (x == 3) {
		Ds.Traumatizare();
		cout << "Lantul nu mai e\n";
	}


}