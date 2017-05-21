#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

class statOfTeam {

private:
	int getScore;
	int loseScore;

public:
	statOfTeam() {
		this->getScore = 0;
		this->loseScore = 0;
	}

	void addStat(int getScore, int loseScore) {
		this->getScore += getScore;
		this->loseScore += loseScore;
	}

	double respectValue() {
		return pow(this->getScore, 2.0) / (pow(this->getScore, 2.0) + pow(this->loseScore, 2.0));
	}
};

double returnMax(statOfTeam arrayOfTeam[], int numOfTeam);
double returnMin(statOfTeam arrayOfTeam[], int numOfTeam);

double returnMax(statOfTeam arrayOfTeam[], int numOfTeam) {
	double Max = arrayOfTeam[0].respectValue();
	for (int i = 1; i < numOfTeam; i++) {
		if (arrayOfTeam[i].respectValue() > Max)
			Max = arrayOfTeam[i].respectValue();
	}
	return Max;
}

double returnMin(statOfTeam arrayOfTeam[], int numOfTeam) {
	double Min = arrayOfTeam[0].respectValue();
	for (int i = 1; i < numOfTeam; i++) {
		if (arrayOfTeam[i].respectValue() < Min)
			Min = arrayOfTeam[i].respectValue();
	}
	return Min;
}

int main() {

	ifstream inFile;
	int testCases;
	int numOfTeam;
	int numOfPlay;

	inFile.open("input.txt");

	if (inFile.fail())
		return 0;

	inFile >> testCases;

	for (int i = 0; i < testCases; i++) {

		inFile >> numOfTeam >> numOfPlay;

		statOfTeam *arrayOfTeam = new statOfTeam[numOfTeam];
		
		for (int k = 0; k < numOfPlay; k++) {
			
			int teamA, teamB, teamAGetScore, teamBGetScore;
			inFile >> teamA >> teamB >> teamAGetScore >> teamBGetScore;
			arrayOfTeam[teamA-1].addStat(teamAGetScore, teamBGetScore);
			arrayOfTeam[teamB-1].addStat(teamBGetScore, teamAGetScore);
		}
		cout << int(returnMax(arrayOfTeam, numOfTeam) * 1000) << endl;
		cout << int(returnMin(arrayOfTeam, numOfTeam) * 1000) << endl;
	}
	inFile.close();
	return 0;
}