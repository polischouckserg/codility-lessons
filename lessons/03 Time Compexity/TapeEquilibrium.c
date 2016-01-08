//		A non-empty zero-indexed array A consisting of N integers is given.
//	Array A represents numbers on a tape.
//		Any integer P, such that 0 < P < N, splits this tape into two non-empty parts:
//	A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].
//		The difference between the two parts is the value of:
//	|(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|
//		In other words, it is the absolute difference between the sum of the first part
//	 and the sum of the second part.
//
//		Written by Sergey Polischouck.

#include <stdio.h>
#include <limits.h>

int solution(int A[], int N);
//		Function is given a non-empty zero-indexed array A of N integers 
//	and returns the minimal difference that can be achieved.
//		Complexity:
//	- Expected worst-case time complexity is O(N);
//	- Expected worst-case space complexity is O(N),
//	  beyond input storage (not counting the storage required for input arguments).

int main()
{
	int N = 5;
	int A[5] = {2, 1, 6, 4, 5};

	for (int i = 0; i < N; ++i)
	{
		printf("%d ", A[i]);
	}
	printf("solution(A, N) = %d\n", solution(A, N));

	return 0;
}

int solution(int A[], int N)
{
	int sumAllElementsInArray = 0;

	for (int i = 0; i < N; ++i)
	{
		sumAllElementsInArray += A[i];
	}
	printf("\n%d\n", sumAllElementsInArray);

	int sumAllElementsInLeftPartOfArray = 0;
	int sumAllElementsInRightPartOfArray = sumAllElementsInArray;
	int difference = 0;
	int minDifference = INT_MAX;

	for (int P = 1; P < N; ++P)
	{
		sumAllElementsInLeftPartOfArray += A[P-1];
		sumAllElementsInRightPartOfArray -= A[P-1];
		difference = sumAllElementsInLeftPartOfArray - sumAllElementsInRightPartOfArray;

		if (difference < 0)
		{
			difference = -difference;
		}
		printf("P = %d, difference = |%d − %d| = %d \n", P, sumAllElementsInLeftPartOfArray, sumAllElementsInRightPartOfArray, difference);

		if (difference < minDifference)
		{
			minDifference = difference;
		}
	}

	return minDifference;
}








