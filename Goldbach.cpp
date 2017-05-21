#include <iostream>
#include <fstream>
using namespace std;
void divideTwo(int arr1[], int data, int count);
int *makeNumArr(int *arr);

void divideTwo(int arr1[], int data, int count) {
	int temp = 0;
	int temp1 = 0;
	int output1 = 0;
	int output2 = 0;
	int min = 1000;

	for (int i = 0; i < count; i++) {
		if (data > arr1[i]) {
			temp = data - arr1[i];
			for (int j = 0; j < count; j++) {
				temp1 = arr1[i] - arr1[j];
				if (temp1 < 0)
					temp1 = -temp1;
				if ((temp == arr1[j]) && (temp1 < min)) {
					min = arr1[j] - arr1[i];
					if (min < 0)
						min = -min;
					output1 = arr1[i];
					output2 = arr1[j];
				}
			}
		}
	}
	cout << output1 << " " << output2 << endl;
}

int *makeNumArr(int *arr) {
	
	for (int i = 2; i < 1000; i++) {
		for (int j = 2; j*i < 1001; j++) {
			arr[i*j] = 0;
		}
	}
	return arr;
}

int main() {

	ifstream inFile;
	int testCases;

	inFile.open("input.txt");
	if (inFile.fail())
		return 0;

	inFile >> testCases;

	int arr[1001];
	for (int i = 0; i < 1001; i++)
		arr[i] = i;
	arr[0] = 0;
	arr[1] = 0;

	makeNumArr(arr);

	int count = 0;

	for (int i = 0; i < 1001; i++)
		if (arr[i] != 0) 
			count++;
	
	int *arr1 = new int[count];
	count = 0;
	for (int i = 0; i < 1001; i++) {
		if (arr[i] != 0) {
			arr1[count] = arr[i];
			count++;
		}
	}
	for (int i = 0; i < testCases; i++) {
		int data;
		inFile >> data;
		divideTwo(arr1, data, count);
	}

	return 0;
}