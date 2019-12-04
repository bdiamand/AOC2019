#include <stdio.h>
#include <vector>
#include <string>

extern bool day1_0(const char *input, unsigned long &totalOut, std::vector<unsigned long> &masses);
extern bool day1_1(const std::vector<unsigned long> &masses);
extern bool day2_0();
extern bool day2_1();

int main(int argc, char *argv[])
{
	if (argc != 1)
	{
		printf("Expecting no inputs\n");
		return -1;
	}

	bool failure = false;

	unsigned long initalFuel;
	std::vector<unsigned long> masses;
	failure |= !day1_0("day1_0.input", initalFuel, masses);
	failure |= !day1_1(masses);
	failure |= !day2_0();
	failure |= !day2_1();

	if (failure)
	{
		printf("Failed\n");
		return -1;
	}

	return 0;
}