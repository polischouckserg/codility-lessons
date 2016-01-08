//		A non-empty zero-indexed array A consisting of N integers is given.
//	The array contains an odd number of elements, and each element of the array
//	can be paired with another element that has the same value, except for one 
//	element that is left unpaired.
//		Written by Sergey Polischouck.

#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N);
//		Function get an array A consisting of N integers fulfilling the above conditions,
//	returns the value of the unpaired element.
//		Complexity:
//	- Expected worst-case time complexity is O(N);
//	- Expected worst-case space complexity is O(1), 
//	  beyond input storage (not counting the storage required for input arguments).

char *printableBinaryCodeOfNumber(int number);
char *stringWithBinaryCodeFromNumber(int number);
char *formattedStringWithBinaryCode(char binaryCode[]);

int main()
{
	int N = 5;
	int A[5] = {2, 1, 9, 9, 1};

	for (int i = 0; i < N; ++i)
	{
		char *printableBinaryCode = printableBinaryCodeOfNumber(A[i]);
		printf("%s\n", printableBinaryCode);
		free(printableBinaryCode);
	}

	printf("solution(A) = %d\n", solution(A, N));

	return 0;
}

int solution(int A[], int N)
{
	int result = 0;

	for (int i = 0; i < N; ++i)
	{
		result ^= A[i];
	}

	return result;
}

char *printableBinaryCodeOfNumber(int number)
{
	char *binaryCode = stringWithBinaryCodeFromNumber(number);
	char *formattedBinaryCode = formattedStringWithBinaryCode(binaryCode);
	free(binaryCode);

	return formattedBinaryCode;
}

char *stringWithBinaryCodeFromNumber(int number)
{
	unsigned int memorySizeOfInt = sizeof(int)*8;
	char *binaryCode = (char*)malloc((memorySizeOfInt+1) * sizeof(char));

	if (binaryCode)
	{
		for (int i = memorySizeOfInt - 1; i >= 0 ; --i)
		{
			if (number & 1)
			{
				binaryCode[i] = '1';
			}
			else
			{
				binaryCode[i] = '0';
			}

			number >>= 1;
		}
	}
	binaryCode[memorySizeOfInt] = '\0';
	return binaryCode;
}

char *formattedStringWithBinaryCode(char binaryCode[])
{
	unsigned int memorySizeOfInt = sizeof(int)*8;
	unsigned int indexOfFirstSignificantDigit = 0;

	for (int i = 0; i < memorySizeOfInt; ++i)
	{
		if (binaryCode[i] == '1')
		{
			indexOfFirstSignificantDigit = i;
			break;
		}
	}

	unsigned int numberOfSignificantDigits = memorySizeOfInt - indexOfFirstSignificantDigit + 1;
	char *formattedBinaryCode = (char*)malloc((numberOfSignificantDigits + 3) * sizeof(char));

	formattedBinaryCode[0] = '0';
	formattedBinaryCode[1] = 'b';
	int index = 2;

	for (int i = indexOfFirstSignificantDigit; i < memorySizeOfInt; ++i)
	{
		formattedBinaryCode[index] = binaryCode[i];
		index++;
	}
	formattedBinaryCode[index] = '\0';

	return formattedBinaryCode;
}




















