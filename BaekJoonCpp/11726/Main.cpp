#include <iostream>
#include <queue>
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
	int data[1001];

	int size;
	cin >> size;

	if (size == 1) {
		cout << 1;
		return 0;
	}
	else if (size == 2) {
		cout << 2;
		return 0;
	}

	data[1] = 1;
	data[2] = 2;
	for (int index = 3; index <= size; index++) {
		data[index] = data[index - 1] + data[index - 2];
		if (data[index] > 10007) {
			data[index] -= 10007;
		}
	}

	cout << data[size];


	return 0;
}