#include <iostream>
#include <fstream>

using namespace std;

#define MIN(a,b) ((a)<(b)?(a):(b))
int B[1001][1001];

int main() {

	ifstream infile;
	infile.open("input.txt");

	if (infile.fail())
		return -1;

	int numOfCasese;

	infile >> numOfCasese;

	int n, k;

	for (int i = 0; i < numOfCasese; i++) {

		infile >> n >> k;
		for (int x = 0; x <= n; x++)
			for (int y = 0; y <= MIN(x, k); y++)
				if (y == x || y == 0)
					B[x][y] = 1; /* base case */
				else
					B[x][y] = (B[x - 1][y - 1] + B[x - 1][y]) % 10007;
		cout << B[n][k] << endl;

	}
	return 0;
}