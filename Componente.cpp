#include "stdafx.h"
#include "Componente.h"
#include <string>
#include <stdlib.h>
#include <time.h>
#define x1 98
#define x2 95
#define x3 92

using namespace std;

string s1m = "uzat\n";
string s1f = "uzata\n";
string s2m = "deteriorat\n";
string s2f = "deteriorata\n";
string s3m = "distrus\n";
string s3f = "distrusa\n";
string sok = "OK\n";




string Ver(bool g, int x)
{
	if (x >= x1) return sok;
	else if (g == 1 && x < x1 && x >= x2) return s1m;
	else if (g == 0 && x < x1 && x >= x2) return s1f;
	else if (g == 1 && x < x2 && x >= x3) return s2m;
	else if (g == 0 && x < x2 && x >= x3) return s2f;
	else if (g == 1 && x < x3) return s3m;
	else if (g == 0 && x < x3) return s3f;

}
string VerPresiune(bool g, int x)
{
	if (x >= x1) return "umflata\n";
	else if (x < x1 && x >= x2) return "usor dezumflata\n";
	else if (x < x2 && x >= x3) return "foarte dezumflata\n";
	else if (x < x3) return "fara aer\n";

}
string VerUlei(int x)
{
	if (x >= x1) return "nou\n";
	else if (x < x1 && x >= x2) return "vechi\n";
	else if (x < x2 && x >= x3) return "foarte vechi\n";
	else if (x < x3) return "antic\n";

}
string VerEGR(int x)
{
	if (x >= x1) return "curat\n";
	else if (x < x1 && x >= x2) return "usor infundat\n";
	else if (x < x2 && x >= x3) return "foarte infundat \n";
	else if (x < x3) return "astupat complet\n";

}
string VerCarb(int x)
{
	if (x >= x1) return "curat\n";
	else if (x < x1 && x >= x2) return "murdar\n";
	else if (x < x2 && x >= x3) return "infundat \n";
	else if (x < x3) return "astupat complet\n";

}
string VerVopsea(int x)
{
	if (x >= x1) return "OK\n";
	else if (x < x1 && x >= x2) return "usor ruginita\n";
	else if (x < x2 && x >= x3) return "foarte ruginita \n";
	else if (x < x3) return "cazan\n";

}
string VerCaroserie(int x)
{
	if (x >= x1 && x >= x2)return "OK\n";
	else if (x < x1 && x >= x2) return "zgariata\n";
	else if (x < x2 && x >= x3) return "indoita \n";
	else if (x < x3) return "distrusa\n";
}
string VerGhidon(int x)
{
	if (x >= x1 && x >= x2)return "OK\n";
	else if (x < x1 && x >= x2) return "stramb\n";
	else if (x < x2 && x >= x3) return "indoit \n";
	else if (x < x3) return "invers\n";
}
Frane::Frane(map<string, int> Stare) {
	dreapta_fata.placuta = 100 - rand() % (101 - Stare["placuta_frana"]);
	dreapta_fata.disc = 100 - rand() % (101 - Stare["disc"]);
	dreapta_spate.placuta = 100 - rand() % (101 - Stare["placuta_frana"]);
	dreapta_spate.disc = 100 - rand() % (101 - Stare["disc"]);
	stanga_fata.placuta = 100 - rand() % (101 - Stare["placuta_frana"]);
	stanga_fata.disc = 100 - rand() % (101 - Stare["disc"]);
	stanga_spate.placuta = 100 - rand() % (101 - Stare["placuta_frana"]);
	stanga_spate.disc = 100 - rand() % (101 - Stare["disc"]);
}
pair <int, double> Frane::Check(map<string, int>Cost)
{
	pair <int, double> cost;
	cost.first = 0;
	cost.second = 0;
	int c = 0;
	cout << "\nPlacute:\n";
	cout << "Placuta dreapta fata este " << Ver(0, dreapta_fata.placuta);
	if (dreapta_fata.placuta < x2) {
		c++;
		cost.first += Cost["placuta"];
		cost.second += 0.1;
	}
	cout << "Placuta stanga fata este " << Ver(0, stanga_fata.placuta);
	if (stanga_fata.placuta < x2) {
		c++;
		cost.first += Cost["placuta"];
		cost.second += 0.1;
	}
	cout << "Placuta dreapta spate este " << Ver(0, dreapta_spate.placuta);
	if (dreapta_spate.placuta < x2) {
		c++;
		cost.first += Cost["placuta"];
		cost.second += 0.1;
	}
	cout << "Placuta stanga spate este " << Ver(0, stanga_spate.placuta);
	if (stanga_spate.placuta < x2) {
		c++;
		cost.first += Cost["placuta"];
		cost.second += 0.1;
	}

	cout << "\nDiscuri:\n";
	cout << "Discul dreapta fata este " << Ver(1, dreapta_fata.disc);
	if (dreapta_fata.disc < x2) {
		c++;
		cost.first += Cost["disc"];
		cost.second += 0.2;
	}
	cout << "Discul stanga fata este " << Ver(1, stanga_fata.disc);
	if (stanga_fata.disc < x2) {
		c++;
		cost.first += Cost["disc"];
		cost.second += 0.2;
	}
	cout << "Discul dreapta spate este " << Ver(1, dreapta_spate.disc);
	if (dreapta_spate.disc < x2) {
		c++;
		cost.first += Cost["disc"];
		cost.second += 0.2;
	}
	cout << "Discul stanga spate este " << Ver(1, stanga_spate.disc);
	if (stanga_spate.disc < x2) {
		c++;
		cost.first += Cost["disc"];
		cost.second += 0.2;
	}
	cost.first += c * 5 * Cost["surub"];
	return cost;

}


