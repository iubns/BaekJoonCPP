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
	int data[1001];

	int size;
	cin >> size;

	data[1] = 1;
	data[2] = 3;
	for (int index = 3; index <= size; index++) {
		data[index] = data[index - 1] + data[index - 2] * 2;
		if (data[index] > 10007) {
			data[index] %= 10007;
		}
	}

	cout << data[size];
	return 0;
}