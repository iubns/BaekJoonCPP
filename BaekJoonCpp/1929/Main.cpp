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

	int startNum, endNum;
	cin >> startNum >> endNum;

	vector<int> primeNumbers;
	primeNumbers.push_back(2);

	for (int index = 3; index <= endNum; index++) {
		for (auto primeIter = primeNumbers.begin(); primeIter != primeNumbers.end(); primeIter++) {
			if (index % *primeIter == 0) {
				break;
			}
			if (*primeIter == primeNumbers.back()) {
				primeNumbers.push_back(index);
				break;
			}
			if (*primeIter * *primeIter > index) {
				primeNumbers.push_back(index);
				break;
			}
		}
	}

	for (auto iter = primeNumbers.begin(); iter != primeNumbers.end(); iter++) {
		if (startNum <= *iter && *iter <= endNum) {
			cout << *iter << '\n';
		}
	}
	return 0;
}
