#include "stdafx.h"
#include "Cost.h"
#include "Vehicul.h"
#include <fstream>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
ifstream fin("vehicule.txt");
ifstream finC("Costuri.txt");
map <string, int>Cost;
int main()
{

	cout << "\n    GARAJUL LUI FANE\n\n";
	cout << "'Unde poti sa legi cu sarma e pacat sa pui surub' - Richard Francu\n";
	cout << "       _______     \n";
	cout << "      /   |   \\    \n";
	cout << "   ===================  \n";
	cout << " __|     ||    |    |) \n";
	cout << "   =================== \n";
	cout << "     (__)     (__)\n\n";
	//srand(time(NULL));
	int N1, N2, N3, i, j, k;
	string S;
	i = j = k = 0;
	fin >> N1 >> N2 >> N3;
	//cout << N1;
	Automobil *A = new Automobil[N1];
	Motocicleta *M = new Motocicleta[N2];
	Bicicleta *B = new Bicicleta[N3];
	//	Vehicul v;
	finC >> Cost;
	while (fin >> S)
	{
		if (S == "Automobil")
		{
			fin >> A[i];
			A[i].set_stare(Cost);
			A[i].Random();
			A[i].set_stats();
			//A[i].Diagnoza(Cost);
			//cout << A[i];
			i++;
		}
		if (S == "Motocicleta")
		{
			fin >> M[j];
			M[j].set_stare(Cost);
			M[j].Random();
			M[j].set_stats();
			//cout << M[j];
			j++;
		}
		if (S == "Bicicleta")
		{
			fin >> B[k];
			B[k].set_stare(Cost);
			B[k].Random();
			B[k].set_stats();
			//cout << B[k];
			k++;
		}
	}
	
	//cout<<A[0].get_an();
	//cout << A[0].M.ulei_motor.nivel;

	cout << "\nCOMENZI VALABILE:\n";
	cout << "info model -> afiseaza informatii despre un vehicul(ALL - afiseaza toate vehiculele)\n";
	cout << "check model -> afiseaza diagnoza unui vehicul\n";
	cout << "damage model -> traumatizeaza un vehicul\n";
	cout << "exit -> iesi din program\n\n";
	while (S != "EXIT")
	{
		cin >> S;
		std::transform(S.begin(), S.end(), S.begin(), ::toupper);
		if (S == "INFO") {
			cin >> S;
			if(S=="ALL"){
				for (i = 0; i < N1; i++)
					cout << A[i];
				for (i = 0; i < N2; i++)
					cout << M[i];
				for (i = 0; i < N3; i++)
					cout << B[i];
			}
			for (i = 0; i < N1; i++)
				if (A[i].get_model() == S)
				{
					cout << A[i];
					break;
				  }
			for (i = 0; i < N2; i++)
				if (M[i].get_model() == S)
				{
					cout << M[i];
					break;
				}
			for (i = 0; i < N3; i++)
				if (B[i].get_model() == S)
				{
					cout << B[i];
					break;
				}
			cout << "\n";
		
						}
		if (S == "CHECK") {
			cin >> S;
		/*	if (S == "ALL") {
				for (i = 0; i < N1; i++)
					A[i].Diagnoza(Cost);
				for (i = 0; i < N2; i++)
					M[i].Diagnoza(Cost);
				for (i = 0; i < N3; i++)
					B[i].Diagnoza(Cost);
			}
			*/
			for (i = 0; i < N1; i++)
				if (A[i].get_model() == S)
				{	
					A[i].Diagnoza(Cost);
					break;
				}
			for (i = 0; i < N2; i++)
				if (M[i].get_model() == S)
				{
					M[i].Diagnoza(Cost);
					break;
				}
			for (i = 0; i < N3; i++)
				if (B[i].get_model() == S)
				{
					B[i].Diagnoza(Cost);
					break;
				}
			cout << "\n";
		}
			if (S == "DAMAGE") {
				cin >> S;
				for (i = 0; i < N1; i++)
					if (A[i].get_model() == S)
					{
						A[i].Traumatizare();
						break;
					}
				for (i = 0; i < N2; i++)
					if (M[i].get_model() == S)
					{
						M[i].Traumatizare();
						break;
					}
				for (i = 0; i < N3; i++)
					if (B[i].get_model() == S)
					{
						B[i].Traumatizare();
						break;
					}
				cout << "\n";
			}
					
		}
		//if(S == "")



	}
	
	//system("PAUSE");