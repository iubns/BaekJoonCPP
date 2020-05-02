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

	int firstNum, secondNum;
	cin >> firstNum >> secondNum;

	vector<int> primeNumbers;
	primeNumbers.push_back(2);

	for (int index = 3; index <= firstNum || index <= secondNum; index++) {
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

	int min = 1, max = 1;
	for (auto iter = primeNumbers.begin(); iter != primeNumbers.end();) {
		if (firstNum % *iter == 0 && secondNum % *iter == 0) {
			min *= *iter;
			firstNum /= *iter;
			secondNum /= *iter;
		}
		else {
			iter++;
		}
	}

	firstNum *= min;
	secondNum *= min;

	while (firstNum != 1 && secondNum != 1) {
		for (auto iter = primeNumbers.begin(); iter != primeNumbers.end();) {
			if (firstNum % *iter == 0 || secondNum % *iter == 0) {
				max *= *iter;
				if (firstNum % *iter == 0) {
					firstNum /= *iter;
				}
				if (secondNum % *iter == 0) {
					secondNum /= *iter;
				}
			}
			else {
				iter++;
			}
		}
	}

	cout << min << endl;
	cout << max << endl;
	return 0;
}