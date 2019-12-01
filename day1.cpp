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

bool day1_0(const char *input)
{
	std::vector<std::string> lines;
	GetFileLines(input, lines);

	std::vector<unsigned long> ulongs;
	bool success = ToULongs(lines, ulongs);
	if (!success)
	{
		printf("Bad input value\n");
		return false;
	}

	unsigned long total = 0;
	for (unsigned long val : ulongs)
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

	printf("day1_0:%lu\n", total);

	return true;
}