Directie::Directie(map<string, int> Stare)
{
	ghidon = 100 - rand() % (101 - Stare["ghidon"]);

	dreapta_fata.anv.presiune = 100 - rand() % (101 - Stare["anvelopa_vara"]);
	dreapta_fata.anv.uzura = 100 - rand() % (101 - Stare["anvelopa_vara"]);
	dreapta_fata.janta = 100 - rand() % (101 - Stare["janta"]);

	stanga_fata.anv.presiune = 100 - rand() % (101 - Stare["anvelopa_vara"]);
	stanga_fata.anv.uzura = 100 - rand() % (101 - Stare["anvelopa_vara"]);
	stanga_fata.janta = 100 - rand() % (101 - Stare["janta"]);

	dreapta_spate.anv.presiune = 100 - rand() % (101 - Stare["anvelopa_vara"]);
	dreapta_spate.anv.uzura = 100 - rand() % (101 - Stare["anvelopa_vara"]);
	dreapta_spate.janta = 100 - rand() % (101 - Stare["janta"]);

	stanga_spate.anv.presiune = 100 - rand() % (101 - Stare["anvelopa_vara"]);
	stanga_spate.anv.uzura = 100 - rand() % (101 - Stare["anvelopa_vara"]);
	stanga_spate.janta = 100 - rand() % (101 - Stare["janta"]);
}

