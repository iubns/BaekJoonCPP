#include <iostream>

using namespace std;

void init() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);
}

int main()
{
	init();

	std::string input;
	cin >> input;

	int currentCount = 0;
	int sum = 0;
	for (auto iter = input.begin(); iter != input.end(); iter++) {
		if (*iter == '(') {
			if (*(iter + 1) == '(') {
				currentCount++;
			}
			else {
				iter++;
				sum += currentCount;
			}
		}
		else  if (*iter == ')') {
			sum++;
			currentCount--;
		}
	}

	cout << sum << std::endl;
	return 0;
}