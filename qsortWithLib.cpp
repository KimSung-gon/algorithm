#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int compare(const void *a, const void *b);
int compare(const void *a, const void *b) {
	return (*(int*)a) - (*(int*)b);
}
int main() {

	ifstream infile;
	infile.open("input.txt");
	if (infile.fail())
		return 0;

	int numOfCases;
	infile >> numOfCases;

	for (int i = 0; i < numOfCases; i++) {
		int numOfData;
		infile >> numOfData;

		int *arr = new int[numOfData];
		for (int j = 0; j < numOfData; j++)
			infile >> arr[j];
		qsort(arr, numOfData, sizeof(arr[0]), compare);
		for (int j = 0; j < numOfData; j++)
			cout <<  arr[j] << " ";
		cout << endl;
	}
}