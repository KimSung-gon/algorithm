#include <iostream>
#include <fstream>
using namespace std;

int partition(int a[], int low, int high);
void quickSort(int v[], int low, int high);
int partition(int a[], int low, int high)
{
	int i, j;
	int pivot, pivotPos, tmp;
	pivot = a[low];
	j = low;
	for (i = low + 1; i <= high; i++)
	{
		if (a[i] < pivot)
		{
			j++;
			/* swap */
			tmp = a[i]; a[i] = a[j]; a[j] = tmp;
		}
	}
	pivotPos = j;
	tmp = a[low]; a[low] = a[pivotPos]; a[pivotPos] = tmp;
	return pivotPos;
}
void quickSort(int v[], int low, int high)
{
	int pivotPos;
	if (high > low)
	{
		pivotPos = partition(v, low, high);
		quickSort(v, low, pivotPos - 1);
		quickSort(v, pivotPos + 1, high);
	}
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

		quickSort(arr, 0, numOfData - 1);

		for (int j = 0; j < numOfData; j++)
			cout << arr[j] << " ";
		cout << endl;
	}
	return 0;
}