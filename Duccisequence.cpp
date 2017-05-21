#include <iostream>  
#include <fstream>
using namespace std;

int main()
{
	ifstream inFile;
	int testCases;

	inFile.open("input.txt");

	if (inFile.fail())
		return 0;

	inFile >> testCases;

	for(int i = 0; i < testCases; i++) {

		int numOfData;
		inFile >> numOfData;
		int *arr = new int[numOfData];

		for (int j = 0; j < numOfData; j++) {
			inFile >> arr[j];
		}

		for (int j = 0; j < 1000; j++) {
			int temp = arr[numOfData - 1] - arr[0];
			if (temp < 0)
				temp = -temp;
			for (int k = 0; k < numOfData-1; k++) {
				arr[k] = arr[k] - arr[k + 1];
				if (arr[k] < 0)
					arr[k] = -arr[k];
			}
			arr[numOfData - 1] = temp;
		}
		int sum = 0;
		for (int j = 0; j < numOfData; j++)
			sum += arr[j];
		if (sum == 0) 
			cout << "ZERO" << endl;
		else
			cout << "LOOP" << endl;
		delete []arr;
	}
	inFile.close();
	return 0;
}