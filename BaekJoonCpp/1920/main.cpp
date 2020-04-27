#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);


	int firstArraySize, secondArraySize;
	cin >> firstArraySize;
	vector<int> firstArray, secondArray;
	firstArray.resize(firstArraySize);

	for (int index = 0; index < firstArraySize; index++) {
		cin >> firstArray[index];
	}

	cin >> secondArraySize;
	secondArray.resize(secondArraySize);

	for (int index = 0; index < secondArraySize; index++) {
		cin >> secondArray[index];
	}

	sort(firstArray.begin(), firstArray.end());

	for (int index = 0; index < secondArraySize; index++) {
		int target = secondArray[index];
		int lowIndex = 0;
		int heightIndex = firstArraySize - 1;

		while (lowIndex >= 0 && heightIndex < firstArraySize)
		{
			int gap = heightIndex - lowIndex;
			int mid = gap / 2 + lowIndex;
			if (firstArray[mid] < target) {
				lowIndex = mid + 1;
			}
			else if (firstArray[mid] > target)
			{
				heightIndex = mid - 1;
			}
			else {
				cout << '1' << '\n';
				break;
			}

			if (lowIndex > heightIndex) {
				cout << '0' << '\n';
				break;
			}
		}
		if (lowIndex < 0 || heightIndex >= firstArraySize)
		{
			if (lowIndex > heightIndex) {
				cout << '0' << '\n';
			}
		}
	}

	return 0;
}
