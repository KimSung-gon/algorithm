#include <iostream>
#include <fstream>
#include <math.h>
#include <windows.h>
using namespace std;

int palindrome(int inputVar);

int palindrome(int inputVar) {
	int tempInputVar;
	int index;
	int correct;

	for (int i = 2; i < 65; i++) {

		tempInputVar = inputVar;
		index = 0;
		while (tempInputVar >= i) {
			tempInputVar /= i;
			index++;
		}

		tempInputVar = inputVar;
		int *arr = new int[index + 1];
		index = 0;
		while (tempInputVar >= i) {
			arr[index] = tempInputVar%i;
			tempInputVar /= i;
			index++;
		}		
		arr[index] = tempInputVar;

		correct = 0;
		for (int j = 0; j < (index+1)/2; j++) {
			if (arr[j] == arr[index - j])
				correct++;
		}
		delete arr;
		if (correct == (index+1) / 2)
			return 1;
	}
	return 0;
}

int main() {
	
	ifstream inFile;
	int testCases;
	int inputVar;

	inFile.open("input.txt");

	if (inFile.fail())
		return 0;

	inFile >> testCases;

	for (int i = 0; i < testCases; i++) {

		inFile >> inputVar;
		cout << palindrome(inputVar) << endl;
	}
	inFile.close();
	return 0;
}