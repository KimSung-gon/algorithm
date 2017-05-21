#include <stdlib.h>
#include <iostream>
#include <fstream>
using namespace std;

int arr1[1000], arr2[1000];
int arr3[1000][1000];
int arr4[1000][1000];

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
		for (int j = 1; j <= numOfData; j++) {
			arr3[j - 1][j] = 0;
			arr4[j - 1][j] = j;
		}
		for (int j = 2; j <= numOfData; j++)
			for (int k = 0; k + j <= numOfData; k++) {
				int temp = k + j;
				arr3[k][temp] = 2e9;
				int start = arr4[k][temp - 1];
				int end = arr4[k + 1][temp];
				for (int l = start; l <= end; l++) {
					int temp2 = arr3[k][l] + arr3[l][temp] + arr2[temp] - arr2[k];
					if (arr3[k][temp] > temp2) {
						arr3[k][temp] = temp2;
						arr4[k][temp] = l;
					}
				}
			}
		cout << arr3[0][numOfData] << endl;
	}
	return 0;
}