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
		int first, second;
		cin >> first >> second;
		if (first < second) {
			cout << "NO BRAINS" << endl;
		}
		else
		{
			cout << "MMM BRAINS" << endl;
		}
	}
	return 0;
}