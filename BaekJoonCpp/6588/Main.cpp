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

	int maxNumber = 1000000;

	vector<bool> primeNumber(maxNumber + 1, true);
	primeNumber[0] = false;
	primeNumber[1] = false;
	for (int index = 2; index <= maxNumber; index++) {
		if (primeNumber[index] == false) {
			continue;
		}
		for (int i = index * 2; i <= maxNumber; i += index) {
			primeNumber[i] = false;
		}
	}

	while (true)
	{
		int target;
		cin >> target;
		if (target == 0) {
			return 0;
		}

		for (int index = target; index > 0; index--) {
			if (primeNumber[index] && primeNumber[target - index]) {
				cout << target << " = " << target - index << " + " << index << '\n';
				break;
			}
		}
	}
	return 0;
}