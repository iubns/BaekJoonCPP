#include <iostream>
#include <set>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}


int main()
{
	init();

	int numberCount;
	cin >> numberCount;

	set<int> inputNumbers;
	for (int index = 0; index < numberCount; index++) {
		int temp;
		cin >> temp;
		inputNumbers.insert(temp);
	}

	set<int> numbers;
	for (auto iter = inputNumbers.begin(); iter != --inputNumbers.end();) {
		int first = *(iter++);
		numbers.insert(*iter - first);
	}

	int maxMultiple = *numbers.begin();
	for (auto iter = numbers.begin(); iter != numbers.end(); iter++) {
		int temp = maxMultiple;
		while (*iter % temp != 0 || maxMultiple % temp != 0) {
			temp--;
		}
		maxMultiple = temp;
	}

	int result = 0, target = *inputNumbers.begin();
	for (auto iter = inputNumbers.begin(); iter != inputNumbers.end(); iter++) {
		while (*iter > target)
		{
			target += maxMultiple;
			result++;
		}
		target += maxMultiple;
	}
	cout << result;

	return 0;
}
