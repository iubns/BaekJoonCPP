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

vector<string> results;
void erasePrint(vector<int> numbers) {
	if (numbers.size() <= 6) {
		string result = "";
		for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
			result += to_string(*iter) + (iter != numbers.end() - 1 ? ' ' : '\n');
		}
		results.push_back(result);
		return;
	}
	else
	{
		for (int index = numbers.size() - 1; index >= 0; index--) {
			auto iter = numbers.begin() + index;
			int value = *iter;
			numbers.erase(iter);
			erasePrint(numbers);
			numbers.insert(numbers.begin() + index, value);
		}
	}

}

int main()
{
	init();

	while (true)
	{
		int numberCount;
		cin >> numberCount;

		if (numberCount == 0) {
			return 0;
		}

		vector<int> numbers;
		numbers.resize(numberCount);
		for (int index = 0; index < numberCount; index++) {
			cin >> numbers[index];
		}

		erasePrint(numbers);
		sort(results.begin(), results.end());
		cout << results[0];
		for (auto iter = results.begin() + 1; iter != results.end(); iter++) {
			if (*(iter - 1) == *iter) {
				continue;
			}
			cout << *iter;
		}

		cout << endl;

	}

	return 0;
}
