//		A small frog wants to get to the other side of the road.
//	The frog is currently located at position X and wants to get to
//	a position greater than or equal to Y. The small frog always 
//	jumps a fixed distance, D.
//		Count the minimal number of jumps that the small frog must perform
//	to reach its target.
//		Written by Sergey Polischouck.

#include <stdio.h>

int solution(int X, int Y, int D);
//		Function is given three integers X, Y and D, returns the minimal number of jumps
//  from position X to a position equal to or greater than Y.
//		Complexity:
//	- Expected worst-case time complexity is O(1);
//	- Expected worst-case space complexity is O(1).

int main()
{
	int X = 10;
	int Y = 85;
	int D = 30;

	printf("X = %d\n", X);
	printf("Y = %d\n", Y);
	printf("D = %d\n", D);

	printf("solution(X, Y, D) = %d\n", solution(X, Y, D));

	return 0;
}

int solution(int X, int Y, int D)
{
	unsigned int mod = (Y-X) % D;
	unsigned int result = (Y-X) / D;

	if (mod)
	{
		result++;
	}

	return result;
}