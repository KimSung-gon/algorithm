#include <iostream>
#include <fstream>

using namespace std;

int max(int a, int b);

int max(int a, int b) {
	return (a > b) ? a : b;
}

int arr[(1 << 21) + 1];

int makeBiggestSum(int numOfData, int loc) {

	int left = 2 * loc + 1;
	int right = 2 * loc + 2;

	if (left > numOfData || right > numOfData) 
		return arr[loc];

	int leftSum = makeBiggestSum(numOfData, left);
	int rightSum = makeBiggestSum(numOfData, right);

	if (leftSum < rightSum) {
		arr[left] += rightSum - leftSum;
	}
	else if (leftSum > rightSum) {
		arr[right] += leftSum - rightSum;
	}

	return arr[loc] + max(leftSum, rightSum);
}

int main() {
	
	fstream infile;
	infile.open("input.txt");
	if (infile.fail())
		return 0;

	int numOfCases;
	infile >> numOfCases;

	for (int i = 0; i < numOfCases; i++) {

		int data;
		infile >> data;

		int numOfData;
		numOfData = (1 << (data + 1)) - 2;

		for (int i = 1; i <= numOfData; ++i)
			infile >> arr[i];

		makeBiggestSum(numOfData, 0);

		int result = 0;

		for (int i = 1; i <= numOfData; ++i) 
			result += arr[i];
		cout << result << endl;
	}
	return 0;
}