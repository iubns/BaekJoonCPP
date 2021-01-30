#include <iostream>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int map[128][128] = { 0, };
int mapSizeInput = 0, drainXpostion = 0, drainYposition = 0;
int tileNumber = 1;

void fillMap(int mapType, int mapSize, int x, int y) {
	if (mapSize > 0) {
		fillMap(1, mapSize - 1, x, y);
		fillMap(2, mapSize - 1, x / 2, y);
		fillMap(3, mapSize - 1, x, y / 2);
		fillMap(4, mapSize - 1, x / 2, y / 2);
	}
	else if () {

	}
	else {
		if (mapType == 1) {
			map[x][y] = tileNumber;
			map[x + 1][y] = tileNumber;
			map[x][y + 1] = tileNumber;
		}
		else if (mapType == 2) {
			map[x][y] = tileNumber;
			map[x + 1][y] = tileNumber;
			map[x + 1][y + 1] = tileNumber;
		}
		else if (mapType == 3) {
			map[x][y] = tileNumber;
			map[x][y + 1] = tileNumber;
			map[x + 1][y + 1] = tileNumber;
		}
		else if (mapType == 4) {
			map[x + 1][y] = tileNumber;
			map[x][y + 1] = tileNumber;
			map[x + 1][y + 1] = tileNumber;
		}
		tileNumber++;
	}
}


int main()
{
	init();


	cin >> mapSizeInput >> drainXpostion >> drainYposition;

	fillMap(1, mapSizeInput - 1, drainXpostion, drainYposition);
	fillMap(2, mapSizeInput - 1, drainXpostion / 2, drainYposition);
	fillMap(3, mapSizeInput - 1, drainXpostion, drainYposition / 2);
	fillMap(4, mapSizeInput - 1, drainXpostion / 2, drainYposition / 2);

	map[drainXpostion - 1][drainYposition - 1] = -1;

	for (int xIndex = 0; xIndex < pow(2, mapSizeInput); xIndex++) {
		for (int yIndex = 0; yIndex < pow(2, mapSizeInput); yIndex++) {
			cout << map[yIndex][xIndex] << ' ';
		}
		cout << endl;
	}

	return 0;
}