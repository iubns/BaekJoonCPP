#include <iostream>
#include <vector>

/*결국은 성공, 아래의 주석 있는 2개의 배열 합치기 부분에서 막혔었음*/
using namespace std;

static vector<int> temp;

void mergeSort(int min, int max, vector<int>& numArray) {
	int gap = max - min;
	if (gap >= 3) {
		mergeSort(min, min + gap / 2, numArray);
		mergeSort(min + gap / 2 + 1, max, numArray);

		/* 두 결과 배열을 어떻게 합치지?
			새로운 배열을 또 만들어? 그럼 또 복사해?*/
		int fistSort = min;
		int mid = min + gap / 2;
		int secondSort = mid + 1;

		for (int index = 0; fistSort <= mid || secondSort <= max; index++)
		{
			if (secondSort > max) {
				temp[index] = numArray[fistSort];
				++fistSort;
				continue;
			}
			else if (fistSort > mid) {
				temp[index] = numArray[secondSort];
				++secondSort;
				continue;
			}

			if (numArray[fistSort] < numArray[secondSort]) {
				temp[index] = numArray[fistSort];
				++fistSort;
			}
			else
			{
				temp[index] = numArray[secondSort];
				++secondSort;
			}
		}

		for (int index = 0; index <= gap; index++) {
			numArray[min + index] = temp[index];
		}
	}

	if (gap == 1) {
		if (numArray[min] > numArray[max]) {
			int temp = numArray[min];
			numArray[min] = numArray[max];
			numArray[max] = temp;
		}
	}

	if (gap == 2) {
		if (numArray[min] > numArray[min + 1]) {
			int temp = numArray[min];
			numArray[min] = numArray[min + 1];
			numArray[min + 1] = temp;
		}

		if (numArray[min + 1] > numArray[max]) {
			int temp = numArray[max];
			numArray[max] = numArray[min + 1];
			numArray[min + 1] = temp;
		}

		if (numArray[min] > numArray[min + 1]) {
			int temp = numArray[min];
			numArray[min] = numArray[min + 1];
			numArray[min + 1] = temp;
		}
	}
}

int main()
{
	int arraySize;
	cin >> arraySize;
	vector<int> numArray;
	numArray.resize(arraySize);
	temp.resize(arraySize);

	for (int index = 0; index < arraySize; index++) {
		cin >> numArray[index];
	}

	mergeSort(0, arraySize - 1, numArray);

	for (int index = 0; index < arraySize; index++) {
		cout << numArray[index] << '\n';
	}
	cout << endl;

	return 0;
}