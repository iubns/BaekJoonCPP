#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int mapSize, chickenCount, oldChickenCount = 0;
int map[51][51];
bool selected[14];
vector<pair<int, int>> home, chicken;
int result = INT32_MAX;

void calc() {
	if (result == 0) {
		return;
	}

	int chickenValue = 0;
	for (int homeIndex = 0; homeIndex < home.size(); homeIndex++) {
		int homeValue = INT32_MAX;
		for (int chickenIndex = 0; chickenIndex < chicken.size(); chickenIndex++) {
			if (selected[chickenIndex] == false) {
				continue;
			}
			if (homeValue > abs(chicken[chickenIndex].first - home[homeIndex].first) + abs(chicken[chickenIndex].second - home[homeIndex].second)) {
				homeValue = abs(chicken[chickenIndex].first - home[homeIndex].first) + abs(chicken[chickenIndex].second - home[homeIndex].second);
			}
		}
		chickenValue += homeValue;
	}
	if (result > chickenValue) {
		result = chickenValue;
	}
}

void chckChicken(int selectedCount, int depth) {
	if (depth == oldChickenCount) {
		if (chickenCount == selectedCount) {
			calc();
		}
		return;
	}

	selected[depth] = true;
	chckChicken(selectedCount + 1, depth + 1);
	selected[depth] = false;
	chckChicken(selectedCount, depth + 1);
}

int main()
{
	init();
	cin >> mapSize >> chickenCount;

	for (int rowIndex = 0; rowIndex < mapSize; rowIndex++) {
		for (int colIndex = 0; colIndex < mapSize; colIndex++) {
			cin >> map[rowIndex][colIndex];
			if (map[rowIndex][colIndex] == 1) {
				home.push_back(make_pair(rowIndex, colIndex));
			}
			else if (map[rowIndex][colIndex] == 2) {
				oldChickenCount++;
				chicken.push_back(make_pair(rowIndex, colIndex));
			}
		}
	}
	chckChicken(0, 0);
	cout << result;
}