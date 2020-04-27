#include <iostream>
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

	vector<int> countArray;
	countArray.resize(2003);

	int numberCount;
	cin >> numberCount;

	int input;
	for (int index = 0; index < numberCount; index++) {
		cin >> input;
		countArray[input + 1000]++;
	}

	for (int index = 0; index < 2003; index++) {
		if (countArray[index] > 0) {
			cout << index - 1000 << ' ';
		}
	}

	return 0;
}
