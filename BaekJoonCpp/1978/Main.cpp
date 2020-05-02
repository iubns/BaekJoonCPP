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

	vector<int> primeNumbers;
	primeNumbers.push_back(2);

	for (int index = 3; index <= 1000; index++) {
		for (auto primeIter = primeNumbers.begin(); primeIter != primeNumbers.end(); primeIter++) {
			if (index % *primeIter == 0) {
				break;
			}
			if (*primeIter == primeNumbers.back()) {
				primeNumbers.push_back(index);
				break;
			}
		}
	}

	int numberCount;
	cin >> numberCount;

	int result = 0;
	for (int index = 0; index < numberCount; index++) {
		int target;
		cin >> target;
		if (find(primeNumbers.begin(), primeNumbers.end(), target) != primeNumbers.end()) {
			result++;
		}
	}

	cout << result;
	return 0;
}