pair <int, double> Directie::Check(map<string, int>Cost)
{
	pair <int, double> cost;
	cost.first = 0;
	cost.second = 0;
	int c = 0;
	cout << "\nAnvelope:\n";
	cout << "Anvelopa dreapta fata este " << Ver(0, dreapta_fata.anv.uzura);
	if (dreapta_fata.anv.uzura < x2) {
		c++;
		cost.first += Cost["anvelopa"];
		cost.second += 0.2;
	}
	cout << "Anvelopa stanga fata este " << Ver(0, stanga_fata.anv.uzura);
	if (stanga_fata.anv.uzura < x2) {
		c++;
		cost.first += Cost["anvelopa"];
		cost.second += 0.2;
	}
	cout << "Anvelopa dreapta spate este " << Ver(0, dreapta_spate.anv.uzura);
	if (dreapta_spate.anv.uzura < x2) {
		c++;
		cost.first += Cost["anvelopa"];
		cost.second += 0.2;
	}
	cout << "Anvelopa stanga spate este " << Ver(0, stanga_spate.anv.uzura);
	if (stanga_spate.anv.uzura < x2) {
		c++;
		cost.first += Cost["anvelopa"];
		cost.second += 0.2;
	}

	cout << "\nPresiune:\n";
	cout << "Anvelopa dreapta fata este " << VerPresiune(0, dreapta_fata.anv.presiune);
	if (dreapta_fata.anv.presiune < x2) {
		c++;
		cost.second += 0.05;
	}
	cout << "Anvelopa stanga fata este " << VerPresiune(0, stanga_fata.anv.presiune);
	if (stanga_fata.anv.presiune < x2) {
		c++;
		cost.second += 0.05;
	}
	cout << "Anvelopa dreapta spate este " << VerPresiune(0, dreapta_spate.anv.presiune);
	if (dreapta_spate.anv.presiune < x2) {
		c++;
		cost.second += 0.05;
	}
	cout << "Anvelopa stanga spate este " << VerPresiune(0, stanga_spate.anv.presiune);
	if (stanga_spate.anv.presiune < x2) {
		c++;
		cost.second += 0.05;
	}

	cout << "\nJante:\n";
	cout << "Janta dreapta fata este " << Ver(0, dreapta_fata.janta);
	if (dreapta_fata.janta < x2) {
		c++;
		cost.first += Cost["janta"];
		cost.second += 0.2;
	}
	cout << "Janta stanga fata este " << Ver(0, stanga_fata.janta);
	if (stanga_fata.janta < x2) {
		c++;
		cost.first += Cost["janta"];
		cost.second += 0.2;
	}
	cout << "Janta dreapta spate este " << Ver(0, dreapta_spate.janta);
	if (dreapta_spate.janta < x2) {
		c++;
		cost.first += Cost["janta"];
		cost.second += 0.2;
	}
	cout << "Janta stanga spate este " << Ver(0, stanga_spate.janta);
	if (stanga_spate.janta < x2) {
		c++;
		cost.first += Cost["janta"];
		cost.second += 0.2;
	}

	cost.first += c * 5 * Cost["surub"];
	return cost;
}

Motor::Motor(map<string, int> Stare)
{
	ulei_motor.nivel = 5 - double(rand() % (101 - Stare["ulei_motor"])) / 7;
	ulei_motor.vascozitate = 100 - rand() % (101 - Stare["ulei_motor"]);
	carburator = 100 - rand() % (101 - Stare["carburator"]);
	EGR = 100 - rand() % (101 - Stare["EGR"]);
	bloc_motor = 100 - rand() % (101 - Stare["bloc_motor"]);
	//cout << Stare["ulei_motor"]<<" ";
}

pair <int, double> Motor::Check(map<string, int>Cost)
{
	pair <int, double> cost;
	cost.first = 0;
	cost.second = 0;
	int c = 0;
	cout << "Nivelul uleiului este " << ulei_motor.nivel << "l din 5l\n";
	if (ulei_motor.nivel <= 4.5) {
		c++;
		cost.first += Cost["ulei"] * double(5 - ulei_motor.nivel);
		cost.second += 0.01*(5 - ulei_motor.nivel);
	}

	cout << "Uleiul este " << VerUlei(ulei_motor.vascozitate);
	if (ulei_motor.vascozitate < x2) {
		c++;
		cost.first += Cost["ulei"] * 5;
		cost.second += 0.5;
	}

	cout << "Carburatorul este " << VerCarb(carburator);
	if (carburator < x2) {
		c++;
		cost.first += Cost["carburator"];
		cost.second += 1;
	}

	cout << "EGR-ul este " << VerEGR(EGR);
	if (EGR < x2) {
		c++;
		cost.first += Cost["EGR"];
		cost.second += 1;
	}

	cout << "Motorul este " << Ver(1, bloc_motor);
	if (bloc_motor < x2) {
		c++;
		cost.first += Cost["bloc_motor"];
		cost.first += Cost["ulei"] * 5;
		cost.second += 3;
	}
	cost.first += c * 5 * Cost["surub"];
	return cost;

}



Caroserie::Caroserie(map<string, int> Stare)
{
	vopsea = 100 - rand() % (101 - Stare["spray_vopsea"]);
	aripa_dreapta = 100 - rand() % (101 - Stare["aripa"]);
	aripa_stanga = 100 - rand() % (101 - Stare["aripa"]);
	capota = 100 - rand() % (101 - Stare["capota"]);
	bara = 100 - rand() % (101 - Stare["bara"]);
	spoiler = 100 - rand() % (101 - Stare["spoiler"]);
	//cout << Stare["ulei_motor"]<<" ";
}


