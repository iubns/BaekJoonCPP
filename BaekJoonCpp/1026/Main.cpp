#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();

	vector<int> firstArray;
	vector<int> secondArray;

	int arraySize;
	cin >> arraySize;

	firstArray.resize(arraySize);
	secondArray.resize(arraySize);

	for (int index = 0; index < arraySize; index++) {
		cin >> firstArray[index];
	}

	for (int index = 0; index < arraySize; index++) {
		cin >> secondArray[index];
	}

	sort(firstArray.begin(), firstArray.end());
	reverse(firstArray.begin(), firstArray.end());
	sort(secondArray.begin(), secondArray.end());

	int result = 0;

	for (int index = 0; index < arraySize; index++) {
		result += firstArray[index] * secondArray[index];
	}

	cout << result;

	return 0;
}
