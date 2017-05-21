#include <iostream>
#include <fstream>
#include <string.h>
#include <string>
using namespace std;
int coins[101];
#define MAX_COINS 101
#define MAX_CHANGE 1001
int countCoinExchange(int numDiffCoins, int change)
{
	int i, j, numComb;
	int N[MAX_COINS][MAX_CHANGE] = { 0 };
	/* base cases */
	for (i = 1; i <= numDiffCoins; i++)
		N[i][0] = 1;
	for (i = 1; i <= change; i++)
		N[0][i] = 0;
	for (i = 1; i <= numDiffCoins; i++)
		for (j = 1; j <= change; j++)
		{
			if (j - coins[i] < 0) /* base case */
				numComb = 0;
			else
				numComb = N[i][j - coins[i]];
			N[i][j] = N[i - 1][j] + numComb;
		}
	return N[numDiffCoins][change];
}
int main() {

	ifstream infile;
	infile.open("input.txt");

	if (infile.fail())
		return -1;

	int numOfCases;
	infile >> numOfCases;

	for (int i = 0; i < numOfCases; i++) {
		
		int N,K;
		infile >> N;

		for (int j = 1; j <= N; j++)
			infile >> coins[j];

		infile >> K;

		cout << countCoinExchange(N, K) << endl;

		}

	return 0;
}
