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
	int numberCount;
	cin >> numberCount;
	countArray.resize(10001);

	for (int index = 0; index < numberCount; index++) {
		int inputNum;
		cin >> inputNum;
		countArray[inputNum]++;
	}

	for (int colIndex = 0; colIndex < 10001; colIndex++) {
		while (countArray[colIndex]-- > 0)
		{
			cout << colIndex << '\n';
		}
	}
	return 0;
}
