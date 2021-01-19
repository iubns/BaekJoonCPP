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

	int values[42] = { 1,0 };

	for (int index = 2; index < (sizeof values) / (sizeof values[0]); index++) {
		values[index] = values[index - 1] + values[index - 2];
	}

	int count, input;
	cin >> count;
	for (int index = 0; index < count; index++) {
		cin >> input;
		cout << values[input] << ' ' << values[input + 1] << endl;
	}
	return 0;
}