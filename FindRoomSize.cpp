#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void findWay(char **array, int row, int col, int &count);
int* append(int array[], int numOfRoom, int findWay);

int count;

void findWay(char **array, int row, int col, int &count) {

	array[row][col] = '+';
	count++;

	if ((array[row][col + 1] == '+') && (array[row + 1][col] == '+') && (array[row][col - 1] == '+') && (array[row - 1][col] == '+')
		&& (array[row][col + 1] != NULL) && (array[row][col - 1] != NULL) && (array[row + 1][col] != NULL) && (array[row - 1][col] != NULL))
		return;

	if ((array[row][col + 1] != '+') && (array[row][col + 1] != NULL))
		findWay(array, row, col + 1, count);
	if ((array[row + 1][col] != '+') && (array[row + 1][col] != NULL))
		findWay(array, row + 1, col, count);
	if ((array[row][col - 1] != '+') && (array[row][col - 1] != NULL))
		findWay(array, row, col - 1, count);
	if ((array[row - 1][col] != '+') && (array[row - 1][col] != NULL))
		findWay(array, row - 1, col, count);
	return;
}

int* append(int array[], int numOfRoom, int findWay) {
	int *temp = new int[numOfRoom];
	for (int i = 0; i < numOfRoom; i++)
		temp[i] = array[i];
	temp[numOfRoom-1] = findWay;
	return temp;
}

int main() {
	ifstream inFile;
	inFile.open("input.txt");

	if (inFile.fail())
		return 0;

	int testCases;
	inFile >> testCases;

	for (int i = 0; i < testCases; i++) {
		int col;
		int row;
		inFile >> col >> row;

		char **arr = new char*[100];
		for (int j = 0; j < 100; j++)
			arr[j] = new char[100];

		inFile.getline(arr[0], col+1);
		for (int j = 0; j < row; j++) 
			inFile.getline(arr[j], col+1);
		
		
		int numOfRoom = 0;
		int count = 0;
		int* result = new int[1];
		result[0] = 0;
		for (int j = 0; j < row; j++) {
			for (int k = 0; k < col; k++) {
				if (arr[j][k] != '+') {
					findWay(arr, j, k, count);
					numOfRoom++;
					result = append(result, numOfRoom+1, count);
				}
				count = 0;
			}
		}
		delete arr;
		sort(result, result + numOfRoom +1);

		cout << numOfRoom << endl;

		for (int j = numOfRoom; j > 0; j--)
			cout << result[j] << " ";
		cout << endl;
		delete result;
	}

	inFile.close();
	return 0;
}