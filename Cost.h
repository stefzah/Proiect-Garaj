#pragma once
#include "stdafx.h"
#include<iostream>
#include<string>
#include<cstring>
#include<map>
using namespace std;
istream & operator>>(istream &i, map<string, int> &C)
{
	string s;
	int x;
	while (i >> s)
		if (s[0] != '/') { i >> x; C[s] = x; }
	return i;
}
