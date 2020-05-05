#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int peopleCount, result = INT32_MAX;
int peoplesData[20][20];
bool insertPeople[20];

void sum()
{
	int startTeamScore = 0;
	int linkTeamScore = 0;
	for (int row = 0; row < peopleCount; row++) {
		for (int col = 0; col < peopleCount; col++) {
			if (insertPeople[row] && insertPeople[col]) {
				startTeamScore += peoplesData[row][col];
			}
			if (!insertPeople[row] && !insertPeople[col]) {
				linkTeamScore += peoplesData[row][col];
			}
		}
	}
	int gap = linkTeamScore - startTeamScore;
	if (gap < 0) {
		gap *= -1;
	}
	if (result > gap) {
		result = gap;
	}
}

void insert(int insertCount, int count) {
	if (count == peopleCount) {
		if (insertCount == peopleCount / 2) {
			sum();
		}
		return;
	}

	if (insertCount > peopleCount / 2) {
		return;
	}

	if (result == 0) {
		result;
	}

	insertPeople[count] = true;
	insert(insertCount + 1, count + 1);
	insertPeople[count] = false;
	insert(insertCount, count + 1);
}

int main()
{
	init();

	cin >> peopleCount;

	for (int row = 0; row < peopleCount; row++) {
		for (int col = 0; col < peopleCount; col++) {
			cin >> peoplesData[row][col];
		}
	}

	insert(0, 0);


	cout << result;
	return 0;
}
