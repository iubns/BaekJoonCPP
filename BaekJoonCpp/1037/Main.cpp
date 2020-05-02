#include <iostream>
#include <vector>
#include <algorithm>

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

	vector<int> numbers;
	numbers.resize(numberCount);

	for (int index = 0; index < numberCount; index++) {
		cin >> numbers[index];
	}

	sort(numbers.begin(), numbers.end());

	cout << *numbers.begin() * *(numbers.end() - 1);
	return 0;
}
