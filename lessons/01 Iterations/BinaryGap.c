//		A binary gap within a positive integer N 
//	is any maximal sequence of consecutive zeros 
//	that is surrounded by ones at both ends in 
//	the binary representation of N.
//		Written by Sergey Polischouck.

#include <stdio.h>

int solution(int N);
//	Function get a positive integer N and returns the length of its longest binary gap.
//	The function returns 0 if N doesn't contain a binary gap.

int power(int number, unsigned int power);
void print_number_in_binary_code(int number);

int main()
{
	int N = 0b100100011100;
	printf("%d = ", N);
	print_number_in_binary_code(N);
	printf("solution(%d) = %d\n", N, solution(N));

	return 0;
}

int solution(int N)
{
	unsigned int i = 0;
	int length_of_maximal_binary_gap = 0;

	while (!(N & power(2, i)))
	{
		i++;
	}
	int index_of_previous_one = i;

	for (; i < (sizeof(int)*8 - 1); ++i)
	{
		if (N & power(2, i))
		{
			int amount_of_zeros = i - index_of_previous_one - 1;

			if (amount_of_zeros > length_of_maximal_binary_gap)
			{
				length_of_maximal_binary_gap = amount_of_zeros;
			}

			index_of_previous_one = i;
		}
	}

	return length_of_maximal_binary_gap;
}

int power(int number, unsigned int power)
{
	int result = 1;

	for (unsigned int i = 0; i < power; ++i)
	{
	 	result *= number;
	}

	return result; 
}

void print_number_in_binary_code(int number)
{
	printf("%s", "0b");
	for (int i = sizeof(int)*8 - 1; i >= 0 ; --i)
	{
		if (number & power(2, i))
		{
			printf("%c", '1');
		}
		else
		{
			printf("%c", '0');
		}
		if (i % 4 == 0 && i != 0)
		{
			printf(" ");
		}
	}

	printf("%s\n", "\0");
}
