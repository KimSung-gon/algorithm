#include <iostream>
#include <fstream>
using namespace std;

int coins[101];
int coins2[1001];
int coinsUsed[10001];
int lastCoin[10001];

int main() {

	ifstream infile;
	infile.open("input.txt");

	if (infile.fail())
		return -1;

	int numOfCases;
	infile >> numOfCases;

	for (int i = 0; i < numOfCases; i++) {
		int N, K;
		infile >> N;

		for (int j = 0; j < N; j++)
			infile >> coins[j];

		infile >> K;

		int count = 0;

		int cents, j;
		coinsUsed[0] = lastCoin[0] = 0;
		for (cents = 1; cents <= K; cents++)
		{
			int minCoins, newCoin;
			minCoins = cents;
			newCoin = 1;
			for (j = 0; j<N; j++)
			{
				if (coins[j] > cents)
					continue;
				if (coinsUsed[cents - coins[j]] + 1 < minCoins)
				{
					minCoins = coinsUsed[cents - coins[j]] + 1;
					newCoin = coins[j];
				}
			}
			coinsUsed[cents] = minCoins;
			lastCoin[cents] = newCoin;
		}

		while (K > 0) {
			coins2[lastCoin[K]]++;
			K -= lastCoin[K];
			count++;
		}

		cout << count << endl;

		for (int j = 0; j < N; j++) {
			cout << coins2[coins[j]] << " ";
			coins2[coins[j]] = 0;
		}
		cout << endl;
			
	}

	return 0;
}

