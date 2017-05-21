#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {

	int numOfCases;
	cin >> numOfCases;
    
	int num1, num2, result;
	int value;
	char sign, equal;
	int arr1[10000];
	int arr2[10000];

	for (int i = 0; i < numOfCases; i++)
	{
		// cin >> num1 >> sign >> num2 >> equal >> result;
		scanf_s("%d %c %d %c %d", &num1, &sign, &num2, &equal, &result);
		if (sign == '+')
			value = num1 + num2;
		else if(sign == '-')
			value = num1 - num2;
		else if (sign == '*')
			value = num1 * num2;
		else
			value = num1 / num2;  // ¼ÒÆÃ
		
		arr1[i] = value;
		arr2[i] = result;
	}

	for (int i = 0; i < numOfCases; i++)
	{
		if (arr1[i] == arr2[i])
			cout << "correct" << endl;
		else
			cout << "wrong answer" << endl;
	}

	return 0;
}