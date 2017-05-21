#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

struct Z {
	int a, b;
} A[100001];

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

		for (int j = 1; j <= numOfData; j++) {
			infile >> A[j].a >> A[j].b;
			if (A[j].a > A[j].b) swap(A[j].a, A[j].b);
		}
		int L;
		infile >> L;
		sort(A + 1, A + numOfData + 1, [](const Z &a, const Z &b) {
			return a.b < b.b;
		});
		priority_queue <int> que;
		int result = 0;
		for (int j = 1; j <= numOfData; j++) {
			que.push(-A[j].a);
			while (!que.empty() && -que.top() < A[j].b - L)
				que.pop();
			result = max(result, (int)(que).size());
		}
		cout << result << endl;
	}
	return 0;
}
