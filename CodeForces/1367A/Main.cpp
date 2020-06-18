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

	int count;
	cin >> count;

	for (int index = 0; index < count; index++) {
		string input;
		cin >> input;
		for (int charIndex = 0; charIndex < input.size(); charIndex += 2) {
			cout << input[charIndex];
		}
		cout << input[input.size() - 1] << endl;
	}
	return 0;
}