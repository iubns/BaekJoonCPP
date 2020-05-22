#include <iostream>
#include <vector>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}


int maxNumber = 2000001;
vector<bool> primeNumber(maxNumber + 1, true);
vector<int> primeNumbers;

void checkPrime(long long target) {
	for (auto iter = primeNumbers.begin(); iter != primeNumbers.end(); iter++) {
		if (target % *iter == 0) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
}

int main()
{
	init();


	primeNumber[0] = false;
	primeNumber[1] = false;
	for (int index = 2; index <= maxNumber; index++) {
		if (primeNumber[index] == false) {
			continue;
		}
		primeNumbers.push_back(index);
		for (int i = index * 2; i <= maxNumber; i += index) {
			primeNumber[i] = false;
		}
	}


	int inputCount;
	cin >> inputCount;
	for (int index = 0; index < inputCount; index++) {
		long long first, second;
		cin >> first >> second;
		long long target = first + second;
		if (target <= 3) {
			cout << "NO\n";
			continue;
		}
		else if (target % 2 == 0) {
			cout << "YES\n";
			continue;
		}

		target -= 2;
		if (target < maxNumber) {
			if (primeNumber[target]) {
				cout << "YES\n";
				continue;
			}
			else {
				cout << "NO\n";
				continue;
			}
		}
		checkPrime(target);
	}

	return 0;
}