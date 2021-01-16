#include <iostream>
#include <vector>
#include <list>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int mapSize;
char map[25][25];

int findSide(int x, int y) {
	map[y][x] = '0';
	int count = 0;

	for (int yIndex = -1; yIndex <= 1; yIndex++) {
		for (int xIndex = -1; xIndex <= 1; xIndex++) {
			if (yIndex + xIndex == 0 || yIndex + xIndex == 2 || yIndex + xIndex == -2) {
				continue;
			}

			if (x + xIndex < 0 || x + xIndex >= mapSize) {
				continue;
			}
			if (y + yIndex < 0 || y + yIndex >= mapSize) {
				continue;
			}


			if (map[y + yIndex][x + xIndex] == '1') {
				count += findSide(x + xIndex, y + yIndex);
			}
		}
	}

	return count + 1;
}

int main()
{
	init();

	cin >> mapSize;

	for (int rowIndex = 0; rowIndex < mapSize; rowIndex++) {
		for (int colIndex = 0; colIndex < mapSize; colIndex++) {
			cin >> map[rowIndex][colIndex];
		}
	}

	list<int> houseSize;
	for (int rowIndex = 0; rowIndex < mapSize; rowIndex++) {
		for (int colIndex = 0; colIndex < mapSize; colIndex++) {
			if (map[rowIndex][colIndex] == '1') {
				houseSize.push_back(findSide(colIndex, rowIndex));
			}
		}
	}

	houseSize.sort();
	cout << houseSize.size() << endl;
	for (auto iter = houseSize.begin(); iter != houseSize.end(); iter++) {
		cout << *iter << endl;
	}

	return 0;
}