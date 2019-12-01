#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <cerrno>

void GetFileLines(const char *fName, std::vector<std::string> &lines)
{
	std::ifstream file(fName);
	
	std::string str;
	while (std::getline(file, str))
	{
		lines.push_back(str);
	}
}

bool ToULongs(const std::vector<std::string> &lines, std::vector<unsigned long> &ulongs)
{
	for (const std::string &line : lines)
	{
		errno = 0;
		char *end = nullptr;
		unsigned long val = strtoul(line.c_str(), &end, 0);
		if (errno || (end == nullptr))
		{
			return false;
		}

		ulongs.push_back(val);
	}

	return true;
}

bool day1_0(const char *input, unsigned long &totalOut, std::vector<unsigned long> &masses)
{
	std::vector<std::string> lines;
	GetFileLines(input, lines);

	bool success = ToULongs(lines, masses);
	if (!success)
	{
		printf("Bad input value\n");
		return false;
	}

	unsigned long total = 0;
	for (unsigned long val : masses)
	{
		val /= 3;
		if (val < 2)
		{
			printf("Unexpected underflow\n");
			return false;
		}
		val -= 2;
		
		total += val;
	}
	totalOut = total;

	printf("day1_0:%lu\n", totalOut);

	return true;
}

unsigned long FuelNeeded(unsigned long mass)
{
	unsigned long amt = mass / 3;
	return (amt > 1) ? (amt - 2) : 0;
}

bool day1_1(const std::vector<unsigned long> &masses)
{
	unsigned long totalModulesFuel = 0;

	for (const unsigned long mass : masses)
	{
		unsigned long totalModuleFuel = 0;
		unsigned long remainder = mass;
		do
		{
			remainder = FuelNeeded(remainder);
			totalModuleFuel += remainder;
		} while (remainder);

		totalModulesFuel += totalModuleFuel;
	}

	printf("day1_1:%lu\n", totalModulesFuel);

	return true;
}
