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

	vector<int> haveNums;
	int arraySize;
	cin >> arraySize;
	haveNums.resize(arraySize);

	for (int index = 0; index < arraySize; index++) {
		cin >> haveNums[index];
	}

	sort(haveNums.begin(), haveNums.end());

	int targetArraySize;
	cin >> targetArraySize;

	for (int index = 0; index < targetArraySize; index++) {
		int minindex = 0;
		int maxIndex = arraySize - 1;
		int target;
		cin >> target;
		while (maxIndex >= minindex && minindex >= 0 && maxIndex < arraySize) {
			int midIndex = (maxIndex - minindex) / 2 + minindex;
			if (haveNums[midIndex] > target) {
				maxIndex = midIndex - 1;
			}
			else if (haveNums[midIndex] < target) {
				minindex = midIndex + 1;
			}
			else {
				cout << 1 << ' ';
				break;
			}
		}
		if (maxIndex < minindex || minindex < 0 || maxIndex >= arraySize) {
			cout << 0 << ' ';
		}
	}

	return 0;
}
