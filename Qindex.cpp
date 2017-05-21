#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int compare(const void *a, const void *b);

int compare(const void *a, const void *b) {
	return (*(int*)a) - (*(int*)b);
}

int main() {
	fstream infile;
	int numOfCases;

	infile.open("input.txt");
	if (infile.fail())
		return 0;

	infile >> numOfCases;

	for (int i = 0; i < numOfCases; i++) {

		int numOfData;
		infile >> numOfData;

		int *array = new int[numOfData + 1];
		array[0] = 0;
		for (int j = 1; j <= numOfData; j++) {
			infile >> array[j];
		}

		qsort(array, numOfData+1, sizeof(array[0]), compare);

		int q = 0;
		int index;
		for (int k = 1; k <= array[numOfData]; k++) {
			
			index = 1;
			while (array[index] < k)
				index++;

			if((numOfData - (index - 1) >= k) && (array[numOfData - k] <= k)){
				q = k;
				break;
			}
		}
		cout << q << endl;

	}
}