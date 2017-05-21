#include <iostream>
#include <fstream>

using namespace std;

int main() {

	ifstream inFile;
	inFile.open("input.txt");
	if (inFile.fail())
		return 0;

	int testCases;

	inFile >> testCases;

	for (int i = 0; i < testCases; i++) {

		int numOfHeight;
		int numOfWidth;
		int numOfOrder;
		int countWidth;
		inFile >> numOfHeight >> numOfWidth >> numOfOrder;

		countWidth = 1;
		while (numOfOrder > numOfHeight) {
			numOfOrder -= numOfHeight;
			countWidth++;
		}
		cout << numOfOrder * 100 + countWidth << endl;
	}
	return 0;
}