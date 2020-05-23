#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();

	long long min, max;
	cin >> min >> max;

	int arrSize = 1000 * 10000 + 1;
	int gap = max - min;

	vector<bool> numberData(arrSize, false);

	for (long long index = 2; index * index <= max; index++) {
		long long pow = index * index;

		for (long long arrIndex = (pow - (min % pow)) % pow; arrIndex <= gap; arrIndex += pow) {
			numberData[arrIndex] = true;
		}
	}

	int count = 0;
	for (int index = 0; index <= gap; index++) {
		if (numberData[index] == true) {
			count++;
		}
	}

	cout << max - min - count + 1;

	return 0;
}