// ID_439.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string add(string num1, string num2)
{
	int rozmiarN1 = num1.size();
	int rozmiarN2 = num2.size();

	vector<unsigned short> wynik;
	short wPamieci = 0;
	string str = "";

	if(rozmiarN1 > rozmiarN2)
	{
		for (int i = rozmiarN2 - 1; i >= 0; i--)
		{
			for (int j= rozmiarN1 - 1; i >= 0; i--, j--)
			{
				short ostatniaCyfra = num1[j] - '0';
				if (ostatniaCyfra <= 9)
					wPamieci += ostatniaCyfra + num2[i] - '0';
				wynik.push_back(wPamieci % 10);
				wPamieci /= 10;
			}
		}
		for (int i = rozmiarN1 - rozmiarN2 ; i < rozmiarN1; i++)
		{
			wPamieci += num1[i];
			wynik.push_back(wPamieci % 10);
			wPamieci /= 10;
		}
	}
	else
	{
		for (int i = rozmiarN1 - 1; i >= 0; i--)
		{
			short ostatniaCyfra = num2[i] - '0';
			if (ostatniaCyfra <= 9)
				wPamieci += ostatniaCyfra + num1[i] - '0';
			wynik.push_back(wPamieci % 10);
			wPamieci /= 10;
		}
		for (int i = rozmiarN2 - rozmiarN1; i < rozmiarN2 && i != 0; i++)
		{
			wPamieci += num2[i];
			wynik.push_back(wPamieci % 10);
			wPamieci /= 10;
		}
	}

	while (wPamieci > 0)
	{
		wynik.push_back(wPamieci % 10);
		wPamieci /= 10;
	}

	for (int i = wynik.size() - 1; i >= 0; i--)
	{
		str += wynik[i] + '0';
	}

	return str;
}

string multiplyByDigit(string liczba, unsigned short cyfra)
{
	string str = "";
	if (liczba[0] == '-') str += '-';
	liczba = liczba.substr(1, liczba.size() - 1);
	
	short n1 = liczba.size();

	short wPamieci = 0;

	vector<unsigned short> wynik;

	for (int i = n1 - 1; i >= 0; i--)
	{
		short ostatniaCyfra = liczba[i] - '0';
		if (ostatniaCyfra <= 9)
			wPamieci += ostatniaCyfra * cyfra;
		wynik.push_back(wPamieci % 10);
		wPamieci /= 10;
	}

	while (wPamieci > 0)
	{
		wynik.push_back(wPamieci % 10);
		wPamieci /= 10;
	}

	for (int i = wynik.size() - 1; i >= 0; i--)
	{
		str += wynik[i] + '0';
	}

	return str;
}
/*
string multiply(string num1, string num2)
{
	string wynik = "";
	if (num1[0] == '-' && num2[0] != '-')
	{
		num1 = num1.substr(1, num1.size() - 1);
		wynik += '-';
	} else if (num2[0] == '-' && num1[0] != '-')
	{
		num2 = num2.substr(1, num2.size() - 1);
		wynik += '-';
	} else if (num1[0] == '-' && num2[0] == '-')
	{
		num1 = num1.substr(1, num1.size() - 1);
		num2 = num2.substr(1, num2.size() - 1);
	}

	int rozmiarN1 = num1.size();
	int rozmiarN2 = num2.size();
	if (rozmiarN1 == 0 || rozmiarN2 == 0)
		return "0";

	if ((rozmiarN1 == 1 && num1[0] == '0') || (rozmiarN2 == 1 && num2[0] == '0'))
		return "0";

	string suma = "0";
	int zera = 0;

	for (int i = rozmiarN2 - 1; i >= 0; i--)
	{
		string przezCyfre = multiplyByDigit(num1, num2[i] - '0');
	}

	int i = result.size() - 1;
	while (i >= 0 && result[i] == 0)
		i--;

	if (i == -1)
		return "0";

	string s = "";
	while (i >= 0)
		s += to_string(result[i--]);

	return s;
}*/

int main()
{
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		string n1, n2;
		cin >> n1 >> n2;
		cout << add(n1, n2) << endl;
	}

	return 0;
}
