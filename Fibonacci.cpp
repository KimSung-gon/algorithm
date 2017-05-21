#include <iostream>
#include <fstream>
using namespace std;

int Fibonacci(int data);

int Fibonacci(int data) {

	if (data == 0)
		return 0;
	else if (data == 1)
		return 1;

	return Fibonacci(data - 1) + Fibonacci(data - 2);
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
		
		cout << Fibonacci(data) << endl;
	}

	inFile.close();
	return 0;
}