pair <int, double> Caroserie::Check(map<string, int>Cost)
{
	pair <int, double> cost;
	cost.first = 0;
	cost.second = 0;
	int c = 0;
	cout << "Caroseria este " << VerVopsea(vopsea);
	if (vopsea < x2) {
		c++;
		cost.first += Cost["spray_vopsea"] * (100 - vopsea) / 10;
		cost.second += 0.1*(100 - vopsea);
	}

	cout << "Aripa dreapta este " << VerCaroserie(aripa_dreapta);
	if (aripa_dreapta < x2) {
		c++;
		cost.first += Cost["aripa"];
		cost.second += 0.5;
	}

	cout << "Aripa stanga este " << VerCaroserie(aripa_stanga);
	if (aripa_stanga < x2) {
		c++;
		cost.first += Cost["aripa"];
		cost.second += 0.5;
	}

	cout << "Capota este " << VerCaroserie(capota);
	if (capota < x2) {
		c++;
		cost.first += Cost["capota"];
		cost.second += 0.5;
	}

	cout << "Bara este " << VerCaroserie(bara);
	if (bara < x2) {
		c++;
		cost.first += Cost["bara"];
		cost.second += 0.5;
	}
	cost.first += c * 5 * Cost["surub"];
	return cost;

}


Distributie::Distributie(map<string, int> Stare)
{
	lant = 100 - rand() % (101 - Stare["lant"]);
	lant_true = 1 - (rand() % (101 - Stare["lant"])) / 10;
}

pair <int, double> Distributie::Check(map<string, int> Cost)
{
	pair <int, double> cost;
	cost.first = 0;
	cost.second = 0;
	int c = 0;

	if (lant_true == 0) {
		cout << "Lantul lipseste\n"; cost.first += Cost["lant"] + Cost["surub"] * 5;
		cost.second += 0.2;
	}
	else
		if (lant > x2) cout << "Lantul este OK\n";
		else {
			cout << "Lantul este ruginit\n"; cost.first += Cost["lant"] + Cost["surub"] * 5;
			cost.second += 0.2;
		}
		return cost;

}
Faruri::Faruri(map<string, int> Stare)
{
	far = 1 - (rand() % (101 - Stare["far"])) / 10;
	stop = 1 - (rand() % (101 - Stare["stop"])) / 10;
	semnalizator_dreapta = 1 - (rand() % (101 - Stare["semnalizator"])) / 10;
	semnalizator_stanga = 1 - (rand() % (101 - Stare["semnalizator"])) / 10;
}

pair <int, double> Faruri::Check(map<string, int>Cost)
{
	pair <int, double> cost;
	cost.first = 0;
	cost.second = 0;
	int c = 0;
	if (far) cout << "Farurile functioneaza OK\n";
	else {
		cout << "Farurile NU functioneaza\n";
		cost.first += Cost["far"];
		cost.second += 0.2;
	}
	if (stop) cout << "Stopurile functioneaza OK\n";
	else {
		cout << "Stopurile NU functioneaza\n"; 
		cost.first += Cost["stop"];
		cost.second += 0.2;
	}
	if (semnalizator_dreapta) cout << "Semnalizatorul la dreapta functioneaza OK\n";
	else {
		cout << "Semnalizatorul la dreapta NU functioneaza\n"; 
		cost.first += Cost["semnalizator"];
		cost.second += 0.2;
	}
	if (semnalizator_stanga) cout << "Semnalizatorul la stanga functioneaza OK\n";
	else {
		cout << "Semnalizatorul la stanga NU functioneaza\n"; 
		cost.first += Cost["semnalizator"];
		cost.second += 0.2;
	}
	return cost;
}

Directie2::Directie2(map<string, int> Stare)
{
	ghidon = 100 - rand() % (101 - Stare["ghidon"]);

	fata.anv.presiune = 100 - rand() % (101 - Stare["anvelopa_vara"]);
	fata.anv.uzura = 100 - rand() % (101 - Stare["anvelopa_vara"]);
	fata.janta = 100 - rand() % (101 - Stare["janta"]);

	spate.anv.presiune = 100 - rand() % (101 - Stare["anvelopa_vara"]);
	spate.anv.uzura = 100 - rand() % (101 - Stare["anvelopa_vara"]);
	spate.janta = 100 - rand() % (101 - Stare["janta"]);
}

