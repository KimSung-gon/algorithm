#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

int arr1[1003], arr2[1003];
int arr3[1003][1003];

int dp(int start, int numOfData)
{
	if (start > numOfData) 
		return 0;
	if (start == numOfData) 
		return arr1[start];
	int &result = arr3[start][numOfData];
	if (result >= 0) 
		return result;
	if (arr2[numOfData] - arr2[start - 1] - dp(start + 1, numOfData) > arr2[numOfData] - arr2[start - 1] - dp(start, numOfData - 1))
		result = arr2[numOfData] - arr2[start - 1] - dp(start + 1, numOfData);
	else
		result = arr2[numOfData] - arr2[start - 1] - dp(start, numOfData - 1);
	return result;
}

int main() {

	ifstream infile;
	int numOfCases;
	
	infile.open("input.txt");
	if (infile.fail())
		return -1;

	infile >> numOfCases;
	for (int i = 0; i < numOfCases; i++) {

		int numOfData;
		infile >> numOfData;
		
		for (int j = 1; j <= numOfData; j++) {
			infile >> arr1[j];
			arr2[j] = arr2[j - 1] + arr1[j];
		}
		for (int j = 1; j <= numOfData; j++)
			for (int k = j; k <= numOfData; k++) 
				arr3[j][k] = -1;
		cout << dp(1, numOfData) << endl;
	}
	return 0;
}