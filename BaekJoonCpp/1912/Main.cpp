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

	int size, max, current, input;
	cin >> size;

	cin >> max;
	current = max;
	for (int index = 1; index < size; index++) {
		if (current < 0) {
			current = 0;
		}
		cin >> input;
		current += input;
		if (current > max) {
			max = current;
		}
	}

	cout << max;
	return 0;
}