#include <iostream>
#include <vector>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int numCount = 0;
bool result = false;
int current[81];

bool check(int depth) {
	if (result) {
		return false;
	}

	if (depth == numCount) {
		for (int index = 0; index < numCount; index++) {
			cout << current[index];
			result = true;
		}
	}

	for (int gap = 1; gap <= (depth / 2) + 1; gap++) {
		for (int col = depth; 0 <= col; col--) {
			if (current[col] != current[col - gap]) {
				break;
			}
			if (col == depth - gap + 1) {
				return false;
			}
		}
	}
	return true;
}

void newNumbers(int depth) {
	if (result) {
		return;
	}

	if (depth > numCount) {
		return;
	}

	for (int index = 1; index <= 3; index++) {
		current[depth] = index;
		if (check(depth)) {
			newNumbers(depth + 1);
		}
	}
}

int main()
{
	init();

	cin >> numCount;

	newNumbers(0);

}