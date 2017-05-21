#include <iostream>
#include <fstream>
using namespace std;

int gcd(int a, int b);

int gcd(int a, int b) {
	int big;
	int small;
	int rest;

	if (a > b) {
		big = a;
		small = b;
	}
	else {
		big = b;
		small = a;
	}
	if (small == 0)
		return big;
	if (big / small == 0)  {
		return small;
	}
	else
		return gcd(small, big%small);
}

int main() {

	ifstream inFile;
	inFile.open("input.txt");

	if (inFile.fail())
		return 0;

	int testCases;

	inFile >> testCases;

	for (int i = 0; i < testCases; i++) {
		int a;
		int b;
		inFile >> a >> b;

		cout << gcd(a, b) << endl;
	}

	inFile.close();
	return 0;
}