#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int arraySize;
	cin >> arraySize;
	vector<int> numArray;
	numArray.resize(arraySize);

	for (int index = 0; index < arraySize; index++) {
		cin >> numArray[index];
	}

	for (int lastIndex = arraySize - 1; lastIndex >= 0; lastIndex--) {
		for (int index = 0; index < lastIndex; index++) {
			if (numArray[index] > numArray[index + 1]) {
				int temp = numArray[index];
				numArray[index] = numArray[index + 1];
				numArray[index + 1] = temp;
			}
		}
	}

	for (int index = 0; index < arraySize; index++) {
		cout << numArray[index] << endl;
	}

	return 0;
}
