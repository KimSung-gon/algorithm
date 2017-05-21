#include <iostream>
#include <fstream>
using namespace std;

int gcd(int num1, int num2);

int gcd(int num1, int num2) {
	int r;
	if (num1 < 1 || num2 < 1) return 0;
	if (num1 < num2) return gcd(num2, num1);
	while ((r = num1%num2) != 0) { num1 = num2; num2 = r; }
	return num2;
}

int main() {

	ifstream inFile;
	int testCases;

	inFile.open("input.txt");

	if (inFile.fail())
		return 0;

	inFile >> testCases;

	for (int i = 0; i < testCases; i++) {
		int numerator;
		int denominator;
		
		inFile >> numerator >> denominator;

		for (int j = 1; numerator!=1; j++) {
			if (numerator*j > denominator) {
				numerator = numerator*j - denominator;
				denominator *= j;
			}
			int check = gcd(numerator, denominator);
			if (check != 1) {
				numerator /= check;
				denominator /= check;
			}
		}
		cout << denominator << endl;
	}

	return 0;
}