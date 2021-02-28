#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();

	int row = 0, col = 0, count = 0;

	int map[100][100] = { 0, };

	cin >> row >> col >> count;

	for (int index = 0; index < count; index++) {
		int leftX, leftY, rightX, rightY;
		cin >> leftX >> leftY >> rightX >> rightY;
		for (int xIndex = leftX; xIndex < rightX; xIndex++) {
			for (int yIndex = leftY; yIndex < rightY; yIndex++) {
				map[yIndex][xIndex] = 1;
			}
		}
	}

	vector<int> sizes;

	for (int xIndex = 0; xIndex < col; xIndex++) {
		for (int yIndex = 0; yIndex < row; yIndex++) {
			if (map[yIndex][xIndex] == 0) {
				queue<vector<int>> checkQueue;
				int sizeCount = 0;
				checkQueue.push(vector<int>{yIndex, xIndex});
				while (!checkQueue.empty())
				{
					auto current = checkQueue.front();
					checkQueue.pop();
					if (map[current[0]][current[1]] != 0) {
						continue;
					}

					map[current[0]][current[1]] = -1;
					sizeCount++;
					if (current[0] > 0) {
						checkQueue.push(vector<int>{current[0] - 1, current[1]});
					}
					if (current[1] > 0) {
						checkQueue.push(vector<int>{current[0], current[1] - 1});
					}
					if (current[0] < row - 1) {
						checkQueue.push(vector<int>{current[0] + 1, current[1]});
					}
					if (current[1] < col - 1) {
						checkQueue.push(vector<int>{current[0], current[1] + 1});
					}
				}

				sizes.push_back(sizeCount);
			}
		}
	}

	sort(sizes.begin(), sizes.end());

	cout << sizes.size() << endl;
	for (auto iter = sizes.begin(); iter != sizes.end(); iter++) {
		cout << *iter << ' ';
	}

	return 0;
}