pair <int, double> Directie2::Check(map<string, int>Cost)
{
	pair <int, double> cost;
	cost.first = 0;
	cost.second = 0;
	int c = 0;
	cout << "\nAnvelope:\n";
	cout << "Anvelopa din fata este " << Ver(0,fata.anv.uzura);
	if (fata.anv.uzura < x2) {
		c++;
		cost.first += Cost["anvelopa"];
		cost.second += 0.2;
	}

	cout << "Anvelopa din spate este " << Ver(0,spate.anv.uzura);
	if (spate.anv.uzura < x2) {
		c++;
		cost.first += Cost["anvelopa"];
		cost.second += 0.2;
	}


	cout << "\nPresiune:\n";
	cout << "Anvelopa din fata este " << VerPresiune(0, fata.anv.presiune);
	if (fata.anv.presiune < x2) {
		c++;
		cost.second += 0.05;
	}

	cout << "Anvelopa din spate este " << VerPresiune(0, spate.anv.presiune);
	if (spate.anv.presiune < x2) {
		c++;
		cost.second += 0.05;
	}


	cout << "\nJante:\n";
	cout << "Janta din fata este " << Ver(0, fata.janta);
	if (fata.janta < x2) {
		c++;
		cost.first += Cost["janta"];
		cost.second += 0.2;
	}
	cout << "Janta din spate este " << Ver(0, spate.janta);
	if (spate.janta < x2) {
		c++;
		cost.first += Cost["janta"];
		cost.second += 0.2;
	}

	cout << "\nGhidonul  este " << VerGhidon(ghidon);
	if (ghidon < x2) {
		c++;
		cost.first += Cost["ghidon"];
		cost.second += 0.2;
	}

	cost.first += c * 5 * Cost["surub"];
	return cost;
}

Frane2::Frane2(map<string, int> Stare) {
	fata.placuta = 100 - rand() % (101 - Stare["placuta_frana"]);
	fata.disc = 100 - rand() % (101 - Stare["disc"]);
	spate.placuta = 100 - rand() % (101 - Stare["placuta_frana"]);
	spate.disc = 100 - rand() % (101 - Stare["disc"]);
}

pair <int, double> Frane2::Check(map<string, int>Cost)
{
	pair <int, double> cost;
	cost.first = 0;
	cost.second = 0;
	int c = 0;
	cout << "\nPlacute:\n";
	cout << "Placuta din fata este " << Ver(0, fata.placuta);
	if (fata.placuta < x2) {
		c++;
		cost.first += Cost["placuta"];
		cost.second += 0.1;
	}
	cout << "Placuta din spate este " << Ver(0, spate.placuta);
	if (spate.placuta < x2) {
		c++;
		cost.first += Cost["placuta"];
		cost.second += 0.1;
	}

	cout << "\nDiscuri:\n";
	cout << "Discul din fata este " << Ver(1, fata.disc);
	if (fata.disc < x2) {
		c++;
		cost.first += Cost["disc"];
		cost.second += 0.2;
	}
	cout << "Discul din spate este " << Ver(1, spate.disc);
	if (spate.disc < x2) {
		c++;
		cost.first += Cost["disc"];
		cost.second += 0.2;
	}
	cost.first += c * 5 * Cost["surub"];
	return cost;
}
void Frane::Traumatizare()
{
	dreapta_fata.disc -= 3;
	dreapta_spate.disc -= 3;
	stanga_fata.disc -= 3;
	stanga_spate.disc -= 3;
}
void Frane2::Traumatizare()
{
	fata.disc -= 3;
	spate.disc -= 3;

}
void Directie::Traumatizare()
{
	dreapta_fata.anv.uzura = 0;
	dreapta_fata.anv.presiune = 0;
	dreapta_spate.anv.uzura = 0;
	dreapta_spate.anv.presiune = 0;
	stanga_fata.anv.uzura = 0;
	stanga_fata.anv.presiune = 0;
	stanga_spate.anv.uzura = 0;
	stanga_spate.anv.presiune = 0;

}
void Directie2::Traumatizare()
{
	ghidon -= 3;

}
void Motor::Traumatizare()
{
	ulei_motor.nivel -= 0.5;

}
void Caroserie::Traumatizare()
{
	vopsea -= 3;
}
void Faruri::Traumatizare()
{	
	far=0;
	stop=0;
	semnalizator_stanga=0;
	semnalizator_dreapta=0;
}
void Distributie::Traumatizare()
{
	lant_true = 0;
}