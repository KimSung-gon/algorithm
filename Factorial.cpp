#include <iostream>
#include <fstream>
using namespace std;

int Factorial(int data);

int Factorial(int data) {

	if (data == 0)
		return 1;
	return data * Factorial(data - 1);
}

int main() {
	ifstream inFile;
	inFile.open("input.txt");

	if (inFile.fail())
		return 0;

	int testCases;
	inFile >> testCases;

	for (int i = 0; i < testCases; i++) {
		int data;
		inFile >> data;

		cout << Factorial(data) << endl;
	}

	inFile.close();
	return 0;
}