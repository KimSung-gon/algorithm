#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int main() {

	ifstream inFile;
	int numOfTruck;
	int w;
	int L;
	int testCases;

	inFile.open("input.txt");
	if (inFile.fail())
		return 0;

	inFile >> testCases;

	for (int testCase = 0; testCase < testCases; testCase++) {

		inFile >> numOfTruck >> w >> L;

		int data[1001];

		for (int i = 0; i < numOfTruck; i++)
			inFile >> data[i];

		queue<int> qu;
		int temp = data[0];
		int temp1;
		qu.push(data[0]);

		int result = 1;
		for (int i = 1; i < numOfTruck; i++) {
			
			result++;
			temp1 = qu.front();

			if (temp + data[i] <= L) {
				qu.push(data[i]);
				temp += data[i];
			}
			else {
				qu.push(0);
				i--;
			}
			if (result >= w) {
				temp -= temp1;
				qu.pop();
			}
		}
		result += w;
		if (w == 1)
			result = numOfTruck+1;

		cout << result << endl;
	}
	return 0;
}