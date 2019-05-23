#pragma once
#include <map>
#include <cstring>
#include <iostream>
using namespace std;
struct frana { int placuta, disc; };

class Frane
{

	frana dreapta_fata;
	frana stanga_fata;
	frana dreapta_spate;
	frana stanga_spate;
public:
	Frane() {}
	Frane(map<string, int>Stare);
	pair<int, double> Check(map<string, int> Cost);
	void Traumatizare();
};

struct anvelopa { int presiune, uzura; };
struct roata {
	anvelopa anv;
	int janta;
};

class Directie
{
	roata dreapta_fata;
	roata stanga_fata;
	roata dreapta_spate;
	roata stanga_spate;
	int ghidon;
public:
	Directie() {}
	Directie(map<string, int>Stare);
	pair<int, double> Check(map<string, int> Cost);
	void Traumatizare();
};

struct ulei
{
	double nivel;
	int vascozitate;
};
class Motor
{
	ulei ulei_motor;
	int carburator;
	int EGR;
	int bloc_motor;
public:
	Motor() {}
	Motor(map<string, int>Stare);
	pair<int, double> Check(map<string, int> Cost);
	void Traumatizare();
	//pair<int, double> Check();
};
class Caroserie
{
	int vopsea;
	int aripa_stanga;
	int aripa_dreapta;
	int capota;
	int bara;
	int spoiler;
public:
	Caroserie() {}
	Caroserie(map<string, int>Stare);
	pair<int, double> Check(map<string,int>Cost);
	void Traumatizare();
};

class Distributie
{
	int lant;
	int lant_true;
public:
	Distributie() {}
	Distributie(map<string, int>Stare);
 	pair<int, double> Check(map<string,int>Cost);
	void Traumatizare();
};

class Faruri
{
	bool far;
	bool stop;
	bool semnalizator_stanga;
	bool semnalizator_dreapta;
public:
	Faruri() {}
	Faruri(map<string, int>Stare);
	pair<int, double> Check(map<string,int>Cost);
	void Traumatizare();
};

class Directie2
{
	int ghidon;
	roata fata, spate;
public:
	Directie2() {}
	Directie2(map<string, int>Stare);
	pair<int, double> Check(map<string, int>Cost);
	void Traumatizare();
};

class Frane2
{
	frana fata;
	frana spate;
public:
	Frane2() {}
	Frane2(map<string, int>Stare);
	pair<int, double> Check(map<string, int> Cost);
	void Traumatizare();
};
