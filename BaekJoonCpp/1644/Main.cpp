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

	int targetNumber;
	cin >> targetNumber;

	vector<bool> primeNumber(targetNumber + 2, true);
	primeNumber[0] = false;
	primeNumber[1] = false;
	for (int index = 2; index <= targetNumber; index++) {
		if (primeNumber[index] == false) {
			continue;
		}
		for (int i = index * 2; i <= targetNumber; i += index) {
			primeNumber[i] = false;
		}
	}

	int result = 0, sum = 0, front = 0, end = 0;
	while (end <= targetNumber && front <= targetNumber)
	{
		if (sum == targetNumber) {
			result++;
			while (!primeNumber[++front]) {}
			sum -= front;
		}
		else if (sum < targetNumber) {
			if (end == primeNumber.size()) {
				break;
			}
			while (!primeNumber[++end]) {}
			sum += end;
		}
		else if (sum > targetNumber) {
			while (!primeNumber[++front]) {}
			sum -= front;
		}
	}

	cout << result;

	return 0;
}