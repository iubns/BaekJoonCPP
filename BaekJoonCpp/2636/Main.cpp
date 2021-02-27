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

	int row = 0, col = 0;

	int map[100][100];
	cin >> row >> col;
	for (int rowIndex = 0; rowIndex < row; rowIndex++) {
		for (int colIndex = 0; colIndex < col; colIndex++) {
			cin >> map[rowIndex][colIndex];
		}
	}

	for (int time = 0; ; time++)
	{
		queue<vector<int>> removeQueue;
		removeQueue.push(vector<int>{0, 0});
		while (!removeQueue.empty())
		{
			vector<int> cell = removeQueue.front();
			removeQueue.pop();

			if (map[cell[0]][cell[1]] == 1) {
				map[cell[0]][cell[1]] = 2;
				continue;
			}

			if (map[cell[0]][cell[1]] != 0) {
				continue;
			}

			map[cell[0]][cell[1]] = -1;

			if (cell[0] > 0) {
				removeQueue.push(vector<int>{cell[0] - 1, cell[1]});
			}
			if (cell[1] > 0) {
				removeQueue.push(vector<int>{cell[0], cell[1] - 1});
			}
			if (cell[0] < row - 1) {
				removeQueue.push(vector<int>{cell[0] + 1, cell[1]});
			}
			if (cell[1] < col - 1) {
				removeQueue.push(vector<int>{cell[0], cell[1] + 1});
			}
		}

		bool isCheese = false;
		for (int rowIndex = 0; rowIndex < row; rowIndex++) {
			for (int colIndex = 0; colIndex < col; colIndex++) {
				if (map[rowIndex][colIndex] == 1) {
					isCheese = true;
					break;
				}
			}
			if (isCheese) {
				break;
			}
		}

		if (isCheese == false) {
			int count = 0;
			for (int rowIndex = 0; rowIndex < row; rowIndex++) {
				for (int colIndex = 0; colIndex < col; colIndex++) {
					if (map[rowIndex][colIndex] > 0) {
						count++;
					}
				}
			}
			cout << time + 1 << endl;
			cout << count << endl;
			return 0;
		}

		for (int rowIndex = 0; rowIndex < row; rowIndex++) {
			for (int colIndex = 0; colIndex < col; colIndex++) {
				if (map[rowIndex][colIndex] == -1 || map[rowIndex][colIndex] == 2) {
					map[rowIndex][colIndex] = 0;
				}
			}
		}
	}

	return 0;
}