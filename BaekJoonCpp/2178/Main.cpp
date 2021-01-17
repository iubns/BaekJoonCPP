#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();

	int row, col;
	cin >> row >> col;

	char map[101][101];

	for (int rowIndex = 1; rowIndex <= row; rowIndex++) {
		for (int colIndex = 1; colIndex <= col; colIndex++) {
			cin >> map[rowIndex][colIndex];
		}
	}

	queue<vector<int>> postionQueue;
	postionQueue.push(vector<int> {1, 1, 1});
	while (true)
	{
		vector<int> currentPostion = postionQueue.front();
		postionQueue.pop();
		if (map[currentPostion[0]][currentPostion[1]] == '0') {
			continue;
		}
		if (currentPostion[0] == row && currentPostion[1] == col) {
			cout << currentPostion[2];
			return 0;
		}
		map[currentPostion[0]][currentPostion[1]] = '0';

		if (currentPostion[0] > 1)
			postionQueue.push(vector<int> {currentPostion[0] - 1, currentPostion[1], currentPostion[2] + 1});
		if (currentPostion[0] < row)
			postionQueue.push(vector<int> {currentPostion[0] + 1, currentPostion[1], currentPostion[2] + 1});
		if (currentPostion[1] > 1)
			postionQueue.push(vector<int> {currentPostion[0], currentPostion[1] - 1, currentPostion[2] + 1});
		if (currentPostion[1] < col)
			postionQueue.push(vector<int> {currentPostion[0], currentPostion[1] + 1, currentPostion[2] + 1});
	}

	return 0;
}