#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int bestPoint[1001][1001][2] = { 0, };

int main()
{
	init();

	for (int rowIndex = 0; rowIndex < 1000; rowIndex++) {
		for (int colIndex = 0; colIndex < 1000; colIndex++) {
			bestPoint[rowIndex][colIndex][0] = INT32_MAX;
			bestPoint[rowIndex][colIndex][1] = INT32_MAX;
		}
	}

	int row = 0, col = 0;

	cin >> row >> col;
	vector<vector<char>> map;

	char input;
	for (int rowIndex = 0; rowIndex < row; rowIndex++) {
		vector<char> line;
		for (int colIndex = 0; colIndex < col; colIndex++) {
			cin >> input;
			line.push_back(input);
		}
		map.push_back(line);
	}

	queue<vector<int>> postionQueue;
	postionQueue.push(vector<int>{0, 0, 0, 0}); // row, col, block, point

	while (!postionQueue.empty())
	{
		auto currentPostion = postionQueue.front();
		postionQueue.pop();

		if (bestPoint[currentPostion[0]][currentPostion[1]][0] < INT32_MAX) {
			continue;
		}

		if (bestPoint[currentPostion[0]][currentPostion[1]][1] < INT32_MAX && currentPostion[2]) {
			continue;
		}

		if (currentPostion[2] > 1) {
			continue;
		}

		if (currentPostion[2] == 0) {
			bestPoint[currentPostion[0]][currentPostion[1]][0] = currentPostion[3] + 1;
		}
		else {
			bestPoint[currentPostion[0]][currentPostion[1]][1] = currentPostion[3] + 1;
		}

		if (currentPostion[0] > 0) {
			postionQueue.push(vector<int> {currentPostion[0] - 1, currentPostion[1], currentPostion[2] + map[currentPostion[0] - 1][currentPostion[1]] - 48, currentPostion[3] + 1});
		}
		if (currentPostion[1] > 0) {
			postionQueue.push(vector<int> {currentPostion[0], currentPostion[1] - 1, currentPostion[2] + map[currentPostion[0]][currentPostion[1] - 1] - 48, currentPostion[3] + 1});
		}
		if (currentPostion[0] < row - 1) {
			postionQueue.push(vector<int> {currentPostion[0] + 1, currentPostion[1], currentPostion[2] + map[currentPostion[0] + 1][currentPostion[1]] - 48, currentPostion[3] + 1});
		}
		if (currentPostion[1] < col - 1) {
			postionQueue.push(vector<int> {currentPostion[0], currentPostion[1] + 1, currentPostion[2] + map[currentPostion[0]][currentPostion[1] + 1] - 48, currentPostion[3] + 1});
		}
	}

	int result = min(bestPoint[row - 1][col - 1][0], bestPoint[row - 1][col - 1][1]);
	cout << (result == INT32_MAX ? -1 : result) << endl;
	return 0;
}