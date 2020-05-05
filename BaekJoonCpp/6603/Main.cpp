#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int numberCount;
int pickNumbers[10];
int numbers[20];

void chckAndPrint(int insertCount, int depth) {
	if (depth == numberCount) {
		if (insertCount == 6) {
			for (int index = 0; index < 6; index++) {
				cout << pickNumbers[index] << (index == 5 ? '\n' : ' ');
			}
		}
		return;
	}

	if (insertCount > 6) {
		return;
	}

	pickNumbers[insertCount] = numbers[depth];
	chckAndPrint(insertCount + 1, depth + 1);
	chckAndPrint(insertCount, depth + 1);
}

int main()
{
	init();

	while (true) {

		cin >> numberCount;

		if (numberCount == 0) {
			return 0;
		}

		for (int index = 0; index < numberCount; index++) {
			cin >> numbers[index];
		}

		chckAndPrint(0, 0);
		cout << endl;
	}
}
