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

int numberCount, targetNum;
set<vector<int>> findSet;

void eraseAndCount(vector<int> numbers) {
	if (numbers.size() <= 0) {
		return;
	}

	for (int index = 0; index < numbers.size(); index++) {
		auto iter = numbers.begin() + index;
		int value = *iter;
		numbers.erase(iter);
		eraseAndCount(numbers);
		numbers.insert(numbers.begin() + index, value);
	}

	int sum = 0;
	for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
		sum += *iter;
	}

	if (sum == targetNum) {
		sort(numbers.begin(), numbers.end());
		findSet.insert(numbers);
	}
}

int main()
{
	init();

	cin >> numberCount >> targetNum;
	vector<int> numbers;
	numbers.resize(numberCount);

	for (int index = 0; index < numberCount; index++) {
		cin >> numbers[index];
	}

	eraseAndCount(numbers);

	cout << findSet.size();
	return 0;
}
