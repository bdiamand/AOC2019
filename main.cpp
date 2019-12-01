#include <stdio.h>
#include <vector>
#include <string>

extern bool day1_0(const char *input);

int main(int argc, char *argv[])
{
	if (argc != 1)
	{
		printf("Expecting no inputs\n");
		return -1;
	}

	bool failure = false;
	failure |= !day1_0("day1_0.input");

	if (failure)
	{
		printf("Failed\n");
		return -1;
	}

	return 0;
}