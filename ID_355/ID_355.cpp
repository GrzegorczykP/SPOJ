// ID_355.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct Coords
{
	int x;
	int y;
};

vector<Coords> get_coords();
double calculate_field(vector<Coords>);

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		string s;
		getline(cin, s); //skip empty line

		auto coords = get_coords();
		auto field1 = calculate_field(coords);

		coords = get_coords();
		auto field2 = calculate_field(coords);

		double all_field = field1 > field2 ? field1 : field2;
		double black_field = field1 < field2 ? field1 : field2;
		double grey_field = all_field - black_field;

		cout << fixed << setprecision(0) << grey_field * 6 + black_field * 10 << endl;
	}

	return 0;
}

vector<Coords> get_coords()
{
	vector<Coords> coordses;

	string line;
	getline(cin, line);
	istringstream iss(line);
	string s;
	Coords coords;
	while (!iss.eof())
	{
		getline(iss, s, ' ');
		std::istringstream(s) >> coords.x;
		getline(iss, s, ' ');
		std::istringstream(s) >> coords.y;
		coordses.push_back(coords);
	}

	return coordses;
}

double calculate_field(vector<Coords> coords)
{
	if (coords.size() < 3)
		return 0;

	double sum = 0;

	for (int i = 1; i < coords.size() - 1; ++i)
	{
		sum += coords[i].x * (coords[i + 1].y - coords[i - 1].y);
	}
	sum += coords[0].x * (coords[1].y - coords[coords.size() - 2].y);

	sum = abs(sum);

	return sum / 2;
}
