#pragma once
#include "Componente.h"
#include <map>
#include <cstring>
#include <iostream>
using namespace std;

class Vehicul
{
protected:
	map<string, int>Stare;
	int masa, an;
	string model, frante_fata, frane_spate;
public:
	void set_stare(map<string, int> &Cost) { Stare.insert(Cost.begin(), Cost.end()); }
	string get_model() { return model; }
	int get_an() { return an; }
	void set_an(int an) { this->an = an; }
	int get_masa() { return masa; }
	void set_masa(int masa) { this->masa = masa; }
	friend istream & operator>>(istream &i, Vehicul &V);
	virtual void Diagnoza(map<string, int>Cost) = 0;
	virtual void Traumatizare() = 0;
	void Random();
};

class Bicicleta : public Vehicul
{
private:
	int masa;
	Frane2 F;
	Directie2 D;
	Distributie Ds;
public:
	Bicicleta() :Vehicul() {}
	Bicicleta(Vehicul &V) { this->an = V.get_an(); this->masa = V.get_masa(); }
	void set_stats() { F = Frane2(Stare); D = Directie2(Stare); Ds = Distributie(Stare); }
	friend istream & operator>>(istream &i, Bicicleta &A);
	friend ostream & operator<<(ostream &out, Bicicleta &A);
	void Diagnoza(map<string, int>Cost);
	void Traumatizare();
};

class Motocicleta : public Vehicul
{
private:
	int motor;
	int putere;
	int cuplu;
	int masa;
	string anvelope;
	Frane2 F;
	Directie2 D;
	Motor M;
	Faruri Fa;
public:
	Motocicleta() :Vehicul() {}
	Motocicleta(Vehicul &V) { this->an = V.get_an(); this->masa = V.get_masa(); }
	void set_stats() { F = Frane2(Stare); D = Directie2(Stare); M = Motor(Stare);  Fa = Faruri(Stare); }
	friend istream & operator>>(istream &i, Motocicleta &A);
	friend ostream & operator<<(ostream &out, Motocicleta &A);
	void Diagnoza(map<string, int>Cost);
	void Traumatizare();
};


class Automobil : public Vehicul
{
private:
	int motor;
	int putere;
	int cuplu;
	int masa;
	string combustibil;
	int usi;
	string anvelope;
	Frane F;
	Directie D;
	Motor M;
	Caroserie C;
	Faruri Fa;
	//Motor M;
public:
	Automobil() :Vehicul() {}
	Automobil(Vehicul &V) { this->an = V.get_an(); this->masa = V.get_masa(); }
	void set_stats() { F = Frane(Stare); D = Directie(Stare); M = Motor(Stare); C = Caroserie(Stare); Fa = Faruri(Stare); }
	friend istream & operator>>(istream &i, Automobil &A);
	friend ostream & operator<<(ostream &out, Automobil &A);
	void Diagnoza(map<string, int>Cost);
	void Traumatizare();

};


