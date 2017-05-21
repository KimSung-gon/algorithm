#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

int main() {

	ifstream inFile;
	int testCases;

	inFile.open("input.txt");

	if (inFile.fail())
		return 0;

	inFile >> testCases;

	for (int i = 0; i < testCases; i++) {
		string checkVPS;
		inFile >> checkVPS;
		int check = 0;
		int checkUsed = 0;
		int checkOther = 0;
		int checkFirst = 0;
		int checkLast = 0;
		if (checkVPS[0] == ')')
			checkFirst++;
		if (checkVPS[checkVPS.length() - 1] == '(')
			checkLast++;
		for (int j = 0; j<checkVPS.length(); j++) {
			if ((checkVPS[j] == '(') || (checkVPS[j] == ')')) {
				checkUsed++;
				if (checkVPS[j] == '(')
					check++;
				else if (checkVPS[j] == ')')
					check--;
			}
			else
				checkOther++;
		}
		if ((check == 0) && (checkUsed != 0) && (checkOther == 0) && (checkFirst == 0) && (checkLast == 0))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	inFile.close();
	return 0;
}