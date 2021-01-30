#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int map[101][101][101];
int main()
{
	init();

	int rowSize = 0, colSize = 0, zSize = 0;
	cin >> colSize >> rowSize >> zSize;

	int input;

	queue<vector<int>> tomatoQueue;

	for (int zIndex = 1; zIndex <= zSize; zIndex++) {
		for (int rowIndex = 1; rowIndex <= rowSize; rowIndex++) {
			for (int colIndex = 1; colIndex <= colSize; colIndex++) {
				cin >> input;
				if (input == 1) {
					tomatoQueue.push(vector<int> {rowIndex, colIndex, zIndex});
					map[rowIndex][colIndex][zIndex] = 0;
				}
				else {
					map[rowIndex][colIndex][zIndex] = input;
				}
			}
		}
	}


	int day = 0;
	while (!tomatoQueue.empty())
	{
		for (int index = tomatoQueue.size(); index > 0; index--) {
			vector<int> currentTomato = tomatoQueue.front();
			tomatoQueue.pop();

			if (map[currentTomato[0]][currentTomato[1]][currentTomato[2]]) {
				continue;
			}
			map[currentTomato[0]][currentTomato[1]][currentTomato[2]] = 1;

			if (currentTomato[0] + 1 <= rowSize)
				tomatoQueue.push(vector<int>{currentTomato[0] + 1, currentTomato[1], currentTomato[2]});

			if (currentTomato[0] - 1 > 0)
				tomatoQueue.push(vector<int>{currentTomato[0] - 1, currentTomato[1], currentTomato[2]});

			if (currentTomato[1] + 1 <= colSize)
				tomatoQueue.push(vector<int>{currentTomato[0], currentTomato[1] + 1, currentTomato[2]});

			if (currentTomato[1] - 1 > 0)
				tomatoQueue.push(vector<int>{currentTomato[0], currentTomato[1] - 1, currentTomato[2]});

			if (currentTomato[2] + 1 <= zSize)
				tomatoQueue.push(vector<int>{currentTomato[0], currentTomato[1], currentTomato[2] + 1});

			if (currentTomato[2] - 1 > 0)
				tomatoQueue.push(vector<int>{currentTomato[0], currentTomato[1], currentTomato[2] - 1});
		}
		day++;
	}

	for (int zIndex = 1; zIndex <= zSize; zIndex++) {
		for (int rowIndex = 1; rowIndex <= rowSize; rowIndex++) {
			for (int colIndex = 1; colIndex <= colSize; colIndex++) {
				if (map[rowIndex][colIndex][zIndex] == 0) {
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}


	//첫날과 마지막날 빼기
	cout << day - 2;
	return 0;
}