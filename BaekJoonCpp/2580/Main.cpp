#include <iostream>
#include <vector>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

vector<vector<int>> map;

int findRowValue(int rowSeq) {
	int check[10] = { 0, };
	int value = 0, zeroIndex = 0;

	for (int index = 1; index < 10; index++) {
		int focus = map[rowSeq][index];
		if (check[focus]) {
			//0ÀÌ 2°³ ³ª¿È.
			return 0;
		}
		check[focus] = 1;
		if (focus == 0) {
			zeroIndex = index;
		}
	}

	for (int index = 1; index < 10; index++) {
		if (check[index] == 0) {
			map[rowSeq][zeroIndex] = index;
		}
	}
	return 1;
}

int findColValue(int colSeq) {
	int check[10] = { 0, };
	int value = 0, zeroIndex = 0;

	for (int index = 1; index < 10; index++) {
		int focus = map[index][colSeq];
		if (check[focus]) {
			//0ÀÌ 2°³ ³ª¿È.
			return 0;
		}
		check[focus] = 1;
		if (focus == 0) {
			zeroIndex = index;
		}
	}

	for (int index = 1; index < 10; index++) {
		if (check[index] == 0) {
			map[zeroIndex][colSeq] = index;
		}
	}
	return 1;
}

int findBoxValue(int rowSeq, int colSeq) {
	int check[10] = { 0, };
	int value = 0, zeroRowIndex = 0, zeroColIndex = 0;

	for (int rowIndex = rowSeq * 3 + 1; rowIndex < (rowSeq + 1) * 3 + 1; rowIndex++) {
		for (int colIndex = colSeq * 3 + 1; colIndex < (colSeq + 1) * 3 + 1; colIndex++) {
			int focus = map[rowIndex][colIndex];
			if (check[focus]) {
				//0ÀÌ 2°³ ³ª¿È.
				return 0;
			}
			check[focus] = 1;
			if (focus == 0) {
				zeroRowIndex = rowIndex;
				zeroColIndex = colIndex;
			}
		}
	}

	for (int index = 1; index < 10; index++) {
		if (check[index] == 0) {
			map[zeroRowIndex][zeroColIndex] = index;
		}
	}
	return 1;
}

int main()
{
	init();

	map.push_back(vector<int>());
	int input;
	for (int rowIndex = 1; rowIndex <= 9; rowIndex++) {
		vector<int> line;
		line.push_back(-1);
		for (int colIndex = 1; colIndex <= 9; colIndex++) {
			cin >> input;
			line.push_back(input);
		}
		map.push_back(line);
	}

	while (true)
	{
		bool findVueValue = false;
		for (int rowIndex = 1; rowIndex < 10; rowIndex++) {
			for (int colIndex = 1; colIndex < 10; colIndex++) {
				if (map[rowIndex][colIndex] == 0) {
					if (findRowValue(rowIndex) || findColValue(colIndex) || findBoxValue((rowIndex - 1) / 3, (colIndex - 1) / 3)) {
						colIndex--;
						findVueValue = true;
					}
				}
			}
		}
		if (!findVueValue) {
			break;
		}
	}

	for (int rowIndex = 1; rowIndex < 10; rowIndex++) {
		for (int colIndex = 1; colIndex < 10; colIndex++) {
			cout << map[rowIndex][colIndex] << ' ';
		}
		cout << endl;
	}

	return 0;
}