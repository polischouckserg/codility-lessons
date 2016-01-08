//		A zero-indexed array A consisting of N different integers is given.
//	The array contains integers in the range [1..(N + 1)], which means that
//	exactly one element is missing.
//		Written by Sergey Polischouck.

#include <stdio.h>

int solution(int A[], int N);
//	Function is given a zero-indexed array A and
//	returns the value of the missing element.

unsigned int sumNumericalSeriesFromZeroToOne(unsigned int n);

int main()
{
	int N = 5;
	int A[5] = {2, 1, 6, 4, 5};

	for (int i = 0; i < N; ++i)
	{
		printf("%d ", A[i]);
	}

	printf("\nsolution(A) = %d\n", solution(A, N));

	return 0;
}

int solution(int A[], int N)
{
	unsigned int predictedSumForArrayElements = sumNumericalSeriesFromZeroToOne(N+1);
	unsigned int calculatedSudForArrayElements = 0;

	for (int i = 0; i < N; ++i)
	{
		calculatedSudForArrayElements += A[i];
	}

	return (predictedSumForArrayElements - calculatedSudForArrayElements);
}

unsigned int sumNumericalSeriesFromZeroToOne(unsigned int n)
{
	return n*(n+1)/2;
}
