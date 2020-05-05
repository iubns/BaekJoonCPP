#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int numberCount, targetNum, result = 0;
vector<int> numbers;

void count(int size, int sum) {
	if (size == numberCount) {
		if (sum == targetNum) {
			result++;
		}
		return;
	}

	count(size + 1, sum);
	count(size + 1, sum + numbers[size]);
}

int main()
{
	init();

	cin >> numberCount >> targetNum;
	numbers.resize(numberCount);

	for (int index = 0; index < numberCount; index++) {
		cin >> numbers[index];
	}

	count(0, 0);

	if (targetNum == 0) {
		result--;
	}

	cout << result;
	return 0;
}
