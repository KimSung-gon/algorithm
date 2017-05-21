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
		int sum;
		inFile >> sum;

		int arr[50];
		int returnVal = 0;
		for (int j = 1; j < 50; j++)
			arr[j - 1] = j*(j + 1) / 2;

		for(int k=0; k<50; k++)
			for(int l=0; l<50; l++)
				for(int m=0; m<50; m++)
					if (arr[m] + arr[l] + arr[k] == sum) {
						returnVal = 1;
						break;
					}
		cout << returnVal << endl;
	}

	return 0;
}