// ID_439.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>

std::string multiply(std::string num1, std::string num2)
{
	int n1 = num1.size();
	int n2 = num2.size();
	if (num1.size() == 0 || num2.size() == 0)
		return "0";

	std::vector<int> result(n1 + n2, 0);

	int i_n1 = 0;
	int i_n2 = 0;

	for (int i = n1 - 1; i >= 0; i--)
	{
		int carry = 0;
		int n1 = num1[i] - '0';

		i_n2 = 0;

		for (int j = n2 - 1; j >= 0; j--)
		{
			int n2 = num2[j] - '0';

			int sum = n1 * n2 + result[i_n1 + i_n2] + carry;

			carry = sum / 10;

			result[i_n1 + i_n2] = sum % 10;

			i_n2++;
		}

		if (carry > 0)
			result[i_n1 + i_n2] += carry;

		i_n1++;
	}

	int i = result.size() - 1;
	while (i >= 0 && result[i] == 0)
		i--;

	if (i == -1)
		return "0";

	std::string s = "";
	while (i >= 0)
		s += std::to_string(result[i--]);

	return s;
}

int main()
{
	int n;
	std::cin >> n;

	for (int i = 0; i < n; i++)
	{
		std::string n1, n2;
		std::cin >> n1 >> n2;
		std::cout << multiply(n1, n2) << std::endl;
	}
	std::cin.ignore();

	return 0;
}
