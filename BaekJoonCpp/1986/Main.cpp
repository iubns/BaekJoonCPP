#include <iostream>
#include <vector>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

vector<vector<char>> board;
void check(int currentX, int currentY, int increseX, int increseY, bool loop) {
	if (currentX < 0 || currentX >= board.size() || currentY < 0 || currentY >= board[0].size()) {
		return;
	}
	switch (board[currentX][currentY]) {
	case 'T':
	case 'F':
		board[currentX][currentY] = 'F';
		if (loop) {
			check(currentX + increseX, currentY + increseY, increseX, increseY, loop);
		}
		break;
	case 'Q':
	case 'P':
	case 'K':
		return;
	}
}

void queen(int x, int y) {
	check(x - 1, y - 1, -1, -1, true);
	check(x - 1, y + 0, -1, 0, true);
	check(x - 1, y + 1, -1, 1, true);
	check(x + 0, y - 1, 0, -1, true);
	check(x + 0, y + 1, 0, 1, true);
	check(x + 1, y - 1, 1, -1, true);
	check(x + 1, y + 0, 1, 0, true);
	check(x + 1, y + 1, 1, 1, true);
}

void knight(int x, int y) {
	check(x + 1, y + 2, 1, 2, false);
	check(x - 1, y + 2, -1, 2, false);
	check(x + 1, y - 2, 1, -2, false);
	check(x - 1, y - 2, -1, -2, false);
	check(x + 2, y + 1, 2, 1, false);
	check(x - 2, y + 1, -2, 1, false);
	check(x + 2, y - 1, 2, -1, false);
	check(x - 2, y - 1, -2, -1, false);
}

int main()
{
	init();
	int x, y;
	cin >> y >> x;

	for (int index = 0; index < y; index++) {
		vector<char> row(x, 'T');
		board.push_back(row);
	}

	for (int i = 0; i < 3; i++) {
		int count;
		cin >> count;
		for (int index = 0; index < count; index++) {
			int postionX, postionY;
			cin >> postionX >> postionY;
			postionX -= 1;
			postionY -= 1;
			switch (i)
			{
			case 0:
				board[postionX][postionY] = 'Q';
				break;
			case 1:
				board[postionX][postionY] = 'K';
				break;
			case 2:
				board[postionX][postionY] = 'P';
				break;
			default:
				break;
			}
		}
	}

	for (int row = 0; row < y; row++) {
		for (int col = 0; col < x; col++) {
			switch (board[row][col])
			{
			case 'T':
			case 'F':
			case 'P':
				continue;
				break;
			case 'Q':
				queen(row, col);
				break;
			case 'K':
				knight(row, col);
				break;
			default:
				break;
			}
		}
	}

	int result = 0;
	for (int row = 0; row < y; row++) {
		for (int col = 0; col < x; col++) {
			if (board[row][col] == 'T')
			{
				result++;
			}
		}

	}
	cout << result << endl;
	return 0;
}