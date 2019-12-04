#include <stdio.h>
#include <fstream>
#include <string>
#include <vector>
#include <cerrno>

static const std::vector<unsigned long> ops
{
	1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,1,10,19,1,19,5,23,2,23,6,27,1,27,5,31,2,6,31,35,1,5,
	35,39,2,39,9,43,1,43,5,47,1,10,47,51,1,51,6,55,1,55,10,59,1,59,6,63,2,13,63,67,1,9,67,71,
	2,6,71,75,1,5,75,79,1,9,79,83,2,6,83,87,1,5,87,91,2,6,91,95,2,95,9,99,1,99,6,103,1,103,13,
	107,2,13,107,111,2,111,10,115,1,115,6,119,1,6,119,123,2,6,123,127,1,127,5,131,2,131,6,135,
	1,135,2,139,1,139,9,0,99,2,14,0,0
};

static bool GetIndices(std::vector<unsigned long> &mod_ops, size_t &curIndex, unsigned long (&vals)[4])
{
	if (curIndex + 1 >= mod_ops.size())
	{
		return false;
	}
	vals[0] = mod_ops[curIndex++];

	if (vals[0] == 99)
	{
		return true;
	}

	if (curIndex + 3 >= mod_ops.size())
	{
		return false;
	}

	vals[1] = mod_ops[curIndex++];
	vals[2] = mod_ops[curIndex++];
	vals[3] = mod_ops[curIndex++];

	if ((vals[0] != 1) && (vals[0] != 2))
	{
		return false;
	}
	
	if ((vals[1] >= mod_ops.size()) || (vals[2] >= mod_ops.size()) || (vals[3] >= mod_ops.size()))
	{
		return false;
	}

	return true;
}

bool run_program(std::vector<unsigned long> &mod_ops)
{
	for (size_t index = 0; index < mod_ops.size();)
	{
		unsigned long vals[4];
		const bool failure = !GetIndices(mod_ops, index, vals);
		if (failure)
		{
			printf("day2_0: error\n");
			return false;
		}

		if (vals[0] == 99)
		{
			break;
		}
		else if (vals[0] == 1)
		{
			const unsigned int sum = mod_ops[vals[1]] + mod_ops[vals[2]];
			mod_ops[vals[3]] = sum;
		}
		else if (vals[0] == 2)
		{
			const unsigned int product = mod_ops[vals[1]] * mod_ops[vals[2]];
			mod_ops[vals[3]] = product;
		}
	}

	return true;
}

bool day2_0()
{
	std::vector<unsigned long> mod_ops = ops;
	mod_ops[1] = 12;
	mod_ops[2] = 2;

	const bool result = run_program(mod_ops);
	if (!result)
	{
		return result;
	}

	printf("day2_0:%lu\n", mod_ops[0]);

	return true;
}

bool day2_1()
{
	std::vector<unsigned long> mod_ops;

	for (unsigned long noun = 0; noun < 100; noun++)
	{
		for (unsigned long verb = 0; verb < 100; verb++)
		{
			mod_ops = ops;

			mod_ops[1] = noun;
			mod_ops[2] = verb;

			const bool result = run_program(mod_ops);
			if (!result)
			{
				return result;
			}

			if (mod_ops[0] == 19690720)
			{
				goto success;
			}
		}
	}

	return false;

success:
	printf("day2_1:%lu\n", mod_ops[1] * 100 + mod_ops[2]);

	return true;
}
